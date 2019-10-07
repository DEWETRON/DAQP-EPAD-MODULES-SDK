// Copyright (c) Dewetron 2019

#include "sp_if_serial_port.h"
#include "OrionDaq_api.h"
#include <assert.h>
#include <inttypes.h>
#include <Windows.h>


#define DEFAULT_BAUD_RATE   9600
#define READY_DATA_TIMEOUT  50


namespace uni
{
    class Timer 
    {
    public:
        Timer()
        {
            m_freq = getFreq();
        }

        uint64_t getTime()
        {
            LARGE_INTEGER time;
            QueryPerformanceCounter(&time);
            return time.QuadPart;
        }

        uint64_t getTimeUS()
        {
            auto t = getTime();
            return static_cast<uint64_t>(t / (m_freq / 1000000.0));
        }

        uint64_t getFreq()
        {
            LARGE_INTEGER time;
            QueryPerformanceFrequency(&time);
            return time.QuadPart;
        }
    private:
        uint64_t m_freq;
    };
}


/**
 * Serial Port interface implementation for the onboard RS485 bus on
 * Orion boards.
 */
class OrionDAQSerialPort : public sp::IfSerialPort
{
    OrionDAQSerialPort() = delete;
    OrionDAQSerialPort(const OrionDAQSerialPort&) = delete;
public:
    OrionDAQSerialPort(unsigned int board_id, const std::string& port_name)
        : m_board_id(board_id)
        , m_port_name(port_name)
        , m_is_open(FALSE)
    {
    }

    virtual ~OrionDAQSerialPort()
    {
        close();
    }

    virtual const char* SP_IMPORT getPortName() const override
    {
        return m_port_name.c_str();
    }

    virtual BOOL SP_IMPORT open() override
    {
        if (!m_is_open)
        {
            if (RtOpenRS485(m_board_id) != 0)
            {
                m_is_open = TRUE;
            }
        }
        return m_is_open;
    }

    virtual BOOL SP_IMPORT isOpen() const override
    {
        return m_is_open;
    }

    virtual BOOL SP_IMPORT close() override
    {
        if (m_is_open)
        {
            m_is_open = FALSE;
            if (RtCloseRS485(m_board_id) != 0)
            {
                return TRUE;
            }
        }
        return FALSE;
    }

    virtual int SP_IMPORT numBytesAvailable() const override
    {
        assert(isOpen());
        int bytes_available = 0;
        if (RtReadyDataRS485(m_board_id, READY_DATA_TIMEOUT, &bytes_available))
        {
            return bytes_available;
        }
        return 0;
    }

    virtual BOOL SP_IMPORT read(BYTE* buf, std::size_t buf_size, unsigned int timeout, sp::ReadResult* read_result) override
    {
        assert(isOpen());
        int read_len = 0;
        int bytes_available = 0;
        uni::Timer timer;

        auto start_time_us = timer.getTimeUS();

        // bytes available?
        RtReadyDataRS485(m_board_id, timeout / 3, &bytes_available);

        // defensive: try again with larger timeout
        if (bytes_available <= 0)
        {
            auto time_us = timer.getTimeUS();
            auto delta_ms = (time_us - start_time_us) / 1000;
            if (delta_ms < timeout)
            {
                unsigned int wait_ms = static_cast<unsigned int>(timeout - delta_ms);
                RtReadyDataRS485(m_board_id, wait_ms, &bytes_available);
            }
        }


        if (bytes_available > 0)
        {
            LPSTR lpstr_buf = reinterpret_cast<LPSTR>(buf);
            read_len = RtReadRS485(m_board_id, lpstr_buf, static_cast<int>(buf_size));

            *read_result = sp::ReadResult(bytes_available);
            return TRUE;
        }
        else if (bytes_available < 0)
        {
            *read_result = sp::ReadResult(sp::ReadResult::LowLevel);
            return FALSE;
        }
        else
        {
            *read_result = sp::ReadResult(sp::ReadResult::Timeout);
            return FALSE;
        }

        return FALSE;

    }

    virtual BOOL SP_IMPORT write(BYTE* buf, std::size_t buf_size, unsigned int /*addr*/, unsigned int /*command_id*/) override
    {
        assert(isOpen());
        LPSTR lpstr_buf = reinterpret_cast<LPSTR>(buf);

        ::Sleep(5);

        if (!RtWriteRS485(m_board_id, lpstr_buf, static_cast<int>(buf_size)))
        {
            return FALSE;
        }
        return TRUE;
    }

    virtual unsigned int SP_IMPORT getBaudRate() const override
    {
        return DEFAULT_BAUD_RATE;
    }
private:
    unsigned int   m_board_id;
    std::string    m_port_name;
    BOOL           m_is_open;
};
