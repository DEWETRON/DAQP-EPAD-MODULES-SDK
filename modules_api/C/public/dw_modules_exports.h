// Copyright (c) DEWETRON GmbH 2015
#ifndef _DW_MODULES_EXPORTS_H_
#define _DW_MODULES_EXPORTS_H_
#pragma once

#ifdef WIN32
#include "windows.h"
#endif

#ifdef WIN32
# ifdef __GNUC__
#  define DW_EXPORT __attribute__ ((dllexport))
#  define EXTERN_C extern "C"
#  define DW_EXPORT_CLASS
# else
#  define DW_EXPORT WINAPI
# endif
#else
# define DW_EXPORT __attribute__ ((visibility ("default")))
# define EXTERN_C extern "C"
# define DW_EXPORT_CLASS
#endif


#endif // _DW_MODULES_EXPORTS_H_
