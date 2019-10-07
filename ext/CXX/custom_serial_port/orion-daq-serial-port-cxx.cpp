// Copyright (c) Dewetron 2019

#include "dw_modules_api_cxx.h"
#include "sp_if_serial_port.h"
#include <assert.h>
#include <string>
#include "stdio.h"
#include "orion_daq_serial_port.h"


using namespace dwcxx;



int main(int argc, char* argv[])
{
    int success = 0;
    unsigned int board_id = 0;
    std::string serial_port_name = "ORION_0";
    OrionDAQSerialPort my_serial_port(board_id, serial_port_name);

    // TODO 
    // Add code to configure ORION DAQ board + RS485

    // Instantiate the api
    ModulesApi  dw_api;

    // The api has to be initalized
    success = dw_api.init();

    // Register a custom serial port "MySerialPort"
    success = dw_api.addSerialPort(&my_serial_port);

    // Open serial port
    success = dw_api.openPort(serial_port_name);
    
    // Scan the custom registered port
    success = dw_api.scanAddress(serial_port_name, 0);

    // Close serial port
    success = dw_api.closePort(serial_port_name);

    return success;
}