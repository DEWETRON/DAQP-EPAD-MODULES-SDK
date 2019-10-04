// Copyright (c) Dewetron 2019
#pragma once

#ifdef WIN32
# include <windows.h>
# define SP_IMPORT WINAPI
#else
# define SP_IMPORT
#endif


typedef enum {
    OK,
    TIMEOUT,
    LOWLEVEL_ERROR,
}  ReadResultType;

typedef struct {

    ReadResultType m_type;
    union
    {
        size_t num_bytes;
    } m_what;
} ReadResult;



// struct _MySerialPort;

// typedef const char* (SP_IMPORT *P_SP_GET_PORT_NAME)(struct _MySerialPort*);
// typedef BOOL (SP_IMPORT *P_SP_OPEN)(struct _MySerialPort*);
// typedef BOOL (SP_IMPORT *P_SP_IS_OPEN)(struct _MySerialPort*);
// typedef BOOL (SP_IMPORT *P_SP_CLOSE)(struct _MySerialPort*);
// typedef int (SP_IMPORT *P_SP_NUM_BYTES_AVAILABLE)(struct _MySerialPort*);
// typedef BOOL (SP_IMPORT *P_SP_READ)(struct _MySerialPort*, BYTE* buf, size_t buf_size, unsigned int timeout, ReadResult* read_result);
// typedef BOOL (SP_IMPORT *P_SP_WRITE)(struct _MySerialPort*, BYTE* buf, size_t buf_size, unsigned int addr, unsigned int command_id);
// typedef unsigned int (SP_IMPORT *P_SP_GET_BAUDRATE)(struct _MySerialPort*);

// typedef struct {
//     P_SP_GET_PORT_NAME getPortName;
//     P_SP_OPEN open;
//     P_SP_IS_OPEN isOpen;
//     P_SP_CLOSE close;
//     P_SP_NUM_BYTES_AVAILABLE numBytesAvailable;
//     P_SP_READ read;
//     P_SP_WRITE write;
//     P_SP_GET_BAUDRATE getBaudRate;
// } MySerialPortVtable;


// typedef struct _MySerialPort  {
//     MySerialPortVtable* _vtable;
// } MySerialPort;


#define DW_CUSTOM_SERIAL_PORT(CUST_SER_PORT)                                                 \
struct _ ## CUST_SER_PORT;                                                                   \
\
typedef const char* (SP_IMPORT *P_SP_GET_PORT_NAME)(struct _ ## CUST_SER_PORT*);             \
typedef BOOL (SP_IMPORT *P_SP_OPEN)(struct _ ## CUST_SER_PORT*);                             \
typedef BOOL (SP_IMPORT *P_SP_IS_OPEN)(struct _ ## CUST_SER_PORT*);                          \
typedef BOOL (SP_IMPORT *P_SP_CLOSE)(struct _ ## CUST_SER_PORT*);                            \
typedef int (SP_IMPORT *P_SP_NUM_BYTES_AVAILABLE)(struct _ ## CUST_SER_PORT*);               \
typedef BOOL (SP_IMPORT *P_SP_READ)(struct _ ## CUST_SER_PORT*, BYTE* buf, size_t buf_size,  \
                                unsigned int timeout, ReadResult* read_result);             \
typedef BOOL (SP_IMPORT *P_SP_WRITE)(struct _ ## CUST_SER_PORT*, BYTE* buf, size_t buf_size, \
                                unsigned int addr, unsigned int command_id);                \
typedef unsigned int (SP_IMPORT *P_SP_GET_BAUDRATE)(struct _ ## CUST_SER_PORT*);            \
\
typedef struct {                                                                            \
    P_SP_GET_PORT_NAME getPortName;                                                         \
    P_SP_OPEN open;                                                                         \
    P_SP_IS_OPEN isOpen;                                                                    \
    P_SP_CLOSE close;                                                                       \
    P_SP_NUM_BYTES_AVAILABLE numBytesAvailable;                                             \
    P_SP_READ read;                                                                         \
    P_SP_WRITE write;                                                                       \
    P_SP_GET_BAUDRATE getBaudRate;                                                          \
}  CUST_SER_PORT ## Vtable;                                                                 \
\
typedef struct _ ## CUST_SER_PORT  {                                                        \
    CUST_SER_PORT ## Vtable* _vtable;                                                       \
} CUST_SER_PORT;                                                                            
