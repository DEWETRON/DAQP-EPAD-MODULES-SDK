#include "sp_serial_port_windows.h"

#include "sp_log.h"

#include "uni_assert.h"
#include "uni_system.h"

#include <windows.h>


namespace
{
    /** Litte helper used during port open. ensures proper cleanup
        when things go wrong. */
    class TransactHandles : public boost::noncopyable
    {
    public:
        TransactHandles()
            : m_port(INVALID_HANDLE_VALUE),
            m_event(INVALID_HANDLE_VALUE) {}

        ~TransactHandles()
        {
            if (m_port != INVALID_HANDLE_VALUE) {
                ::CloseHandle(m_port);
            }
            if (m_event != INVALID_HANDLE_VALUE) {
                ::CloseHandle(m_event);
            }
        }

        void setPort(HANDLE h)
        {
            UNI_ASSERT(m_port == INVALID_HANDLE_VALUE);
            m_port = h;
        }

        void setEvent(HANDLE h)
        {
            UNI_ASSERT(m_event == INVALID_HANDLE_VALUE);
            m_event = h;
        }

        HANDLE getPort() const
        {
            return m_port;
        }

        HANDLE getEvent() const
        {
            return m_event;
        }

        void reap(HANDLE& port, HANDLE& event)
        {
            port = m_port;
            m_port = INVALID_HANDLE_VALUE;
            event = m_event;
            m_event = INVALID_HANDLE_VALUE;
        }

    private:
        HANDLE m_port;
        HANDLE m_event;
    };
}


namespace sp
{
    static const uint32 NUM_OF_RECURSIVE_READ_RETRIES = 3;

    SerialPortWindows::SerialPortWindows(
        const std::string& name,
        const SerialPortConfig& config)
        : m_name(name),
        m_config(config),
        m_port(INVALID_HANDLE_VALUE),
        m_event(INVALID_HANDLE_VALUE)
    {}

    SerialPortWindows::~SerialPortWindows()
    {
        if (isOpen())
            close();
    }

    bool SerialPortWindows::open()
    {
        UNI_ASSERT(!isOpen());

        TransactHandles handles;

        handles.setEvent(::CreateEvent(
            NULL/*security*/,
            /*manual-reset=*/TRUE,
            /*initial-state=*/FALSE,
            NULL/*nameless*/));
        if (handles.getEvent() == INVALID_HANDLE_VALUE) {
            printLastError_("cannot create event");
            return false;
        }

        //ports other than COM1-COM9 can only be opened using a special syntax
        std::string full_name("\\\\.\\");
        full_name += m_name;

        handles.setPort(::CreateFile(
            full_name.c_str(),
            GENERIC_READ | GENERIC_WRITE,
            0, // exclusive
            NULL, // security? windows? wtf!
            OPEN_EXISTING, // file must exist
            FILE_FLAG_OVERLAPPED,
            NULL // wtf is a template?
            ));
        if (handles.getPort() == INVALID_HANDLE_VALUE) {
            printLastError_("cannot open");
            return false;
        }

        COMMTIMEOUTS cto;
        if (!::GetCommTimeouts(handles.getPort(), &cto)) {
            printLastError_("GetCommTimeouts() failed");
            return false;
        }

        // gosh. https://msdn.microsoft.com/en-us/library/ff802693.aspx
        // is not helpful at all. I had to look into
        // boost/asio/detail/impl/win_iocp_serial_port_service.ipp for
        // this.

        // Set up timeouts so that the serial port will behave
        // similarly to a network socket. Reads wait for at least one
        // byte, then return with whatever they have. Writes return
        // once everything is out the door.
        cto.ReadIntervalTimeout = 1;
        cto.ReadTotalTimeoutMultiplier = 0;
        cto.ReadTotalTimeoutConstant = 0;
        cto.WriteTotalTimeoutMultiplier = 0;
        cto.WriteTotalTimeoutConstant = 0;

        if (!::SetCommTimeouts(handles.getPort(), &cto)) {
            printLastError_("SetCommTimeouts() failed");
            return false;
        }

        // read current settings
        DCB dcb = { 0 };
        dcb.DCBlength = sizeof(DCB);
        if (!::GetCommState(handles.getPort(), &dcb)) {
            printLastError_("cannot get comm state");
            return false;
        }

        // apply parameters on top of these
        {
            switch (m_config.getBaudrate()) {
            case 110:
                dcb.BaudRate = CBR_110;
                break;
            case 300:
                dcb.BaudRate = CBR_300;
                break;
            case 600:
                dcb.BaudRate = CBR_600;
                break;
            case 1200:
                dcb.BaudRate = CBR_1200;
                break;
            case 2400:
                dcb.BaudRate = CBR_2400;
                break;
            case 4800:
                dcb.BaudRate = CBR_4800;
                break;
            case 9600:
                dcb.BaudRate = CBR_9600;
                break;
            case 14400:
                dcb.BaudRate = CBR_14400;
                break;
            case 19200:
                dcb.BaudRate = CBR_19200;
                break;
            case 38400:
                dcb.BaudRate = CBR_38400;
                break;
            case 56000:
                dcb.BaudRate = CBR_56000;
                break;
            case 57600:
                dcb.BaudRate = CBR_57600;
                break;
            case 115200:
                dcb.BaudRate = CBR_115200;
                break;
            case 128000:
                dcb.BaudRate = CBR_128000;
                break;
            case 256000:
                dcb.BaudRate = CBR_256000;
                break;
            default:
                std::ostringstream os;
                os << "baud rate " << m_config.getBaudrate() << " not supported";
                printError_(os.str());
                return false;
            }

            switch (m_config.getParity()) {
            case Parity::NONE:
                dcb.Parity = NOPARITY;
                break;
            case Parity::ODD:
                dcb.Parity = ODDPARITY;
                break;
            case Parity::EVEN:
                dcb.Parity = EVENPARITY;
                break;
            }

            switch (m_config.getCSize()) {
            case 8:
                dcb.ByteSize = 8;
                break;
            default:
                std::ostringstream os;
                os << "character size " << m_config.getCSize() << " not supported";
                printError_(os.str());
                return false;
            }

            switch (m_config.getFlow()) {
            case FlowControl::NONE:
                dcb.fOutxCtsFlow = FALSE;
                dcb.fOutxDsrFlow = FALSE;
                dcb.fDtrControl = DTR_CONTROL_DISABLE;
                dcb.fRtsControl = RTS_CONTROL_DISABLE;
                dcb.fOutX = FALSE;
                dcb.fInX = FALSE;
                break;
            default:
                printError_("flow control not supported");
                return false;
            }

            switch (m_config.getStopBits()) {
            case StopBits::ONE:
                dcb.StopBits = ONESTOPBIT;
                break;
            case StopBits::ONEP_POINT_FIVE:
                dcb.StopBits = ONE5STOPBITS;
                break;
            case StopBits::TWO:
                dcb.StopBits = ONE5STOPBITS;
                break;
            }
        }

        if (!::SetCommState(handles.getPort(), &dcb)) {
            printLastError_("cannot set comm state");
            return false;
        }

        handles.reap(m_port, m_event);
        return true;
    }

    bool SerialPortWindows::isOpen() const
    {
        if (m_port == INVALID_HANDLE_VALUE) {
            UNI_ASSERT(m_event == INVALID_HANDLE_VALUE);
            return false;
        }
        else {
            UNI_ASSERT(m_event != INVALID_HANDLE_VALUE);
            return true;
        }
    }

    bool SerialPortWindows::close()
    {
        if (isOpen()) {
            ::CloseHandle(m_port);
            ::CloseHandle(m_event);
            m_port = INVALID_HANDLE_VALUE;
            m_event = INVALID_HANDLE_VALUE;
        }
        return true;
    }

    sint32 SerialPortWindows::numBytesAvailable() const
    {
        UNI_ASSERT(isOpen());

        COMSTAT status;
        if (!::ClearCommError(m_port, NULL, &status)) {
            printLastError_("ClearCommError() failed");
            return -1;
        }
        return status.cbInQue;
    }

    ReadResult SerialPortWindows::read(
        BYTE* buf,
        std::size_t buf_size,
        uint32 timeout_milli)
    {

        return read(buf, buf_size, timeout_milli, NUM_OF_RECURSIVE_READ_RETRIES);
    }

    ReadResult SerialPortWindows::read(BYTE* buf, std::size_t buf_size, uint32 timeout_milli, uint32 recursive_calls /*= false*/)
    {
        UNI_ASSERT(isOpen());

        BOOL ok;
        OVERLAPPED overlapped = { 0 };
        overlapped.hEvent = m_event;
        bool timeout_occured = false;

        ::ResetEvent(m_event);

        // https://msdn.microsoft.com/en-us/library/windows/desktop/aa365467%28v=vs.85%29.aspx
        // sucks completely in suggesting that one should not pass
        // lpNumberOfBytesRead. omg they suck.

        // https://support.microsoft.com/en-us/kb/156932 on the other
        // hand says (I believe) that the operation, though started
        // with an OVERLAPPED structure, MAY complete synchronously as
        // well. so, it does make sense to pass lpNumberOfBytesRead.

        DWORD num_read = ~0; // ensure that errors happen when it
        // remains uninitialized by crap
        ok = ::ReadFile(m_port, buf, (DWORD)buf_size, &num_read, &overlapped);

        if (ok) {
            return ReadResult(num_read);
        }

        if (::GetLastError() != ERROR_IO_PENDING) {
            printLastError_("read failed");
            return ReadResult(ReadResult::LowLevel);
        }

        // read is pending; wait for completion, applying the timeout
        DWORD wait_result = ::WaitForSingleObject(m_event, (DWORD)timeout_milli);

        switch (wait_result) {
        case WAIT_TIMEOUT:
            /*
            If the function succeeds, the return value is nonzero.The cancel operation for all
            pending I / O operations issued by the calling process for the specified file handle
            was successfully requested.The application must not free or reuse the OVERLAPPED
            structure associated with the canceled I / O operations until they have completed.
            The thread can /use the GetOverlappedResult function to determine when the I / O
            operations themselves have been completed.
            */
            if (::CancelIoEx(m_port, &overlapped))
            {
                timeout_occured = true;
                break;
            }
            else
            {
                /*
                ERROR_NOT_FOUND would tell us, that the operation
                actually managed to complete, before we were able
                to issue the cancel-request
                */
                if (::GetLastError() != ERROR_NOT_FOUND)
                {
                    printLastError_("CancelIoEx failed");
                    return ReadResult(ReadResult::LowLevel);
                }
                break;
            }
        case WAIT_FAILED:
            ::CancelIo(m_port);
            printLastError_("wait failed");
            return ReadResult(ReadResult::LowLevel);
        case WAIT_OBJECT_0:
            break;
        }

        DWORD nread = 0;
        ok = GetOverlappedResult(m_port, &overlapped, &nread,
            (timeout_occured ? TRUE : FALSE) /*no wait - we already now
                                                that we completed, except on cancel */
                                                );
        if (!ok) {

            if (::GetLastError() == ERROR_OPERATION_ABORTED) {
                return ReadResult(ReadResult::Timeout);
            }
            printLastError_("GetOverlappedResult() failed");
            return ReadResult(ReadResult::LowLevel);
        }
        if (nread == 0)
        {

            printLastError_("SerialPortWindows::read failed (nread = 0)");
            if ((--recursive_calls))
            {
                uni::System::Sleep(10);
                return read(buf, buf_size, timeout_milli, recursive_calls);
            }
            else if (timeout_occured)
            {
                return ReadResult(ReadResult::Timeout);
            }
            else
            {
                return ReadResult(ReadResult::LowLevel);
            }
        }
        return ReadResult(nread);
    }

    bool SerialPortWindows::write(
    BYTE* buf,
    std::size_t buf_size,
    uint32 addr,
    uint32 command_id)
    {
        UNI_ASSERT(isOpen());
        UNI_ASSERT(buf_size > 0);

        OVERLAPPED overlapped = { 0 };
        overlapped.hEvent = m_event;

        while (buf_size) {
            DWORD nwritten;
            ::ResetEvent(m_event);

            if (!::WriteFile(m_port, buf, (DWORD)buf_size, &nwritten, &overlapped))
            {
                if (::GetLastError() == ERROR_IO_PENDING)
                {
                    DWORD wait_result = ::WaitForSingleObject(m_event, 250); // ISSUE 0004061

                    switch (wait_result)
                    {
                    case WAIT_OBJECT_0:
                        if (!::GetOverlappedResult(m_port, &overlapped, &nwritten,
                                                   FALSE /*no wait - we already now that we completed */))
                        {
                            printLastError_("GetOverlappedResult() failed");
                            return false;
                        }
                        break;
                    case WAIT_TIMEOUT:
                        SPSER_ERROR(m_name << ": WaitForSingleObject() timeout");
                        return false;
                    case WAIT_ABANDONED_0:
                        SPSER_ERROR(m_name << ": WaitForSingleObject() handle abandoned");
                        return false;
                    case WAIT_FAILED:
                        SPSER_ERROR(m_name << ": WaitForSingleObject() failed");
                        return false;
                    }
                }
                else
                {
                    printLastError_("write failed");
                    return false;
                }
            }

            buf_size -= nwritten;
            buf += nwritten;
        }

        return true;
    }

    uint32 SerialPortWindows::getBaudRate() const
    {
        return m_config.getBaudrate();
    }

    //ScopedTransaction SerialPortWindows::getScopedTransaction()
    //{
    //    return sp::ScopedTransaction(m_mutex);
    //}

    void SerialPortWindows::printError_(
        const std::string& msg)
        const
    {
        SPSER_ERROR(m_name << ": " << msg);
    }

    void SerialPortWindows::printLastError_(
        const std::string& msg)
        const
    {
        char buffer[128];

        DWORD error = GetLastError();
        FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
            NULL, /* lpSource */
            error, /* dwMessageId */
            0, /* dwLanguageId */
            buffer,
            sizeof(buffer),
            NULL /* WTF? */);

        SPSER_ERROR(m_name << ": " << msg << ": " << buffer);
    }

}