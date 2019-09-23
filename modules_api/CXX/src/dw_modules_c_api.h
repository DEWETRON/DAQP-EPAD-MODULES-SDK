// Copyright (c) Dewetron 2014

#ifndef _DW_MODULES_C_API_H_
#define _DW_MODULES_C_API_H_

#include <inttypes.h>
#include "dw_modules_exports.h"


typedef void* ModuleHandle;

/**
 * Startup and initialize the API
 * @return ERR_SUCCESS if successful
 */
EXTERN_C int DW_EXPORT DeWeInit();

/**
 * Tear down the API.
 * @Note: Do not call any API function after a call to DeWeDeInit.
 * @return ERR_SUCCESS if successful
 */
EXTERN_C int DW_EXPORT DeWeDeInit();

/**
 * Create a module (instance) at the given port / address.
 * Main usage: offline setup.
 * @param name
 * @param fw_revision (can be 0 or "" empty string)
 * @param port
 * @param chan_no (== address)
 */
EXTERN_C ModuleHandle DW_EXPORT DeWeCreateModule(const char* name, const char* fw_revision, const char* port, uint8_t address);

EXTERN_C ModuleHandle DW_EXPORT DeWeGetModule(const char* port, uint8_t address);

EXTERN_C int DW_EXPORT DeWeGetParamStrLen(ModuleHandle mh, const char* source, const char* path, uint32_t* buffer_len);

EXTERN_C int DW_EXPORT DeWeGetParamStr(ModuleHandle mh, const char* source, const char* path, char* buffer, uint32_t buffer_len);

EXTERN_C int DW_EXPORT DeWeSetParamStr(ModuleHandle mh, const char* source, const char* path, const char* buffer);

EXTERN_C int DW_EXPORT DeWeGetParamXMLLen(ModuleHandle mh, const char* source, const char* path, uint32_t* buffer_len);

EXTERN_C int DW_EXPORT DeWeGetParamXml(ModuleHandle mh, const char* source, const char* path, char* buffer, uint32_t buffer_len);

EXTERN_C int DW_EXPORT DeWeGetParam_i32(ModuleHandle mh, uint32_t command, int* val);

EXTERN_C int DW_EXPORT DeWeSetParam_i32(ModuleHandle mh, uint32_t command, int val);

EXTERN_C int DW_EXPORT DeWeGetParam_Ptr(ModuleHandle mh, uint32_t command, void* val, uint32_t size);

EXTERN_C int DW_EXPORT DeWeSetParam_Ptr(ModuleHandle mh, uint32_t command, void* val, uint32_t size);

EXTERN_C int DW_EXPORT DeWeScanAddress(ModuleHandle mh, const char* port, uint8_t addr, int* status);

EXTERN_C int DW_EXPORT DeWeSetAddress(ModuleHandle mh, const char* port, uint8_t addr);

EXTERN_C int DW_EXPORT DeWeSimAddSerialPort(const char* port);

EXTERN_C int DW_EXPORT DeWeSimAddModule(const char* name, const char* fw_revision, const char* port, uint8_t address);

EXTERN_C int DW_EXPORT DeWeSimRemoveModule(const char* port, uint8_t address);

#endif // _DW_MODULES_C_API_H_
