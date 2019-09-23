# DAQP-EPAD-MODULES-SDK
DEWETRON DAQP-EPAD-MODULES SDK. API description and example sources. 


# Prerequisites
To use the DEWETRON DAQP-EPAD SDK you need a current DW_MODULES API installation.
The DW_MODULES Application installer is available on DEWETRON's customer care center:

https://ccc.dewetron.com



# Directory structure

## modules_api

This directory contains language bindings for C and C++.
Additionally CXX contains util and serial port source interfaces.

## daqp

This directory contains examples directly accessing DAQP modules.



# Building the examples

## Examples in C 
Building the C examples require CMAKE (https://cmake.org/).
```cmd
cd daqp\C
mkdir build
cd build
```
For a Visual Studio 2019 run:
```cmd
cmake -G "Visual Studio 16 2019" ..
```
Other generators are listed when calling "cmake -G"

Open the generated solution:
```cmd
start DAQP_SDK_C.sln
```

## Examples in C++
Building the C++ examples also require CMAKE (https://cmake.org/).
```cmd
cd daqp\CXX
mkdir build
cd build
```
For a Visual Studio 2019 run:
```cmd
cmake -G "Visual Studio 16 2019" ..
```
Other generators are listed when calling "cmake -G"

Open the generated solution:
```cmd
start DAQP_SDK_CXX.sln
```

# License
MIT License

Copyright (c) 2018 DEWETRON

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
LICENSE (END)