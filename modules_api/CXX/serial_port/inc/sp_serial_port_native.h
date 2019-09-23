#pragma once

#if defined UNIX
#  include "sp_serial_port_unix.h"
namespace sp
{
    typedef SerialPortUnix SerialPortNative;
}
#elif defined WIN32
#  include "sp_serial_port_windows.h"
namespace sp
{
    typedef SerialPortWindows SerialPortNative;
}
#else
#  error dont know what OS this could be
#endif
