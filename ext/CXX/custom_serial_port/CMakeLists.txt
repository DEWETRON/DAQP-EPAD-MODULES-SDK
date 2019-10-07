#
# Project DEWETRON DAQP EPAD SDK C++ - custom serial port examples
#

add_executable(custom-serial-port-cxx
    custom-serial-port-cxx.cpp
  )
SampleBuildSettings(custom-serial-port-cxx "ext/custom-serial-port-cxx")


if (WIN32)

  include_directories(../../orion_daq)

  add_executable(orion-daq-serial-port-cxx      
      orion-daq-serial-port-cxx.cpp
      orion_daq_serial_port.h
      ../../orion_daq/OrionDaq_api.h
      ../../orion_daq/OrionDaq_api.c
    )
  SampleBuildSettings(orion-daq-serial-port-cxx "ext/orion-daq-serial-port-cxx")

  include_directories(../../orion_dsa)

  add_executable(orion-dsa-serial-port-cxx
      orion-dsa-serial-port-cxx.cpp
      orion_dsa_serial_port.h
      ../../orion_dsa/OrionDsa_api.h
      ../../orion_dsa/OrionDsa_api.c
    )
  SampleBuildSettings(orion-dsa-serial-port-cxx "ext/orion-dsa-serial-port-cxx")

endif()