// Copyright DEWETRON GmbH 2019

#include "sp_serial_port_enum.h"
#include <filesystem>

namespace fs = std::filesystem;

namespace sp
{
    SerialPortEnum::SerialPortNames SerialPortEnum::GetPortNames()
    {
        SerialPortNames ser_port_names;

        std::vector<std::string> ser_prefixes;
#ifdef __APPLE__
        ser_prefixes.push_back("/dev/tty.usbserial");
        //ser_prefixes.push_back("/dev/tty.usbserial");
#else
        ser_prefixes.push_back("/dev/ttyUSB");
        ser_prefixes.push_back("/dev/ttyS");
#endif

        if (fs::is_directory("/dev"))
        {
            for (fs::directory_iterator dir_iter("/dev"); dir_iter != fs::directory_iterator(); ++dir_iter)
            {
                for (std::vector<std::string>::const_iterator prefix = ser_prefixes.begin();
                     prefix != ser_prefixes.end(); ++prefix)
                {
                //     if (boost::algorithm::starts_with(dir_iter->path().string(), *prefix))
                //     {
                //         ser_port_names.push_back(dir_iter->path().string());
                //     }
                        if (dir_iter->path().string().find(*prefix) == 0)
                        {
                                ser_port_names.push_back(dir_iter->path().string());
                        }
                }
            }
        }

        return ser_port_names;
    }
} // end namespace sp
