// Copyright (c) Dewetron 2019

#include "dw_modules_api_cxx.h"
#include "sp_if_serial_port.h"
#include <assert.h>
#include "stdio.h"


using namespace dwcxx;


class MySerialPort : public sp::IfSerialPort
{
public:
    const char* SP_IMPORT getPortName() const override {
        return "SIM_SP1";
    }

    BOOL SP_IMPORT open() override {
        return true;
    }

    BOOL SP_IMPORT isOpen() const override {
        return true;
    }

    BOOL SP_IMPORT close() override {
        return true;
    }

    int32_t SP_IMPORT numBytesAvailable() const override {
        return 0;
    }

    BOOL SP_IMPORT read(BYTE* buf, size_t buf_size, uint32_t timeout, sp::ReadResult* read_result) override {
        assert(read_result != nullptr);
        *read_result = sp::ReadResult(sp::ReadResult::Timeout);
        return false;
    }

    BOOL SP_IMPORT write(BYTE* buf, std::size_t buf_size, uint32_t addr, uint32_t command_id) override {
        return true;
    }

    uint32_t SP_IMPORT getBaudRate() const override {
        return 9600;
    }
};


int main(int argc, char* argv[])
{
    int success = 0;
    std::string serial_port_name = "SIM_SP1";
    MySerialPort my_serial_port;

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