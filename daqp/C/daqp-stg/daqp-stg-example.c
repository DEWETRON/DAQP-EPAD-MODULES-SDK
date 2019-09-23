// Copyright (c) Dewetron 2019
#include "dw_modules_load.h"


int main(int argc, char* argv[])
{
    int error = 0;

    error = DeWeModulesLoad();

    error = DeWeInit();

    error = DeWeDeInit();

    DeWeModulesUnload();
    return error;
}

