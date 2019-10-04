// Copyright (c) Dewetron 2019
#include "dw_modules_load.h"
#include "dw_modules_c_command.h"
#include "dw_modules_c_error.h"
#include "dw_modules_c_custom_serial_port.h"
#include <assert.h>
#include <stdio.h>


// create IfSerialPort compatible type MySerialPort and MySerialPortVtable
DW_CUSTOM_SERIAL_PORT(MySerialPort)


// These ustom serial port functions
// have to be implemented
const char* SP_IMPORT SIM_SP_getPortName(struct _MySerialPort*);
BOOL SP_IMPORT SIM_SP_open(struct _MySerialPort*);
BOOL SP_IMPORT SIM_SP_isOpen(struct _MySerialPort*);
BOOL SP_IMPORT SIM_SP_close(struct _MySerialPort*);
int SP_IMPORT SIM_SP_numBytesAvailable(struct _MySerialPort*);
BOOL SP_IMPORT SIM_SP_read(struct _MySerialPort*, BYTE* buf, size_t buf_size, unsigned int timeout, ReadResult* read_result);
BOOL SP_IMPORT SIM_SP_write(struct _MySerialPort*, BYTE* buf, size_t buf_size, unsigned int addr, unsigned int command_id);
unsigned int SP_IMPORT SIM_SP_getBaudRate(struct _MySerialPort*);



// default handle to access api instead of modules
ModuleHandle API_HANDLE = (ModuleHandle)-1;

int checkError(int error);



int main(int argc, char* argv[])
{
    int error = 0;
    int revision = 0;
    int addr = 0;
    int num_modules = 0;

    // Initialize vtable
    MySerialPortVtable my_serial_port_vt = {
        &SIM_SP_getPortName,
        &SIM_SP_open,
        &SIM_SP_isOpen,
        &SIM_SP_close,
        &SIM_SP_numBytesAvailable,
        &SIM_SP_read,
        &SIM_SP_write,
        &SIM_SP_getBaudRate
    };

    // Instantiate MySerialPort
    MySerialPort  my_serial_port = { &my_serial_port_vt };


    // Load the modules api dll
    revision = DeWeModulesLoad();

    // The api has to be initalized
    error = DeWeInit();
    checkError(error);

    // Register custom serial port
    error = DeWeSetParam_Ptr(API_HANDLE, DWCMD_ADD_SERIALPORT, &my_serial_port, sizeof(&my_serial_port));
    checkError(error);

    // Open custom serial port
    DeWeSetParamStr(API_HANDLE, "", "OPEN_PORT", "SIM_SP1");

    // Scan the custom registered port
    DeWeScanAddress(API_HANDLE, "SIM_SP1", addr, &num_modules);

    // Close custom erial port
    DeWeSetParamStr(API_HANDLE, "", "CLOSE_PORT", "SIM_SP1");

    // Cleanup api initialization
    error = DeWeDeInit();
    checkError(error);

    // Unload api dll
    DeWeModulesUnload();

    return error;
}

int checkError(int error)
{
    if (error != DW_SUCCESS)
    {
        printf("Error %s\n", DwErrorStr(error));
    }
    return error;
}


const char* SP_IMPORT SIM_SP_getPortName(struct _MySerialPort* self)
{
    return "SIM_SP1";
}

BOOL SP_IMPORT SIM_SP_open(struct _MySerialPort* self)
{
    return TRUE;
}

BOOL SP_IMPORT SIM_SP_isOpen(struct _MySerialPort* self)
{
    return TRUE;
}

BOOL SP_IMPORT SIM_SP_close(struct _MySerialPort* self)
{
    return TRUE;
}

int SP_IMPORT SIM_SP_numBytesAvailable(struct _MySerialPort* self)
{
    return 0;
}

static ReadResult read_result;


BOOL SP_IMPORT SIM_SP_read(struct _MySerialPort* self, BYTE* buf, size_t buf_size, unsigned int timeout, ReadResult* read_result)
{
    read_result->m_type = LOWLEVEL_ERROR;
    read_result->m_what.num_bytes = 0;
    return FALSE;
}

BOOL SP_IMPORT SIM_SP_write(struct _MySerialPort* self, BYTE* buf, size_t buf_size, unsigned int addr, unsigned int command_id)
{
    return TRUE;
}

unsigned int SP_IMPORT SIM_SP_getBaudRate(struct _MySerialPort* self)
{
    return 9600;
}
