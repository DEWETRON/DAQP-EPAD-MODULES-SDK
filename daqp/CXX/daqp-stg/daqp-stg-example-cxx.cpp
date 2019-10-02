// Copyright (c) Dewetron 2019

#include "dw_modules_api_cxx.h"
#include "sp_serial_port_util.h"
#include "xpugixml.h"
#include <assert.h>
#include "stdio.h"


//#define VERBOSE

using namespace dwcxx;

bool enableDaqpSimulation(ModulesApi& dw_api, const std::string& serial_port_name);
void printModuleProperties(IfModulePtr module);
void printModes(IfModulePtr module);
void printCurrentSettings(IfModulePtr module);
void setVoltageMode(IfModulePtr module);
void setBridgeMode(IfModulePtr module);
void setResistenceMode(IfModulePtr module);

int main(int argc, char* argv[])
{
    int success = 0;
    std::string serial_port_name = "COM1";


    // Scan for available serial ports
    sp::SerialPortUtil sp;
    auto ports = sp.getPortNamesSorted();
      
    // Instantiate the api
    ModulesApi  dw_api;

    // The api has to be initalized
    success = dw_api.init();

    // Enable simulation, configure a DAQP-STG @ address 0
    success = enableDaqpSimulation(dw_api, serial_port_name);

    // Open serial port
    dw_api.openPort(serial_port_name);

    // Scan for module
    int num_modules = dw_api.scanAddress(serial_port_name, 0);
    printf("Found %d modules\n", num_modules);

    // access the amplifier module
    IfModuleWPtr module_wp = dw_api.getModule(serial_port_name, 0);
    if (auto module = module_wp.lock())
    {
        printModuleProperties(module);
        printModes(module);

        setVoltageMode(module);
        setBridgeMode(module);
        setResistenceMode(module);
    }

    // Close serial port
    dw_api.closePort(serial_port_name);

    return success;
}


bool enableDaqpSimulation(ModulesApi& dw_api, const std::string& serial_port_name)
{
    ModulesSimPtr sim;
    bool success = false;

    sim = dw_api.getModelSim().lock();
    sim->setCommandDelay(0);  // set to FAST
    sim->addSerialPort(serial_port_name);
    success = sim->addModule("DAQP-STG", serial_port_name, 0);

    dw_api.enableSimulation(true);

    return success;
}


void printModuleProperties(IfModulePtr module)
{
    bool success = false;
    printf("Module:   %s  (ID:%X)\n", module->getModuleName().c_str(), module->getModuleID());
    printf("Type:     %s\n", module->getModuleTypename().c_str());

    // queries directly into the modules XML representation is possible:
    std::string fw_ver;
    success = module->getParamStr("CurrProp", "FirmwareVersion", fw_ver);
    printf("Firmware: %s\n", fw_ver.c_str());

    std::string serial;
    success = module->getParamStr("CurrProp", "SerialNumber", serial);
    printf("Serial:   %s\n",serial.c_str());

#ifdef VERBOSE
    // all XML Properties
    // list all supported modes and print their child properties
    std::string all_prop;
    success = module->getParamStr("AllProp", "Module", all_prop);
    printf("ALL XML: %s\n", xpugi::xmlPrettyPrint(all_prop).c_str());
#endif

    // current XML Properties
    // list the current active mode and print the current child settings
    std::string curr_prop;
    success = module->getParamStr("CurrProp", "Module", curr_prop);
    printf("Current XML: %s\n", xpugi::xmlPrettyPrint(curr_prop).c_str());
}

void printModes(IfModulePtr module)
{
    bool success = false;

    std::string modes_as_string;
    success = module->getParamStr("AvailProp", "Channel[1]/Mode", modes_as_string);
    printf("Modes:   %s\n", modes_as_string.c_str());

    // XML query not supported for mode list
    // std::string modes_as_xml;
    // success = module->getParamXML("AvailProp", "Channel[1]/Mode", modes_as_xml);
    // printf("modes(xml): %s\n", xpugi::xmlPrettyPrint(modes_as_xml).c_str());
}

void printCurrentSettings(IfModulePtr module)
{
    bool success = false;
    // current XML Properties
    // list the current active mode and print the current child settings
    std::string curr_prop;
    success = module->getParamStr("CurrProp", "Module", curr_prop);
#ifdef VERBOSE
    printf("Current XML: %s\n", xpugi::xmlPrettyPrint(curr_prop).c_str());
#endif
}

void setVoltageMode(IfModulePtr module)
{
    bool success = false;
    std::string mode;

    printf("setVoltageMode\n");

    // set voltage mode
    success = module->setParamStr("CurrProp", "Channel[1]/Mode", "Voltage");
    // verify mode
    success = module->getParamStr("CurrProp", "Channel[1]/Mode", mode);
    assert(mode == "Voltage");

    // print settings
    printCurrentSettings(module);

    // query available ranges
    std::string ranges_xml;
    success = module->getParamXML("AvailProp", "Channel[1]/Mode/Range", ranges_xml);
#ifdef VERBOSE
    printf("Ranges(xml): %s\n", xpugi::xmlPrettyPrint(ranges_xml).c_str());
#endif

    std::string ranges_list;
    success = module->getParamStr("AvailProp", "Channel[1]/Mode/Range", ranges_list);
    printf("Ranges %s\n", ranges_list.c_str());

    // set range
    success = module->setParamStr("CurrProp", "Channel[1]/Mode/Range", "0.5V");
    std::string current_range;
    success = module->getParamStr("CurrProp", "Channel[1]/Mode/Range", current_range);
    assert(current_range == "0.5V");

    // set low pass filter Butterworth
    std::string lp_filter_type;
    std::string lp_filter_val;
    success = module->setParamStr("CurrProp", "Channel[1]/Mode/LPFilter/LPFilter_Type", "Butterworth");
    success = module->setParamStr("CurrProp", "Channel[1]/Mode/LPFilter/LPFilter_Val", "10000Hz");
    // verify
    success = module->getParamStr("CurrProp", "Channel[1]/Mode/LPFilter/LPFilter_Type", lp_filter_type);
    success = module->getParamStr("CurrProp", "Channel[1]/Mode/LPFilter/LPFilter_Val", lp_filter_val);

    assert(lp_filter_type == "Butterworth");
    assert(lp_filter_val == "10000Hz");

    // set low pass filter Bessel
    success = module->setParamStr("CurrProp", "Channel[1]/Mode/LPFilter/LPFilter_Type", "Bessel");
    success = module->setParamStr("CurrProp", "Channel[1]/Mode/LPFilter/LPFilter_Val", "3000Hz");
    // verify
    success = module->getParamStr("CurrProp", "Channel[1]/Mode/LPFilter/LPFilter_Type", lp_filter_type);
    success = module->getParamStr("CurrProp", "Channel[1]/Mode/LPFilter/LPFilter_Val", lp_filter_val);

    assert(lp_filter_type == "Bessel");
    assert(lp_filter_val == "3000Hz");

    // Voltage excitation
    std::string exc_type;
    std::string exc_v;
    success = module->setParamStr("CurrProp", "Channel[1]/Mode/Excitation/Excitation_Type", "Voltage");
    success = module->setParamStr("CurrProp", "Channel[1]/Mode/Excitation/Excitation_Val", "1V");
    // verify
    success = module->getParamStr("CurrProp", "Channel[1]/Mode/Excitation/Excitation_Type", exc_type);
    success = module->getParamStr("CurrProp", "Channel[1]/Mode/Excitation/Excitation_Val", exc_v);

    assert(exc_type == "Voltage");
    assert(exc_v == "1V");

    // Current excitation
    success = module->setParamStr("CurrProp", "Channel[1]/Mode/Excitation/Excitation_Type", "Current");
    success = module->setParamStr("CurrProp", "Channel[1]/Mode/Excitation/Excitation_Val", "1mA");
    // verify
    success = module->getParamStr("CurrProp", "Channel[1]/Mode/Excitation/Excitation_Type", exc_type);
    success = module->getParamStr("CurrProp", "Channel[1]/Mode/Excitation/Excitation_Val", exc_v);

    assert(exc_type == "Current");
    assert(exc_v == "1mA");

    // Input Type
    std::string input_type;
    success = module->getParamStr("CurrProp", "Channel[1]/Mode/InputType", input_type);
    assert(input_type =="Voltage");

    // apply settings to the module
    success = module->applyParam();

    // Actions
    std::string possible_actions;
    success = module->getParamStr("AvailProp", "Channel[1]/Mode/Actions", possible_actions);

    // Amplifier balance action
    success = module->setParamStr("CurrProp", "Channel[1]/Mode/Actions", "AmplifierBalance");

}

void setBridgeMode(IfModulePtr module)
{
    bool success = false;
    std::string mode;

    printf("setBridgeMode\n");

    // set bridge mode
    success = module->setParamStr("CurrProp", "Channel[1]/Mode", "Bridge");
    // verify mode
    success = module->getParamStr("CurrProp", "Channel[1]/Mode", mode);
    assert(mode == "Bridge");

    // print settings
    printCurrentSettings(module);

    std::string ranges_xml;
    success = module->getParamXML("AvailProp", "Channel[1]/Mode/Range", ranges_xml);
#ifdef VERBOSE
    printf("Ranges(xml): %s\n", xpugi::xmlPrettyPrint(ranges_xml).c_str());
#endif

    std::string ranges_list;
    success = module->getParamStr("AvailProp", "Channel[1]/Mode/Range", ranges_list);
    printf("Ranges %s\n", ranges_list.c_str());

    //
    // Attention: ranges depend on excitation (range and type)!
    //

    // set range
    success = module->setParamStr("CurrProp", "Channel[1]/Mode/Excitation/Excitation_Type", "Voltage");
    success = module->setParamStr("CurrProp", "Channel[1]/Mode/Excitation/Excitation_Val", "5V");

    success = module->getParamStr("AvailProp", "Channel[1]/Mode/Range", ranges_list);
    printf("Ranges for 5V excitation: %s\n", ranges_list.c_str());

    success = module->setParamStr("CurrProp", "Channel[1]/Mode/Range", "100mV/V");
    std::string current_range;
    success = module->getParamStr("CurrProp", "Channel[1]/Mode/Range", current_range);
    assert(current_range == "100mV/V");

    // change excitation 5V -> 1V: Get new ranges!
    success = module->setParamStr("CurrProp", "Channel[1]/Mode/Excitation/Excitation_Val", "1V");

    success = module->getParamStr("AvailProp", "Channel[1]/Mode/Range", ranges_list);
    printf("Ranges for 1V excitation: %s\n", ranges_list.c_str());

    // current set range changes too!
    success = module->getParamStr("CurrProp", "Channel[1]/Mode/Range", current_range);
    assert(current_range == "500mV/V");


    // shunt
    std::string shunt_options;
    success = module->getParamStr("AvailProp", "Channel[1]/Mode/Shunt", shunt_options);
    printf("Shunts %s\n", shunt_options.c_str());

    std::string shunt;
    success = module->setParamStr("CurrProp", "Channel[1]/Mode/Shunt", "On");
    success = module->getParamStr("CurrProp", "Channel[1]/Mode/Shunt", shunt);
    assert(shunt == "On");
    success = module->setParamStr("CurrProp", "Channel[1]/Mode/Shunt", "Off");
    success = module->getParamStr("CurrProp", "Channel[1]/Mode/Shunt", shunt);
    assert(shunt == "Off");
    

    // Voltage excitation
    std::string exc_type;
    std::string exc_v;
    success = module->setParamStr("CurrProp", "Channel[1]/Mode/Excitation/Excitation_Type", "Voltage");
    success = module->setParamStr("CurrProp", "Channel[1]/Mode/Excitation/Excitation_Val", "1V");
    // verify
    success = module->getParamStr("CurrProp", "Channel[1]/Mode/Excitation/Excitation_Type", exc_type);
    success = module->getParamStr("CurrProp", "Channel[1]/Mode/Excitation/Excitation_Val", exc_v);

    assert(exc_type == "Voltage");
    assert(exc_v == "1V");

    // Current excitation
    success = module->setParamStr("CurrProp", "Channel[1]/Mode/Excitation/Excitation_Type", "Current");
    success = module->setParamStr("CurrProp", "Channel[1]/Mode/Excitation/Excitation_Val", "1mA");
    // verify
    success = module->getParamStr("CurrProp", "Channel[1]/Mode/Excitation/Excitation_Type", exc_type);
    success = module->getParamStr("CurrProp", "Channel[1]/Mode/Excitation/Excitation_Val", exc_v);

    assert(exc_type == "Current");
    assert(exc_v == "1mA");

    success = module->getParamStr("AvailProp", "Channel[1]/Mode/Range", ranges_list);
    printf("Ranges for 1mA excitation: %s\n", ranges_list.c_str());

    success = module->setParamStr("CurrProp", "Channel[1]/Mode/Excitation/Excitation_Val", "5mA");

    success = module->getParamStr("AvailProp", "Channel[1]/Mode/Range", ranges_list);
    printf("Ranges for 5mA excitation: %s\n", ranges_list.c_str());


    // set low pass filter
    std::string lp_filter_type;
    std::string lp_filter_val;
    success = module->setParamStr("CurrProp", "Channel[1]/Mode/LPFilter/LPFilter_Type", "Butterworth");
    success = module->setParamStr("CurrProp", "Channel[1]/Mode/LPFilter/LPFilter_Val", "10000Hz");
    // verify
    success = module->getParamStr("CurrProp", "Channel[1]/Mode/LPFilter/LPFilter_Type", lp_filter_type);
    success = module->getParamStr("CurrProp", "Channel[1]/Mode/LPFilter/LPFilter_Val", lp_filter_val);

    assert(lp_filter_type == "Butterworth");
    assert(lp_filter_val == "10000Hz");

    // set low pass filter Bessel
    success = module->setParamStr("CurrProp", "Channel[1]/Mode/LPFilter/LPFilter_Type", "Bessel");
    success = module->setParamStr("CurrProp", "Channel[1]/Mode/LPFilter/LPFilter_Val", "3000Hz");
    // verify
    success = module->getParamStr("CurrProp", "Channel[1]/Mode/LPFilter/LPFilter_Type", lp_filter_type);
    success = module->getParamStr("CurrProp", "Channel[1]/Mode/LPFilter/LPFilter_Val", lp_filter_val);

    assert(lp_filter_type == "Bessel");
    assert(lp_filter_val == "3000Hz");

    // Input Type
    std::string input_type;
    success = module->setParamStr("CurrProp", "Channel[1]/Mode/InputType", "BRFULL");
    success = module->getParamStr("CurrProp", "Channel[1]/Mode/InputType", input_type);
    assert(input_type == "BRFULL");

    success = module->setParamStr("CurrProp", "Channel[1]/Mode/InputType", "BRHALF");
    success = module->getParamStr("CurrProp", "Channel[1]/Mode/InputType", input_type);
    assert(input_type == "BRHALF");

    success = module->setParamStr("CurrProp", "Channel[1]/Mode/InputType", "BRQUARTER3W");
    success = module->getParamStr("CurrProp", "Channel[1]/Mode/InputType", input_type);
    assert(input_type == "BRQUARTER3W");

    success = module->setParamStr("CurrProp", "Channel[1]/Mode/InputType", "BRQUARTER4W");
    success = module->getParamStr("CurrProp", "Channel[1]/Mode/InputType", input_type);
    assert(input_type == "BRQUARTER4W");

    // Bridge Resistance
    std::string bridge_res;
    success = module->setParamStr("CurrProp", "Channel[1]/Mode/InputType", "BRQUARTER3W");
    
    success = module->setParamStr("CurrProp", "Channel[1]/Mode/BridgeResistance", "120Ohm");
    success = module->getParamStr("CurrProp", "Channel[1]/Mode/BridgeResistance", bridge_res);
    assert(bridge_res == "120Ohm");

    success = module->setParamStr("CurrProp", "Channel[1]/Mode/BridgeResistance", "350Ohm");
    success = module->getParamStr("CurrProp", "Channel[1]/Mode/BridgeResistance", bridge_res);
    assert(bridge_res == "350Ohm");

    success = module->setParamStr("CurrProp", "Channel[1]/Mode/InputType", "BRQUARTER4W");

    success = module->setParamStr("CurrProp", "Channel[1]/Mode/BridgeResistance", "120Ohm");
    success = module->getParamStr("CurrProp", "Channel[1]/Mode/BridgeResistance", bridge_res);
    assert(bridge_res == "120Ohm");

    success = module->setParamStr("CurrProp", "Channel[1]/Mode/BridgeResistance", "350Ohm");
    success = module->getParamStr("CurrProp", "Channel[1]/Mode/BridgeResistance", bridge_res);
    assert(bridge_res == "350Ohm");

    // Short
    std::string short_circuit;
    success = module->setParamStr("CurrProp", "Channel[1]/Mode/Short", "Off");
    success = module->getParamStr("CurrProp", "Channel[1]/Mode/Short", short_circuit);
    assert(short_circuit == "Off");

    // InputOffsetRange
    std::string input_off_range;
    success = module->getParamStr("CurrProp", "Channel[1]/Mode/InputOffsetRange", input_off_range);


    // apply settings to the module
    success = module->applyParam();

    // Actions
    std::string possible_actions;
    success = module->getParamStr("AvailProp", "Channel[1]/Mode/Actions", possible_actions);

    // Sensor balance action
    success = module->setParamStr("CurrProp", "Channel[1]/Mode/Actions", "SensorBalance");
    success = module->setParamStr("CurrProp", "Channel[1]/Mode/Actions", "ReadSensorOffsetAdjustment");

    // read input offset
    std::string offset;
    success = module->getParamStr("CurrProp", "Channel[1]/Mode/InputOffset", offset);

    // write sensor offset back
    success = module->setParamStr("CurrProp", "Channel[1]/Mode/Actions", "WriteSensorOffsetAdjustment");
}

void setResistenceMode(IfModulePtr module)
{
    bool success = false;
    std::string mode;

    printf("setResistenceMode\n");

    // set resistence mode
    success = module->setParamStr("CurrProp", "Channel[1]/Mode", "Resistance");
    // verify mode
    success = module->getParamStr("CurrProp", "Channel[1]/Mode", mode);
    assert(mode == "Resistance");

    // print settings
    printCurrentSettings(module);

    std::string ranges_xml;
    success = module->getParamXML("AvailProp", "Channel[1]/Mode/Range", ranges_xml);
#ifdef VERBOSE
    printf("Ranges(xml): %s\n", xpugi::xmlPrettyPrint(ranges_xml).c_str());
#endif

    std::string ranges_list;
    success = module->getParamStr("AvailProp", "Channel[1]/Mode/Range", ranges_list);
    printf("Ranges %s\n", ranges_list.c_str());

    // set range
    success = module->setParamStr("CurrProp", "Channel[1]/Mode/Range", "250Ohm");
    std::string current_range;
    success = module->getParamStr("CurrProp", "Channel[1]/Mode/Range", current_range);
    assert(current_range == "250Ohm");


    // apply settings to the module
    success = module->applyParam();
}
