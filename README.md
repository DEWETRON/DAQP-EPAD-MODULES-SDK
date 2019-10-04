# DAQP-EPAD-MODULES-SDK
DEWETRON DAQP-EPAD-MODULES SDK. API description and example sources. 


# Prerequisites
To use the DEWETRON DAQP-EPAD SDK you need a current DW_MODULES API installation.
The DW_MODULES Application installer is available on DEWETRON's customer care center:

DAQP-EPAD-MODULES-API Installer:
https://ccc.dewetron.com/pl/sdk


# Documentation

The docs directory contains a pdf version of the low level programmming manual.

This projets wiki pasge https://github.com/DEWETRON/DAQP-EPAD-MODULES-SDK/wiki

explains how to use DEWETRON DAQP and EPAD modules using this SDK.


# Directory structure

## cmake

Common cmake settings.

## docs

Contains documentation like daqp_hsi_pad_modules_progref_228ex.pdf. 

## modules_api

This directory contains language bindings for C and C++.
Additionally CXX contains util and serial port source interfaces.

## daqp

This directory contains examples directly accessing DAQP modules.

## epad

This directory contains examples directly measuring using EPAD modules.

## ext

This directory contains examples explaining how to extend the modules API.
For instance how to support a custom RS232 or RS485 port.

Ext features need dw_modules_api.dll R1.1.0 to work.

# Compiler

This project successfully builds using:
* Visual Studio 2019
* Visual Studio 2017 (+ boost?)
* Visual Studio 2013 + boost

* GCC 8+


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


# Contact

**Company information**

[www.dewetron.com](https://www.dewetron.com)

**For general questions please contact:**

support@dewetron.com


**For technical questions please contact:**

Michael Oberhofer 

michael.oberhofer@dewetron.com

Gunther Laure

gunther.laure@dewetron.com


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