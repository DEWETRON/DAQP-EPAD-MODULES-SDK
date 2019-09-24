// Copyright DEWETRON GmbH 2015

#ifndef _SP_SERIAL_PORT_UTIL_H_
#define _SP_SERIAL_PORT_UTIL_H_

#include "sp_serial_port_enum.h"
#include <string>

namespace sp
{
    /**
     * serial port utils
     */
    class SerialPortUtil
    {
    public:

        SerialPortUtil();
        SerialPortUtil(const std::string& prefix);

        /**
        * Return a sorted list containing the names of available serial ports.
        * sorting considers platform prefix
        * @return a sorted list of available serial ports
        */
        SerialPortEnum::SerialPortNames getPortNamesSorted(const std::string& prefix);

        /**
        * Return a sorted list containing the names of available serial ports.
        * sorting considers defaul platform prefix
        * @return a sorted list of available serial ports
        */
        SerialPortEnum::SerialPortNames getPortNamesSorted();

        /**
        * sort compare operator
        */
        bool com_sort(const std::string& str1, const std::string& str2);

        /**
        * prefix setter & getter
        */
        void setPrefix(const std::string& prefix);
        const std::string& getPrefix();

        void sort(std::vector<std::string>& vector);

    private:
        std::string m_prefix;
    };
} // namespace sp


#endif // _SP_SERIAL_PORT_UTIL_H_
