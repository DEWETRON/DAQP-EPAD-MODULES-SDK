// Copyright DEWETRON GmbH 2015

#include "sp_serial_port_util.h"
#include <algorithm>


//using namespace boost;
namespace sp
{
    SerialPortUtil::SerialPortUtil()
    {
        /* default */
#ifdef _WIN32
        m_prefix = "COM";
#elif __linux__
        m_prefix = "/dev/ttyUSB";
#else
        m_prefix = "NONE";
#endif /*_WIN32*/
    }
    SerialPortUtil::SerialPortUtil(const std::string& prefix)
    {
        m_prefix = prefix;
    }

    void SerialPortUtil::setPrefix(const std::string& prefix)
    {
        m_prefix = prefix;
    }
    const std::string& SerialPortUtil::getPrefix()
    {
        return m_prefix;
    }

    SerialPortEnum::SerialPortNames SerialPortUtil::getPortNamesSorted(const std::string& prefix)
    {
        SerialPortEnum::SerialPortNames names = SerialPortEnum::GetPortNames();
        this->sort(names);
        return names;
    }

    SerialPortEnum::SerialPortNames SerialPortUtil::getPortNamesSorted()
    {
        return getPortNamesSorted(m_prefix);
    }

    void SerialPortUtil::sort(std::vector<std::string>& vec)
    {
        if (!m_prefix.empty())
        {
            std::sort(vec.begin(), vec.end(), [this](const std::string& str1, const std::string& str2) {
                return com_sort(str1, str2);
            });
        }
        else
        {
            std::sort(vec.begin(), vec.end());
        }
    }

    bool SerialPortUtil::com_sort(const std::string& str1, const std::string& str2)
    {
        std::string temp1, temp2;
        int port1 = 0, port2 = 0;
        auto pos = str1.find(m_prefix);

        if (pos != std::string::npos)
        {
            pos += m_prefix.size();
            auto num = str1.substr(pos);
            port1 = std::stoi(num);
        }
        else
        {
            temp1 = str1;
        }

        pos = str2.find(m_prefix);
        if (pos != std::string::npos)
        {
            pos += m_prefix.size();
            auto num = str2.substr(pos);
            port2 = std::stoi(num);
        }
        else
        {
            temp2 = str2;
        }


        if (temp1.empty() && temp2.empty())
        {
            return port1 < port2;
        }
        else
        {
            return str1.compare(str2) < 0;
        }

        return true;
    }
} // end namespace sp
