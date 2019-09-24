// Copyright (c) Dewetron 2019

#include "dw_modules_api_cxx.h"
#include "sp_serial_port_util.h"

using namespace dwcxx;

int main(int argc, char* argv[])
{
    int error = 0;

    sp::SerialPortUtil sp;
    auto ports = sp.getPortNamesSorted();
      

    ModulesApi  dw_api;

    dw_api.init();

    return error;
}
