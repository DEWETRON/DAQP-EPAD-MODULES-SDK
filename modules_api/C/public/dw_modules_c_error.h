// Copyright (c) DEWETRON GmbH 2015

#ifndef _DW_MODULES_C_ERROR_H_
#define _DW_MODULES_C_ERROR_H_
#pragma once

enum DwError
{
    DW_SUCCESS = 0,
    DW_ERROR,
    DW_ERR_INIT_FAILED,
    DW_ERR_NOT_INITIALIZED,
    DW_ERR_INVALID_HANDLE,
    DW_ERR_BUFFER_TOO_SMALL,
    DW_ERR_GET_PARAM_STR_LEN,
    DW_ERR_GET_PARAM_STR,
    DW_ERR_SET_PARAM_STR,
    DW_ERR_GET_PARAM_XML_LEN,
    DW_ERR_GET_PARAM_XML,
    DW_ERR_SET_PARAM_I32,
    DW_ERR_GET_PARAM_I32,
    DW_ERR_SET_PARAM_PTR,
    DW_ERR_GET_PARAM_PTR
};

inline const char* DwErrorStr(int err)
{
    switch(err)
    {
    case DW_SUCCESS: return "DW_SUCCESS";
    case DW_ERROR: return "DW_ERROR";
    case DW_ERR_INIT_FAILED: return "DW_ERR_INIT_FAILED";
    case DW_ERR_NOT_INITIALIZED: return "DW_ERR_NOT_INITIALIZED";
    case DW_ERR_INVALID_HANDLE: return "DW_ERR_INVALID_HANDLE";
    case DW_ERR_BUFFER_TOO_SMALL: return "DW_ERR_BUFFER_TOO_SMALL";
    case DW_ERR_GET_PARAM_STR_LEN: return "DW_ERR_GET_PARAM_STR_LEN";
    case DW_ERR_GET_PARAM_STR: return "DW_ERR_GET_PARAM_STR";
    case DW_ERR_SET_PARAM_STR: return "DW_ERR_SET_PARAM_STR";
    case DW_ERR_GET_PARAM_XML_LEN: return "DW_ERR_GET_PARAM_XML_LEN";
    case DW_ERR_GET_PARAM_XML: return "DW_ERR_GET_PARAM_XML";
    case DW_ERR_SET_PARAM_I32: return "DW_ERR_SET_PARAM_I32";
    case DW_ERR_GET_PARAM_I32: return "DW_ERR_GET_PARAM_I32";
    case DW_ERR_SET_PARAM_PTR: return "DW_ERR_SET_PARAM_PTR";
    case DW_ERR_GET_PARAM_PTR: return "DW_ERR_GET_PARAM_PTR";
    }
    return "DW_UNKNOWN_ERROR";
}

#endif // _DW_MODULES_C_ERROR_H_
