// Copyright (c) Dewetron 2019

#include "dw_modules_api_cxx.h"
#include "sp_serial_port_util.h"
#include "xpugixml.h"
#include <assert.h>
#include "stdio.h"


//#define VERBOSE

using namespace dwcxx;

bool enableSimulation(ModulesApi& dw_api, const std::string& serial_port_name);
void printModuleProperties(IfModulePtr module);
void printModes(IfModulePtr module);
void printCurrentSettings(IfModulePtr module);
void measure(IfModulePtr module, int num_channels);

int main(int argc, char* argv[])
{
    int success = 0;
    std::string serial_port_name = "COM1";
    int num_channels = 0;
      
    // Instantiate the api
    ModulesApi  dw_api;

    // The api has to be initalized
    success = dw_api.init();

    // Enable simulation, configure a DAQP-STG @ address 0
    success = enableSimulation(dw_api, serial_port_name);

    // Open serial port
    dw_api.openPort(serial_port_name);

    // Scan for module
    int num_modules = dw_api.scanAddress(serial_port_name, 0);
    printf("Found %d modules\n", num_modules);

    // access the amplifier module
    IfModuleWPtr module_wp = dw_api.getModule(serial_port_name, 0);
    if (auto module = module_wp.lock())
    {
        // Get number of channels
        std::string str_num_channels;
        module->getParamStr("CurrProp", "count(ChannelProperties/Channel)", str_num_channels);
        num_channels = std::stoi(str_num_channels);


        printModuleProperties(module);
        printModes(module);

        // get a sample from each channel
        measure(module, num_channels);
    }

    // Close serial port
    dw_api.closePort(serial_port_name);

    return success;
}


bool enableSimulation(ModulesApi& dw_api, const std::string& serial_port_name)
{
    ModulesSimPtr sim;
    bool success = false;

    sim = dw_api.getModelSim().lock();
    sim->setCommandDelay(0);  // set to FAST
    sim->addSerialPort(serial_port_name);

    success = sim->addModule("EPAD2-TH8", serial_port_name, 0);

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

void measure(IfModulePtr module, int num_channels)
{
    auto sample_vec = IfModule::SampleValueVec();
    module->getSamples(sample_vec, num_channels);

    int ch_idx = 1;
    for (auto ch = sample_vec.begin(); ch != sample_vec.end(); ++ch, ++ch_idx)
    {
        printf("Channel %d:  %f\n", ch_idx, *ch);
    }
}