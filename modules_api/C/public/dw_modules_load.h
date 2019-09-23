// Copyright (c) DEWETRON GmbH 2015

#ifndef _DW_MODULES_LOAD_H_
#define _DW_MODULES_LOAD_H_
#pragma once

#include "dw_modules_c_core.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * Define BUILD_X64 for 64bit builds
 * Define BUILD_X86 for 32bit builds (default)
 */
#ifndef BUILD_X64
  #ifndef BUILD_X86
    // if nothing is defined default to 32bit
    #define BUILD_X86
  #endif
#endif

#ifdef BUILD_X64
  // 64bit API
  #ifdef WIN32
    #include <windows.h>
      static const char DEWE_MODULES_DLL_NAME[] = "dw_modules_api_x64.dll";
  #elif defined(__APPLE__)
    #include <dlfcn.h>
    static const char DEWE_MODULES_DLL_NAME[]   = "libdw_modules_api_x64.dylib";
  #elif defined(UNIX)
    #include <dlfcn.h>
    static const char DEWE_MODULES_DLL_NAME[]   = "libdw_modules_api_x64.so";
  #endif //UNIX
#endif
#ifdef BUILD_X86
  // 32bit API
  #ifdef WIN32
    #include <windows.h>
      static const char DEWE_MODULES_DLL_NAME[] = "dw_modules_api.dll";
  #elif defined(__APPLE__)
    #include <dlfcn.h>
    static const char DEWE_MODULES_DLL_NAME[]   = "libdw_modules_api.dylib";
  #elif defined(UNIX)
    #include <dlfcn.h>
    static const char DEWE_MODULES_DLL_NAME[]   = "libdw_modules_api.so";
  #endif //UNIX
#endif



#include <stdio.h>
#if !defined(WIN32) && !defined(__APPLE__) && defined(__linux__)
#include <linux/limits.h>
#include <libgen.h>
#include <unistd.h>
#endif



#ifdef WIN32
# ifndef DW_IMPORT
#  define DW_IMPORT WINAPI
# endif
#else
# ifndef DW_IMPORT
#  define DW_IMPORT
# endif
#endif


/**
 * API Functions:
 */

/**
 * Load DLL
 */
int DeWeModulesLoad(void);

/**
 * Unload DLL
 */
void DeWeModulesUnload(void);


#ifdef __cplusplus
#  ifdef DEWE_MODULES_NS
using namespace DwModApi;
#  endif
#endif


#ifndef DW_MODULES_NO_API_INJECTION

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


static int     bLoaded = FALSE;



#ifdef WIN32
static HINSTANCE   hLib = 0;
#endif //WIN32

#ifdef UNIX
static void*       hLib = 0;
#endif //UNIX


#ifndef STATIC_DLL


#ifdef WIN32
  #ifdef LOADDLLFUNCTION
    #error "LOADDLLFUNCTION already defined"
  #else
    #define LOADDLLFUNCTION(lib, type, name) (type) loadFunction(#name, &bTotResult);
    #define LOAD_LIBRARY(dll_name) LoadLibraryA(dll_name)
    #define CLOSE_LIBRARY(so_name) FreeLibrary(hLib);
  #endif //LOADDLLFUNCTION

  //local helper function
  static void* loadFunction( const char* pcName, int* bTotalOK );
#endif //WIN32

#ifdef UNIX
  #ifdef LOADDLLFUNCTION
    #error "LOADDLLFUNCTION already defined"
  #else
    #define LOADDLLFUNCTION(lib, type, name) (type) dlsym(lib, #name); \
    if ((error = dlerror()) != NULL) {                                  \
        fprintf(stderr, "%s\n", error);                                 \
        bLoaded = FALSE;                                                \
        DeWeModulesUnload();                                            \
        return bLoaded;                                                 \
    }

    #ifdef __APPLE__
      #define DW_DLOPEN_FLAGS RTLD_LAZY | RTLD_LOCAL
    #else
      #define DW_DLOPEN_FLAGS RTLD_LAZY | RTLD_LOCAL | RTLD_DEEPBIND | RTLD_NODELETE
    #endif

    #define LOAD_LIBRARY(so_name) dlopen(so_name, DW_DLOPEN_FLAGS);   \
    if (!hLib) {                                                \
        error = dlerror();                                      \
        fprintf(stderr, "%s\n", error);                         \
    }


    #define CLOSE_LIBRARY(so_name) dlclose(so_name)
  #endif //LOADDLLFUNCTION
#endif //UNIX


#ifdef UNLOADDLLFUNCTION
  #error "UNLOADDLLFUNCTION already defined"
#else
  #define UNLOADDLLFUNCTION(f)       f = NULL;
#endif
#endif  //STATIC_DLL


#ifndef STATIC_DLL
#ifdef WIN32
static
void*
loadFunction(
             const char*        pcName,
             int*           bTotalOK
             )
{
    void*       pf = NULL;
    int     bDummy = FALSE;

    if ( NULL == bTotalOK ){
        bTotalOK = &bDummy;
    }
    if ( !hLib ) {
        *bTotalOK = FALSE;
        return pf;
    }
    if ( NULL == pcName ){
        *bTotalOK = FALSE;
        return pf;
    }

    pf = GetProcAddress(hLib, pcName);

    if ( NULL == pf ){
        *bTotalOK = FALSE;
#ifndef NDEBUG
        {
            char szMsg[255] = {0};
            DWORD err;
            err = GetLastError();
            _snprintf_s( szMsg, _countof(szMsg), _TRUNCATE, "%s failed to load (ERR %d).", pcName, err );
            OutputDebugStringA(pcName);
        }
#endif

    }
    return pf;
}
#endif //WIN32

/**
 * Load dw_modules_api
 */
int DeWeModulesLoad(void)
{
    int        bTotResult = TRUE;
    char*          error = NULL;
    int revision = 0;

    //Trap multiple Loads
    if ( bLoaded ) {
        return bLoaded;
    }

    hLib = LOAD_LIBRARY(DEWE_MODULES_DLL_NAME);
#if !defined(WIN32) && !defined(__APPLE__) && defined(__linux__)
    if (!hLib)
    {
        char executable_path[PATH_MAX];
        ssize_t count = readlink("/proc/self/exe", executable_path, PATH_MAX);
        if (count != -1)
        {
            const char *search_path = dirname(executable_path);
            char real_plugin_filename[PATH_MAX];
            snprintf(real_plugin_filename, PATH_MAX, "%s/%s", search_path, DEWE_MODULES_DLL_NAME);
            hLib = LOAD_LIBRARY(real_plugin_filename);
        }
    }
#endif
    if (hLib)
        bLoaded = TRUE;
    else
        bLoaded = FALSE;

    bTotResult = bLoaded;

    if (bTotResult)
    {
        // Api Init
        DeWeInit = LOADDLLFUNCTION( hLib, PDEWE_INIT, DeWeInit );
        DeWeDeInit = LOADDLLFUNCTION( hLib, PDEWE_DEINIT, DeWeDeInit );

        // factory/get
        DeWeCreateModule = LOADDLLFUNCTION(hLib, PDEWE_CREATE_MODULE, DeWeCreateModule);
        DeWeGetModule = LOADDLLFUNCTION(hLib, PDEWE_GET_MODULE, DeWeGetModule);

        // string based functions
        DeWeGetParamStrLen = LOADDLLFUNCTION(hLib, PDEWE_GET_PARAM_STRLEN, DeWeGetParamStrLen);
        DeWeGetParamStr = LOADDLLFUNCTION(hLib, PDEWE_GET_PARAM_STR, DeWeGetParamStr);
        DeWeSetParamStr = LOADDLLFUNCTION(hLib, PDEWE_SET_PARAM_STR, DeWeSetParamStr);

        DeWeGetParamXMLLen = LOADDLLFUNCTION(hLib, PDEWE_GET_PARAM_XMLLEN, DeWeGetParamXMLLen);
        DeWeGetParamXML = LOADDLLFUNCTION(hLib, PDEWE_GET_PARAM_XML, DeWeGetParamXML);

        DeWeSetParam_i32 = LOADDLLFUNCTION(hLib, PDEWE_SET_PARAM_I32, DeWeSetParam_i32);
        DeWeGetParam_i32 = LOADDLLFUNCTION(hLib, PDEWE_GET_PARAM_I32, DeWeGetParam_i32);

        DeWeSetParam_Ptr = LOADDLLFUNCTION(hLib, PDEWE_SET_PARAM_PTR, DeWeSetParam_Ptr);
        DeWeGetParam_Ptr = LOADDLLFUNCTION(hLib, PDEWE_GET_PARAM_PTR, DeWeGetParam_Ptr);

        DeWeScanAddress = LOADDLLFUNCTION(hLib, PDEWE_SCAN_ADDRESS, DeWeScanAddress);
        DeWeSetAddress = LOADDLLFUNCTION(hLib, PDEWE_SET_ADDRESS, DeWeSetAddress);

        DeWeSimAddSerialPort = LOADDLLFUNCTION(hLib, PDEWESIM_ADD_SERIAL_PORT, DeWeSimAddSerialPort);
        DeWeSimAddModule = LOADDLLFUNCTION(hLib, PDEWESIM_ADD_MODULE, DeWeSimAddModule);
        DeWeSimRemoveModule = LOADDLLFUNCTION(hLib, PDEWESIM_REMOVE_MODULE, DeWeSimRemoveModule);

        // // Obtain readable ErrorMessage from ErroCode
        // LOADDLLFUNCTION( hLib, PDEWEERRORCONSTANTTOSTRING, DeWeErrorConstantToString );

        // //Load the Test interface, if provided
        // bTotResult = DewePxiLoadTestInterface( &bTotResult );
    }


    if (bTotResult)
    {
        revision = 1;
    }

    if ( 0 == revision) //no valid dll found
    {
        DeWeModulesUnload();
    }

    return revision;
}



/**
 * Unload dw_modules_api
 */
void DeWeModulesUnload(void)
{
     if (bLoaded)
     {
         //if(DeWeDriverDeInit != 0) {
         //    DeWeDriverDeInit();
         //}
         CLOSE_LIBRARY(hLib);
         bLoaded = FALSE;
         hLib    = 0;
     }

    // Driver Init
    UNLOADDLLFUNCTION(DeWeInit);
    UNLOADDLLFUNCTION(DeWeDeInit);

    UNLOADDLLFUNCTION(DeWeCreateModule);
    UNLOADDLLFUNCTION(DeWeGetModule);

    // string based functions
    UNLOADDLLFUNCTION(DeWeGetParamStrLen);
    UNLOADDLLFUNCTION(DeWeGetParamStr);
    UNLOADDLLFUNCTION(DeWeSetParamStr);

    UNLOADDLLFUNCTION(DeWeGetParamXMLLen);
    UNLOADDLLFUNCTION(DeWeGetParamXML);

    UNLOADDLLFUNCTION(DeWeSetParam_i32);
    UNLOADDLLFUNCTION(DeWeGetParam_i32);

    UNLOADDLLFUNCTION(DeWeSetParam_Ptr);
    UNLOADDLLFUNCTION(DeWeGetParam_Ptr);

    UNLOADDLLFUNCTION(DeWeScanAddress);
    UNLOADDLLFUNCTION(DeWeSetAddress);

    UNLOADDLLFUNCTION(DeWeSimAddSerialPort);
    UNLOADDLLFUNCTION(DeWeSimAddModule);
    UNLOADDLLFUNCTION(DeWeSimRemoveModule);
}

#else // STATIC_DLL

/**
 * DeWeModulesLoad
 * empty implementation for static linking
 */
int DeWeModulesLoad(void)
{
    int revision = 1;

    bLoaded = TRUE;

    return revision;
}

/**
 * DeWeModulesUnload
 * empty implementation for static linking
 */
void DeWeModulesUnload(void)
{
    if (bLoaded) {
        DeWeDriverDeInit();
    }
    bLoaded = FALSE;
}

#endif

#ifndef STATIC_DLL

#undef LOADDLLFUNCTION
#undef UNLOADDLLFUNCTION

#endif //STATIC_DLL

#endif //DW_MODULES_NO_API_INJECTION

#ifdef __cplusplus
}
#endif


#endif // _DW_MODULES_LOAD_H_
