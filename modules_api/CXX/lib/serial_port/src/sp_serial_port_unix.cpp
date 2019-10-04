#include "sp_serial_port_unix.h"

#include <iostream>
#include <sstream>
#include <termios.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>

#ifndef OSX
#include <linux/serial.h>
#endif


static bool print_error(const std::string& msg)
{
    std::cerr << msg << std::endl;
    return false;
}

static bool print_errno(const std::string& msg)
{
    ::perror(msg.c_str());
    return false;
}


namespace sp
{
    SerialPortUnix::SerialPortUnix(const std::string& path, const SerialPortConfig& config)
    : m_path(path),
      m_config(config),
      m_fd(-1) {}

    BOOL SerialPortUnix::open()
    {
        std::string errmsg(m_path + ": ");

        m_fd = ::open(m_path.c_str(), O_RDWR|O_NOCTTY|O_NONBLOCK);
        if (m_fd == -1)
            return print_errno(errmsg + "cannot open");

        // read current settings
        termios t;
        if (::tcgetattr(m_fd, &t) < 0)
            return print_errno(errmsg + "cannot get settings");

        // apply parameters on top of these
        {
            {
                int speed;
                switch (m_config.getBaudrate()) {
                    case 9600:
                        speed = B9600;
                        break;
                    case 19200:
                        speed = B19200;
                        break;
                    case 38400:
                        speed = B38400;
                        break;
                    case 57600:
                        speed = B57600;
                        break;
                    case 115200:
                        speed = B115200;
                        break;
                    default:
                        std::ostringstream os;
                        os << errmsg << "baud rate " << m_config.getBaudrate() << " not supported";
                        return print_error(os.str());
                }
                // man termios: cfsetspeed() sets both, but is a
                // 4.4BSD extension
                if (::cfsetspeed(&t, speed) == -1)
                    return print_errno(errmsg + "cannot set speed");
            }

            {
                switch (m_config.getParity()) {
                    case Parity::NONE:
                        t.c_cflag &= ~PARENB;
                        break;
                    case Parity::ODD:
                        t.c_cflag |= PARENB;
                        t.c_cflag |= PARODD;
                        break;
                    case Parity::EVEN:
                        t.c_cflag |= PARENB;
                        t.c_cflag &= ~PARODD;
                        break;
                }
            }

            {
                switch (m_config.getCSize()) {
                    case 8:
                        t.c_cflag &= ~CSIZE;
                        t.c_cflag |= CS8;
                        break;
                    default:
                        std::ostringstream os;
                        os << errmsg << "character size " << m_config.getCSize() << " not supported";
                        return print_error(os.str());
                }
            }

            {
                switch (m_config.getFlow()) {
                    case FlowControl::NONE:
                        // don't know how to set flow control, being
                        // too lazy to dig through man termios. trust
                        // that it is not currently set on the line.
                        break;
                    default:
                        return print_error(errmsg + "flow control not supported");
                }
            }

            {
                switch (m_config.getStopBits()) {
                    case StopBits::ONE:
                        t.c_cflag &= ~CSTOPB;
                        break;
                    case StopBits::TWO:
                        t.c_cflag |= CSTOPB;
                        break;
                    default:
                        return print_error(errmsg + "stop bits other than 1 not supported");
                }
            }
        }

        if (::tcsetattr(m_fd, TCSADRAIN, &t) == -1)
            return print_errno(errmsg + "apply settings");

        // set the line to "low latency" so the kernel does not hold
        // back bytes in its buffer for some time.
#ifndef OSX
        {
            serial_struct serinfo;
            if (::ioctl(m_fd, TIOCGSERIAL, &serinfo) == -1 && errno != ENOTTY)
                return print_errno(errmsg + "TIOCGSERIAL (low-latency)");
            serinfo.flags |= ASYNC_LOW_LATENCY;
            if (::ioctl(m_fd, TIOCSSERIAL, &serinfo) == -1 && errno != ENOTTY)
                return print_errno(errmsg + "TIOCSSERIAL (low-latency)");
        }
#endif // OSX

        return true;
    }

    BOOL SerialPortUnix::close()
    {
        if (m_fd >= 0)
        {
            int ret = ::close(m_fd);
            return ret == 0;
        }

        return false;
    }

    int SerialPortUnix::numBytesAvailable() const
    {
        assert(m_fd >= 0);

        int num_bytes;
        int error = ::ioctl(m_fd, FIONREAD, &num_bytes);
        if (error) {
            print_errno("ioctl(FIONREAD)");
            return -1;
        }
        return num_bytes;
    }

    BOOL SerialPortUnix::read(BYTE* buf, size_t buf_size, unsigned int timeout_milli, ReadResult* read_result)
    {
        assert(m_fd >= 0);
        assert(read_result != nullptr);

        timeval to;
        to.tv_sec = timeout_milli / 1000;
        to.tv_usec = (timeout_milli % 1000) * 1000;

        fd_set in;
        FD_ZERO(&in);
        FD_SET(m_fd, &in);
        int rv = ::select(m_fd+1, &in, NULL, NULL, &to);
        if (rv == -1) {
            print_errno(m_path+": select");
            *read_result = ReadResult(ReadResult::LowLevel);
            return false;
        }
        if (rv == 0) {
            *read_result = ReadResult(ReadResult::Timeout);
            return false;
        }

        ssize_t nread = ::read(m_fd, buf, buf_size);
        if (nread == -1) {
            print_errno(m_path+": read");
            *read_result = ReadResult(ReadResult::LowLevel);
            return false;
        }
        if (nread == 0) {
            print_error(m_path+": what? read returns 0 on a serial line?");
            *read_result = ReadResult(ReadResult::LowLevel);
            return false;
        }

        *read_result = ReadResult(nread);
        return true;
    }

    BOOL SerialPortUnix::write(BYTE* buf, size_t buf_size, unsigned int addr, unsigned int command_id)
    {
        assert(buf_size>0);

        while (buf_size) {
            ssize_t nwritten = ::write(m_fd, buf, buf_size);
            if (nwritten == -1) {
                print_errno(m_path+": write");
                return false;
            }
            if (nwritten == 0) {
                // should turn this into an assertion; this is not how
                // write works.
                print_errno(m_path+": what? write returns 0?");
                return false;
            }
            buf_size -= nwritten;
            buf += nwritten;
        }
        return true;
    }

    unsigned int SerialPortUnix::getBaudRate() const
    {
        assert(m_fd>=0);

        termios t;
        if (::tcgetattr(m_fd, &t) < 0) {
            print_errno(m_path+": GetBaudRate: tcgetattr");
            // our unsigned int return type permits no proper error handling
            assert(false);
            return ~0;
        }

        speed_t speed = ::cfgetospeed(&t);
        switch (speed) {
            case B9600:
                return 9600;
            case B19200:
                return 19200;
            case B38400:
                return 38400;
            case B57600:
                return 57600;
            case B115200:
                return 115200;
            default:
                std::ostringstream os;
                os << m_path << ": termios speed " << speed << " not supported";
                print_error(os.str());
                // return value type does not permit proper handling
                // of this
                assert(false);
                return 0;
        }

        assert(false);
        return 0;
    }

}
