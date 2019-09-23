// Copyright (c) Dewetron 2014

#ifndef _DW_MODULES_C_CORE_H_
#define _DW_MODULES_C_CORE_H_

#include "dw_modules_exports.h"

#ifdef _WIN32
# include <windows.h>
# ifndef DW_IMPORT
#  define DW_IMPORT WINAPI //__declspec(dllimport)
# endif
#else
# ifndef DW_IMPORT
#  define DW_IMPORT
# endif
#endif

#ifndef _DW_MODULES_LOAD_H_
	#define DWLOAD	extern
#else
	#define DWLOAD
#endif

#ifdef DW_MODULES_NO_API_INJECTION
# ifdef DWLOAD
#  undef DWLOAD
# endif
# define DWLOAD	extern
#endif

/**
 * Type - Definitions
 */
typedef signed char       sint8;
typedef signed short      sint16;
typedef signed int        sint32;
typedef signed long long  sint64;

typedef unsigned char       uint8;
typedef unsigned short      uint16;
typedef unsigned int        uint32;
typedef unsigned long long  uint64;


#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif


typedef void* ModuleHandle;

typedef int (DW_IMPORT *PDEWE_INIT)(void);
typedef int (DW_IMPORT *PDEWE_DEINIT)(void);

typedef ModuleHandle (DW_IMPORT *PDEWE_CREATE_MODULE)(const char* name, const char* fw_revision, const char* port, uint8 address);
typedef ModuleHandle (DW_IMPORT *PDEWE_GET_MODULE)(const char* port, uint8 address);

typedef int (DW_IMPORT *PDEWE_GET_PARAM_STRLEN)(ModuleHandle mh, const char* source, const char* path, uint32* buffer_len);
typedef int (DW_IMPORT *PDEWE_GET_PARAM_STR)(ModuleHandle mh, const char* source, const char* path, char* buffer, uint32 buffer_len);
typedef int (DW_IMPORT *PDEWE_SET_PARAM_STR)(ModuleHandle mh, const char* source, const char* path, const char* buffer);

typedef int (DW_IMPORT *PDEWE_GET_PARAM_XMLLEN)(ModuleHandle mh, const char* source, const char* path, uint32* buffer_len);
typedef int (DW_IMPORT *PDEWE_GET_PARAM_XML)(ModuleHandle mh, const char* source, const char* path, char* buffer, uint32 buffer_len);

typedef int (DW_IMPORT *PDEWE_SET_PARAM_I32)(ModuleHandle mh, uint32 command, int val);
typedef int (DW_IMPORT *PDEWE_GET_PARAM_I32)(ModuleHandle mh, uint32 command, int* val);

typedef int (DW_IMPORT *PDEWE_SET_PARAM_PTR)(ModuleHandle mh, uint32 command, void* val, uint32 size);
typedef int (DW_IMPORT *PDEWE_GET_PARAM_PTR)(ModuleHandle mh, uint32 command, void* val, uint32 size);

typedef int (DW_IMPORT *PDEWE_SCAN_ADDRESS)(ModuleHandle mh, const char* port, uint8 addr, int* status);

typedef int (DW_IMPORT *PDEWE_SET_ADDRESS)(ModuleHandle mh, const char* port, uint8 addr);

typedef int (DW_IMPORT *PDEWESIM_ADD_SERIAL_PORT)(const char* port);
typedef int (DW_IMPORT *PDEWESIM_ADD_MODULE)(const char* name, const char* fw_revision, const char* port, uint8 address);
typedef int (DW_IMPORT *PDEWESIM_REMOVE_MODULE)(const char* port, uint8 address);

#ifdef __cplusplus
#  ifdef DEWE_MODULES_NS
namespace DwModApi {
#  endif
#endif

DWLOAD PDEWE_INIT              DeWeInit;
DWLOAD PDEWE_DEINIT            DeWeDeInit;
DWLOAD PDEWE_CREATE_MODULE     DeWeCreateModule;
DWLOAD PDEWE_GET_MODULE        DeWeGetModule;
DWLOAD PDEWE_GET_PARAM_STRLEN  DeWeGetParamStrLen;
DWLOAD PDEWE_GET_PARAM_STR     DeWeGetParamStr;
DWLOAD PDEWE_SET_PARAM_STR     DeWeSetParamStr;
DWLOAD PDEWE_GET_PARAM_XMLLEN  DeWeGetParamXMLLen;
DWLOAD PDEWE_GET_PARAM_XML     DeWeGetParamXML;
DWLOAD PDEWE_SET_PARAM_I32     DeWeSetParam_i32;
DWLOAD PDEWE_GET_PARAM_I32     DeWeGetParam_i32;
DWLOAD PDEWE_SET_PARAM_PTR     DeWeSetParam_Ptr;
DWLOAD PDEWE_GET_PARAM_PTR     DeWeGetParam_Ptr;
DWLOAD PDEWE_SCAN_ADDRESS      DeWeScanAddress;
DWLOAD PDEWE_SET_ADDRESS       DeWeSetAddress;

DWLOAD PDEWESIM_ADD_SERIAL_PORT   DeWeSimAddSerialPort;
DWLOAD PDEWESIM_ADD_MODULE        DeWeSimAddModule;
DWLOAD PDEWESIM_REMOVE_MODULE     DeWeSimRemoveModule;

#ifdef __cplusplus
#  ifdef DEWE_MODULES_NS
}
#  endif
#endif

#endif // _DW_MODULES_C_CORE_H_
