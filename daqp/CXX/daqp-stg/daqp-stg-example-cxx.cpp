// Copyright (c) Dewetron 2019

#include "dw_modules_api_cxx.h"
#include "sp_serial_port_util.h"
#include "dw_modules_sim.h"

using namespace dwcxx;


bool enableDaqpSimulation(ModulesApi& dw_api);


int main(int argc, char* argv[])
{
    int error = 0;

    sp::SerialPortUtil sp;
    auto ports = sp.getPortNamesSorted();
      
    ModulesApi  dw_api;
    dw_api.init();

    enableDaqpSimulation(dw_api);

    return error;
}


bool enableDaqpSimulation(ModulesApi& dw_api)
{
    ModulesSimPtr sim;
    std::string serial_port = "COM1";
    bool success = false;

    sim = dw_api.getModelSim().lock();
    sim->setCommandDelay(0);  // set to FAST
    sim->addSerialPort(serial_port);
    success = sim->addModule("DAQP-STG", serial_port, 0);

    dw_api.enableSimulation(true);

    return success;
}