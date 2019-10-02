// Copyright DEWETRON GmbH 2014

#ifndef _SP_SERIAL_PORT_ENUM_H_
#define _SP_SERIAL_PORT_ENUM_H_

#include <string>
#include <vector>

namespace sp
{

    /**
     * Allowes to detect the systems serial ports.
     */
    class SerialPortEnum
    {
    public:
        typedef std::vector<std::string> SerialPortNames;

        /**
         * Return a list containing the names of available serial ports.
         * @return a list of available serial ports
         */
        static SerialPortNames GetPortNames();
    };
} // namespace sp


#endif // _SP_SERIAL_PORT_ENUM_H_
