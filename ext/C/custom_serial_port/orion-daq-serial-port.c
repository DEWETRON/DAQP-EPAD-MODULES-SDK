// Copyright (c) Dewetron 2019

#include "OrionDaq_api.h"
#include "dw_modules_load.h"
#include "dw_modules_c_command.h"
#include "dw_modules_c_error.h"
#include "dw_modules_c_custom_serial_port.h"
#include <assert.h>
#include <inttypes.h>
#include <stdio.h>


#define DEFAULT_BAUD_RATE   9600
#define READY_DATA_TIMEOUT  50


typedef struct _OrionRS485Data
{
    unsigned int m_board_id;
    BOOL         m_is_open;
} OrionRS485Data;

// create IfSerialPort compatible type
DW_CUSTOM_SERIAL_PORT_EX(OrionDAQRS485, OrionRS485Data)


// These ustom serial port functions
// have to be implemented
const char* SP_IMPORT ORION_DAQ_RS485_getPortName(struct _OrionDAQRS485*);
BOOL SP_IMPORT ORION_DAQ_RS485_open(struct _OrionDAQRS485*);
BOOL SP_IMPORT ORION_DAQ_RS485_isOpen(struct _OrionDAQRS485*);
BOOL SP_IMPORT ORION_DAQ_RS485_close(struct _OrionDAQRS485*);
int SP_IMPORT ORION_DAQ_RS485_numBytesAvailable(struct _OrionDAQRS485*);
BOOL SP_IMPORT ORION_DAQ_RS485_read(struct _OrionDAQRS485*, BYTE* buf, size_t buf_size, unsigned int timeout, ReadResult* read_result);
BOOL SP_IMPORT ORION_DAQ_RS485_write(struct _OrionDAQRS485*, BYTE* buf, size_t buf_size, unsigned int addr, unsigned int command_id);
unsigned int SP_IMPORT ORION_DAQ_RS485_getBaudRate(struct _OrionDAQRS485*);



// default handle to access api instead of modules
ModuleHandle API_HANDLE = (ModuleHandle)-1;

int checkError(int error);
uint64_t getTime();
uint64_t getTimeUS(uint64_t freq);
uint64_t getFreq();


int main(int argc, char* argv[])
{
    int error = 0;
    int revision = 0;
    int addr = 0;
    int nr_boards = 0;
    int num_modules = 0;

    // Initialize vtable
    OrionDAQRS485Vtable my_serial_port_vt = {
        &ORION_DAQ_RS485_getPortName,
        &ORION_DAQ_RS485_open,
        &ORION_DAQ_RS485_isOpen,
        &ORION_DAQ_RS485_close,
        &ORION_DAQ_RS485_numBytesAvailable,
        &ORION_DAQ_RS485_read,
        &ORION_DAQ_RS485_write,
        &ORION_DAQ_RS485_getBaudRate
    };

    // Instantiate OrionDAQRS485
    OrionRS485Data rs485_data = { 0, FALSE };
    OrionDAQRS485  my_serial_port = { &my_serial_port_vt, rs485_data };


    // Add code to load and configure ORION DAQ board + RS485
    if (!RTdaqLoad())
    {
        printf("Error: Could not load ORION DAQ API.\n");
        return -1;
    }

    if (!RtInitialBoards())
    {
        printf("Error: Could not initialize ORION DAQ API.\n");
        return -1;
    }

    nr_boards = RtGetBoardCount();
    printf("Nr of boards: %d\n", nr_boards);

    // TODO initalize and setup boards


    // Load the modules api dll
    revision = DeWeModulesLoad();

    // The api has to be initalized
    error = DeWeInit();
    checkError(error);

    // Register custom serial port
    error = DeWeSetParam_Ptr(API_HANDLE, DWCMD_ADD_SERIALPORT, &my_serial_port, sizeof(&my_serial_port));
    checkError(error);

    // Open custom serial port
    DeWeSetParamStr(API_HANDLE, "", "OPEN_PORT", "ORION_DAQ_RS485");

    // Scan the custom registered port
    DeWeScanAddress(API_HANDLE, "ORION_DAQ_RS4851", addr, &num_modules);

    // Close custom erial port
    DeWeSetParamStr(API_HANDLE, "", "CLOSE_PORT", "ORION_DAQ_RS485");

    // Cleanup api initialization
    error = DeWeDeInit();
    checkError(error);

    // Unload api dll
    DeWeModulesUnload();

    // unload Orion API dll
    RTdaqUnload();

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


const char* SP_IMPORT ORION_DAQ_RS485_getPortName(struct _OrionDAQRS485* self)
{
    return "ORION_DAQ_RS485";
}

BOOL SP_IMPORT ORION_DAQ_RS485_open(struct _OrionDAQRS485* self)
{
    if (!self->m_data.m_is_open)
    {
        if (RtOpenRS485(self->m_data.m_board_id) != 0)
        {
            self->m_data.m_is_open = TRUE;
        }
    }
    return self->m_data.m_is_open;
}

BOOL SP_IMPORT ORION_DAQ_RS485_isOpen(struct _OrionDAQRS485* self)
{
    return self->m_data.m_is_open;
}

BOOL SP_IMPORT ORION_DAQ_RS485_close(struct _OrionDAQRS485* self)
{
    if (self->m_data.m_is_open)
    {
        self->m_data.m_is_open = FALSE;
        if (RtCloseRS485(self->m_data.m_board_id) != 0)
        {
            return TRUE;
        }
    }
    return FALSE;
}

int SP_IMPORT ORION_DAQ_RS485_numBytesAvailable(struct _OrionDAQRS485* self)
{
    assert(ORION_DAQ_RS485_isOpen(self));
    int bytes_available = 0;
    if (RtReadyDataRS485(self->m_data.m_board_id, READY_DATA_TIMEOUT, &bytes_available))
    {
        return bytes_available;
    }
    return 0;
}


BOOL SP_IMPORT ORION_DAQ_RS485_read(struct _OrionDAQRS485* self, BYTE* buf, size_t buf_size, unsigned int timeout, ReadResult* read_result)
{
    assert(ORION_DAQ_RS485_isOpen(self));
    int read_len = 0;
    int bytes_available = 0;
    
    uint64_t clock_freq = getFreq();
    uint64_t start_time_us = getTimeUS(clock_freq);

    // bytes available?
    RtReadyDataRS485(self->m_data.m_board_id, timeout / 3, &bytes_available);

    // defensive: try again with larger timeout
    if (bytes_available <= 0)
    {
        uint64_t time_us = getTimeUS(clock_freq);
        unsigned int delta_ms = (unsigned int)((time_us - start_time_us) / 1000);
        if (delta_ms < timeout)
        {
            unsigned int wait_ms = timeout - delta_ms;
            RtReadyDataRS485(self->m_data.m_board_id, wait_ms, &bytes_available);
        }
    }


    if (bytes_available > 0)
    {
        LPSTR lpstr_buf = (LPSTR)(buf);
        read_len = RtReadRS485(self->m_data.m_board_id, lpstr_buf, (int)buf_size);

        read_result->m_type = OK;
        read_result->m_what.num_bytes = bytes_available;
        return TRUE;
    }
    else if (bytes_available < 0)
    {
        read_result->m_type = LOWLEVEL_ERROR;
        read_result->m_what.num_bytes = bytes_available;
        return FALSE;
    }
    else
    {
        read_result->m_type = TIMEOUT;
        read_result->m_what.num_bytes = bytes_available;
        return FALSE;
    }

    return FALSE;
}

BOOL SP_IMPORT ORION_DAQ_RS485_write(struct _OrionDAQRS485* self, BYTE* buf, size_t buf_size, unsigned int addr, unsigned int command_id)
{
    assert(ORION_DAQ_RS485_isOpen(self));

    LPSTR lpstr_buf = (LPSTR)buf;

    Sleep(5);

    if (!RtWriteRS485(self->m_data.m_board_id, lpstr_buf, (int)buf_size))
    {
        return FALSE;
    }

    return TRUE;
}

unsigned int SP_IMPORT ORION_DAQ_RS485_getBaudRate(struct _OrionDAQRS485* self)
{
    return DEFAULT_BAUD_RATE;
}

uint64_t getTime()
{
    LARGE_INTEGER time;
    QueryPerformanceCounter(&time);
    return time.QuadPart;
}

uint64_t getTimeUS(uint64_t freq)
{
    return (uint64_t)(getTime() / (freq / 1000000.0));
}

uint64_t getFreq()
{
    LARGE_INTEGER time;
    QueryPerformanceFrequency(&time);
    return time.QuadPart;
}
