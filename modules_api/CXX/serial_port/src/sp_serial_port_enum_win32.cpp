// Copyright DEWETRON GmbH 2014


#include "sp_serial_port_enum.h"
#include <windows.h>
#include <winreg.h>

#define MAX_KEY_LENGTH 255
#define MAX_VALUE_NAME 16383


namespace sp
{


    SerialPortEnum::SerialPortNames SerialPortEnum::GetPortNames()
    {
        SerialPortNames ser_port_names;

        HKEY parent_key_handle;

        if (RegOpenKeyEx( HKEY_LOCAL_MACHINE,
                          TEXT("HARDWARE\\DEVICEMAP\\SERIALCOMM"),
                          0,
                          KEY_READ,
                        &parent_key_handle) == ERROR_SUCCESS)
        {
            DWORD nr_comms = 0;
            DWORD i, ret_code;
            DWORD cchValue = MAX_VALUE_NAME;

            ret_code = RegQueryInfoKey(
              parent_key_handle,
              NULL,
              NULL,
              NULL,
              NULL,
              NULL,
              NULL,
              &nr_comms,
              NULL,
              NULL,
              NULL,
              NULL);

            if (ret_code == ERROR_SUCCESS && nr_comms)
            {
                for (i=0; i<nr_comms; i++)
                {
                    DWORD child_key_length = MAX_KEY_LENGTH;
                    TCHAR child_key_name[MAX_KEY_LENGTH];
                    DWORD data_length = MAX_KEY_LENGTH;
                    TCHAR data[MAX_KEY_LENGTH];

                    ret_code = RegEnumValue(
                        parent_key_handle,
                        i,
                        child_key_name,
                        &child_key_length,
                        NULL,
                        NULL,
                        (LPBYTE)&data,
                        &data_length);

                    if(ret_code != ERROR_SUCCESS)
                        continue;
                    ser_port_names.push_back(std::string(data));
                }
            }
        }

        RegCloseKey(parent_key_handle);
        return ser_port_names;
    }

} // end namespace sp
