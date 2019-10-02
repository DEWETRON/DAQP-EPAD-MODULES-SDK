// Copyright (c) Dewetron 2019
#include "dw_modules_load.h"
#include "dw_modules_c_command.h"
#include "dw_modules_c_error.h"
#include <assert.h>
#include <stdio.h>


// default handle to access api instead of modules
ModuleHandle API_HANDLE = (ModuleHandle)-1;

int enableDaqpSimulation(const char* serial_port_name);
void printModuleProperties(ModuleHandle module);
void printModes(ModuleHandle module);

void setVoltageMode(ModuleHandle module);
void setBridgeMode(ModuleHandle module);
void setResistenceMode(ModuleHandle module);

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
    error = enableDaqpSimulation(serial_port_name);

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

            setVoltageMode(module);
            setBridgeMode(module);
            setResistenceMode(module);
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


int enableDaqpSimulation(const char* serial_port_name)
{
    int error = 0;
    int delay = 0;
    int slot_no = 0;

    error = DeWeSetParam_i32(API_HANDLE, DWCMD_SIM_COMMAND_DELAY, delay);
    error = DeWeSimAddSerialPort(serial_port_name);
    error = DeWeSimAddModule("DAQP-STG", "", serial_port_name, slot_no);

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
    char curr_prop[2048] = { 0 };

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

void setVoltageMode(ModuleHandle module)
{
    int error = 0;
    char mode[128] = { 0 };
    char ranges_list[256] = { 0 };
    char current_range[32] = { 0 };
    char lp_filter_type[32] = { 0 };
    char lp_filter_val[32] = { 0 };
    char exc_type[32] = { 0 };
    char exc_val[32] = { 0 };
    char input_type[32] = { 0 };
    char possible_actions[256] = { 0 };

    printf("setVoltageMode\n");

    // set voltage mode
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode", "Voltage");
    checkError(error);
    // verify mode
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode", mode, sizeof(mode));
    checkError(error);
    assert(0 == STR_CMP("Voltage", mode));

    // query available ranges
    error = DeWeGetParamStr(module, "AvailProp", "Channel[1]/Mode/Range", ranges_list, sizeof(ranges_list));
    checkError(error);
    printf("Ranges %s\n", ranges_list);

    // set a valid range
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/Range", "0.5V");
    checkError(error);
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode/Range", current_range, sizeof(current_range));
    checkError(error);
    assert(0 == STR_CMP("0.5V", current_range));

    // set low pass filter Butterworth
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/LPFilter/LPFilter_Type", "Butterworth");
    checkError(error);
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/LPFilter/LPFilter_Val", "10000Hz");
    checkError(error);
    // verify
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode/LPFilter/LPFilter_Type", lp_filter_type, sizeof(lp_filter_type));
    checkError(error);
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode/LPFilter/LPFilter_Val", lp_filter_val, sizeof(lp_filter_val));
    checkError(error);
    assert(0 == STR_CMP("Butterworth", lp_filter_type));
    assert(0 == STR_CMP("10000Hz", lp_filter_val));

    // set low pass filter Bessel
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/LPFilter/LPFilter_Type", "Bessel");
    checkError(error);
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/LPFilter/LPFilter_Val", "3000Hz");
    checkError(error);
    // verify
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode/LPFilter/LPFilter_Type", lp_filter_type, sizeof(lp_filter_type));
    checkError(error);
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode/LPFilter/LPFilter_Val", lp_filter_val, sizeof(lp_filter_val));
    checkError(error);
    assert(0 == STR_CMP("Bessel", lp_filter_type));
    assert(0 == STR_CMP("3000Hz", lp_filter_val));

    // Voltage excitation
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/Excitation/Excitation_Type", "Voltage");
    checkError(error);
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/Excitation/Excitation_Val", "1V");
    checkError(error);
    // verify
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode/Excitation/Excitation_Type", exc_type, sizeof(exc_type));
    checkError(error);
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode/Excitation/Excitation_Val", exc_val, sizeof(exc_val));
    checkError(error);
    assert(0 == STR_CMP("Voltage", exc_type));
    assert(0 == STR_CMP("1V", exc_val));

    // Current excitation
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/Excitation/Excitation_Type", "Current");
    checkError(error);
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/Excitation/Excitation_Val", "1mA");
    checkError(error);
    // verify
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode/Excitation/Excitation_Type", exc_type, sizeof(exc_type));
    checkError(error);
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode/Excitation/Excitation_Val", exc_val, sizeof(exc_val));
    checkError(error);
    assert(0 == STR_CMP("Current", exc_type));
    assert(0 == STR_CMP("1mA", exc_val));

    // Input Type
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode/InputType", input_type, sizeof(input_type));
    checkError(error);
    assert(0 == STR_CMP("Voltage", input_type));

    // apply settings to amplifier
    error = DeWeSetParam_i32(module, DWCMD_APPLY_PARAM, 0);
    checkError(error);


    // Actions
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode/Actions", possible_actions, sizeof(possible_actions));
    checkError(error);

    // Amplifier balance action
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/Actions", "AmplifierBalance");
    checkError(error);
}


void setBridgeMode(ModuleHandle module)
{
    int error = 0;
    char mode[128] = { 0 };
    char ranges_list[256] = { 0 };
    char current_range[32] = { 0 };
    char shunt[32] = { 0 };
    char lp_filter_type[32] = { 0 };
    char lp_filter_val[32] = { 0 };
    char input_type[32] = { 0 };
    char possible_actions[256] = { 0 };
    char bridge_res[32] = { 0 };
    char short_circuit[32] = { 0 };
    char input_off_range[32] = { 0 };

    printf("setBridgeMode\n");

    // set voltage mode
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode", "Bridge");
    checkError(error);
    // verify mode
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode", mode, sizeof(mode));
    checkError(error);
    assert(0 == STR_CMP("Bridge", mode));

    //
    // Attention: ranges depend on excitation (range and type)!
    //

    // Voltage excitation
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/Excitation/Excitation_Type", "Voltage");
    checkError(error);
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/Excitation/Excitation_Val", "5V");
    checkError(error);

    // query available ranges
    error = DeWeGetParamStr(module, "AvailProp", "Channel[1]/Mode/Range", ranges_list, sizeof(ranges_list));
    checkError(error);
    printf("Ranges for 5V excitation: %s\n", ranges_list);


    // set range
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/Range", "100mV/V");
    checkError(error);
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode/Range", current_range, sizeof(current_range));
    checkError(error);
    assert(0 == STR_CMP("100mV/V", current_range));

    // change excitation 5V -> 1V: Get new ranges!
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/Excitation/Excitation_Val", "1V");
    checkError(error);

    error = DeWeGetParamStr(module, "AvailProp", "Channel[1]/Mode/Range", ranges_list, sizeof(ranges_list));
    checkError(error);
    printf("Ranges for 1V excitation: %s\n", ranges_list);

    // current set range changes too!
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode/Range", current_range, sizeof(current_range));
    checkError(error);
    assert(0 == STR_CMP("500mV/V", current_range));


    // Current excitation
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/Excitation/Excitation_Type", "Current");
    checkError(error);
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/Excitation/Excitation_Val", "1mA");
    checkError(error);

    // query available ranges
    error = DeWeGetParamStr(module, "AvailProp", "Channel[1]/Mode/Range", ranges_list, sizeof(ranges_list));
    checkError(error);
    printf("Ranges for 1mA excitation: %s\n", ranges_list);


    // set range
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/Range", "100mV/mA");
    checkError(error);
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode/Range", current_range, sizeof(current_range));
    checkError(error);
    assert(0 == STR_CMP("100mV/mA", current_range));

    // change excitation 1mA -> 5mA: Get new ranges!
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/Excitation/Excitation_Val", "5mA");
    checkError(error);

    error = DeWeGetParamStr(module, "AvailProp", "Channel[1]/Mode/Range", ranges_list, sizeof(ranges_list));
    checkError(error);
    printf("Ranges for 5mA excitation: %s\n", ranges_list);

    // current set range changes too!
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode/Range", current_range, sizeof(current_range));
    checkError(error);
    assert(0 == STR_CMP("20mV/mA", current_range));

    // shunt
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/Shunt", "On");
    checkError(error);
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode/Shunt", shunt, sizeof(shunt));
    checkError(error);
    assert(0 == STR_CMP("On", shunt));

    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/Shunt", "Off");
    checkError(error);
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode/Shunt", shunt, sizeof(shunt));
    checkError(error);
    assert(0 == STR_CMP("Off", shunt));


    // set low pass filter Butterworth
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/LPFilter/LPFilter_Type", "Butterworth");
    checkError(error);
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/LPFilter/LPFilter_Val", "10000Hz");
    checkError(error);
    // verify
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode/LPFilter/LPFilter_Type", lp_filter_type, sizeof(lp_filter_type));
    checkError(error);
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode/LPFilter/LPFilter_Val", lp_filter_val, sizeof(lp_filter_val));
    checkError(error);
    assert(0 == STR_CMP("Butterworth", lp_filter_type));
    assert(0 == STR_CMP("10000Hz", lp_filter_val));

    // set low pass filter Bessel
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/LPFilter/LPFilter_Type", "Bessel");
    checkError(error);
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/LPFilter/LPFilter_Val", "3000Hz");
    checkError(error);
    // verify
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode/LPFilter/LPFilter_Type", lp_filter_type, sizeof(lp_filter_type));
    checkError(error);
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode/LPFilter/LPFilter_Val", lp_filter_val, sizeof(lp_filter_val));
    checkError(error);
    assert(0 == STR_CMP("Bessel", lp_filter_type));
    assert(0 == STR_CMP("3000Hz", lp_filter_val));

    // Input Type
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/InputType", "BRFULL");
    checkError(error);
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode/InputType", input_type, sizeof(input_type));
    checkError(error);
    assert(0 == STR_CMP("BRFULL", input_type));

    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/InputType", "BRHALF");
    checkError(error);
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode/InputType", input_type, sizeof(input_type));
    checkError(error);
    assert(0 == STR_CMP("BRHALF", input_type));

    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/InputType", "BRQUARTER3W");
    checkError(error);
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode/InputType", input_type, sizeof(input_type));
    checkError(error);
    assert(0 == STR_CMP("BRQUARTER3W", input_type));

    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/InputType", "BRQUARTER4W");
    checkError(error);
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode/InputType", input_type, sizeof(input_type));
    checkError(error);
    assert(0 == STR_CMP("BRQUARTER4W", input_type));

    // Bridge Resistance
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/InputType", "BRQUARTER3W");
    checkError(error);
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/BridgeResistance", "120Ohm");
    checkError(error);
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode/BridgeResistance", bridge_res, sizeof(bridge_res));
    checkError(error);
    assert(0 == STR_CMP("120Ohm", bridge_res));
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/BridgeResistance", "350Ohm");
    checkError(error);
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode/BridgeResistance", bridge_res, sizeof(bridge_res));
    checkError(error);
    assert(0 == STR_CMP("350Ohm", bridge_res));

    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/InputType", "BRQUARTER4W");
    checkError(error);
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/BridgeResistance", "120Ohm");
    checkError(error);
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode/BridgeResistance", bridge_res, sizeof(bridge_res));
    checkError(error);
    assert(0 == STR_CMP("120Ohm", bridge_res));
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/BridgeResistance", "350Ohm");
    checkError(error);
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode/BridgeResistance", bridge_res, sizeof(bridge_res));
    checkError(error);
    assert(0 == STR_CMP("350Ohm", bridge_res));

    // Short
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/Short", "Off");
    checkError(error);
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode/Short", short_circuit, sizeof(short_circuit));
    checkError(error);
    assert(0 == STR_CMP("Off", short_circuit));

    // InputOffsetRange
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode/InputOffsetRange", input_off_range, sizeof(input_off_range));
    checkError(error);

    // apply settings to amplifier
    error = DeWeSetParam_i32(module, DWCMD_APPLY_PARAM, 0);
    checkError(error);

    // Actions
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode/Actions", possible_actions, sizeof(possible_actions));
    checkError(error);

    // Amplifier balance action
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/Actions", "SensorBalance");
    checkError(error);
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/Actions", "ReadSensorOffsetAdjustment");
    checkError(error);

    // read input offset
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode/InputOffsetRange", input_off_range, sizeof(input_off_range));
    checkError(error);

    // write sensor offset back
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/Actions", "WriteSensorOffsetAdjustment");
    checkError(error);

}

void setResistenceMode(ModuleHandle module)
{
    int error = 0;
    char mode[128] = { 0 };
    char ranges_list[256] = { 0 };
    char current_range[32] = { 0 };

    printf("setResistenceMode\n");

    // set voltage mode
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode", "Resistance");
    checkError(error);
    // verify mode
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode", mode, sizeof(mode));
    checkError(error);
    assert(0 == STR_CMP("Resistance", mode));

    // query available ranges
    error = DeWeGetParamStr(module, "AvailProp", "Channel[1]/Mode/Range", ranges_list, sizeof(ranges_list));
    checkError(error);
    printf("Ranges %s\n", ranges_list);

    // set a valid range
    error = DeWeSetParamStr(module, "CurrProp", "Channel[1]/Mode/Range", "250Ohm");
    checkError(error);
    error = DeWeGetParamStr(module, "CurrProp", "Channel[1]/Mode/Range", current_range, sizeof(current_range));
    checkError(error);
    assert(0 == STR_CMP("250Ohm", current_range));
}

int checkError(int error)
{
    if (error != DW_SUCCESS)
    {
        printf("Error %s\n", DwErrorStr(error));
    }
    return error;
}