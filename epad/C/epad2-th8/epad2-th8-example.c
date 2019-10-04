// Copyright (c) Dewetron 2019
#include "dw_modules_load.h"
#include "dw_modules_c_command.h"
#include "dw_modules_c_error.h"
#include <assert.h>
#include <stdio.h>


// default handle to access api instead of modules
ModuleHandle API_HANDLE = (ModuleHandle)-1;

int enableSimulation(const char* serial_port_name);
void printModuleProperties(ModuleHandle module);
void printModes(ModuleHandle module);
void measure(ModuleHandle module, unsigned int num_channels);


int checkError(int error);

#define STR_CMP(a,b) strncmp(a, b, min(sizeof(a), sizeof(b)))

int main(int argc, char* argv[])
{
    int error = 0;
    int revision = 0;
    int addr = 0;
    int num_modules = 0;
    const char serial_port_name[] = "COM1";

    // Load the modules api dll
    revision = DeWeModulesLoad();

    // The api has to be initalized
    error = DeWeInit();

    // Enable simulation, configure a DAQP-STG @ address 0
    error = enableSimulation(serial_port_name);

    // Open serial port
    DeWeSetParamStr(API_HANDLE, "", "OPEN_PORT", serial_port_name);

    // Scan for module
    DeWeScanAddress(API_HANDLE, serial_port_name, addr, &num_modules);
    printf("Found %d modules\n", num_modules);
    
    if (num_modules > 0)
    {
        ModuleHandle module = NULL;

        // reuest a handle to the module
        module = DeWeGetModule(serial_port_name, addr);
        assert(module);
        if (module)
        {
            printModuleProperties(module);
            printModes(module);

            measure(module, 8);
        }
    }

    // Close serial port
    DeWeSetParamStr(API_HANDLE, "", "CLOSE_PORT", serial_port_name);

    // Cleanup api initialization
    error = DeWeDeInit();

    // Unload api dll
    DeWeModulesUnload();

    return error;
}


int enableSimulation(const char* serial_port_name)
{
    int error = 0;
    int delay = 0;
    int slot_no = 0;

    error = DeWeSetParam_i32(API_HANDLE, DWCMD_SIM_COMMAND_DELAY, delay);
    error = DeWeSimAddSerialPort(serial_port_name);
    error = DeWeSimAddModule("EPAD2-TH8", "", serial_port_name, slot_no);

    error = DeWeSetParam_i32(API_HANDLE, DWCMD_ENABLE_SIMULATION, 1);

    return error;
}


void printModuleProperties(ModuleHandle module)
{
    int error = 0;
    char name[32] = { 0 };
    char type[32] = { 0 };
    char fw_ver[32] = { 0 };

    char serial[32] = { 0 };
    char curr_prop[4096] = { 0 };

    error = DeWeGetParamStr(module, "CurrProp", "@Name", name, sizeof(name));
    checkError(error);
    printf("Name:     %s\n", name);

    error = DeWeGetParamStr(module, "CurrProp", "@Type", type, sizeof(type));
    checkError(error);
    printf("Type:     %s\n", type);

    error = DeWeGetParamStr(module, "CurrProp", "FirmwareVersion", fw_ver, sizeof(fw_ver));
    checkError(error);
    printf("Firmware: %s\n", fw_ver);

    error = DeWeGetParamStr(module, "CurrProp", "SerialNumber", serial, sizeof(serial));
    checkError(error);
    printf("Serial:   %s\n", serial);


    error = DeWeGetParamStr(module, "CurrProp", "Module", curr_prop, sizeof(curr_prop));
    checkError(error);
    printf("Current XML: %s\n", curr_prop);
}

void printModes(ModuleHandle module)
{
    int error = 0;
    char modes[512] = { 0 };

    error = DeWeGetParamStr(module, "AvailProp", "Channel[1]/Mode", modes, sizeof(modes));
    checkError(error);
    printf("Modes:   %s\n", modes);
}

void measure(ModuleHandle module, unsigned int num_channels)
{
    int error = 0;
    double sample_values[8] = { 0 };

    error = DeWeGetParam_Ptr(module,
        DWCMD_SAMPLES,
        &sample_values,
        sizeof(sample_values));
    checkError(error);

    for (unsigned int ch_idx = 0; ch_idx < num_channels; ++ch_idx)
    {
        printf("Channel %d:  %f\n", ch_idx+1, sample_values[ch_idx]);
    }
}

int checkError(int error)
{
    if (error != DW_SUCCESS)
    {
        printf("Error %s\n", DwErrorStr(error));
    }
    return error;
}