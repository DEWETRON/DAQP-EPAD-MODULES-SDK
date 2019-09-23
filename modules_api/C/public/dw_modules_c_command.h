// Copyright (c) DEWETRON GmbH 2015

#ifndef _DW_MODULES_C_COMMAND_H_
#define _DW_MODULES_C_COMMAND_H_
#pragma once


typedef void* ModuleHandle;

// default handle to access api instead of modules
extern ModuleHandle API_HANDLE;


enum DwModulesCmd
{
// Standard API
    DWCMD_SCAN = 100
    , DWCMD_CLEAR_SERIALPORT
    , DWCMD_ADD_SERIALPORT
    , DWCMD_REMOVE_SERIALPORT

// Standard Module
    , DWCMD_APPLY_PARAM = 200
    , DWCMD_RESET
    , DWCMD_READ_MODULE_CONFIGURATION
    , DWCMD_LOCK_MODULE_BUTTONS            // 1 -> lock, 0 -> unlock

 // EPAD only
    , DWCMD_SAMPLES = 400

// SIM
    , DWCMD_ENABLE_SIMULATION = 1000
    , DWCMD_SIM_COMMAND_DELAY
    , DWCMD_CLEAR_SIMULATION
};



#endif // _DW_MODULES_C_COMMAND_H_
