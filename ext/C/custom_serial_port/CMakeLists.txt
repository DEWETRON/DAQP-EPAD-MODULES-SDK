#
# Project DEWETRON DAQP EPAD SDK - custom serial port examples
#

add_executable(custom-serial-port
  custom-serial-port.c
  )
SampleBuildSettings(custom-serial-port "ext/custom-serial-port")

if (WIN32)

  include_directories(../../orion_daq)

  add_executable(orion-daq-serial-port
    orion-daq-serial-port.c
    ../../orion_daq/OrionDaq_api.h
    ../../orion_daq/OrionDaq_api.c
  )
  SampleBuildSettings(orion-daq-serial-port "ext/orion-daq-serial-port")

  include_directories(../../orion_dsa)

  add_executable(orion-dsa-serial-port
    orion-dsa-serial-port.c
    ../../orion_dsa/OrionDsa_api.h
    ../../orion_dsa/OrionDsa_api.c
  )
  SampleBuildSettings(orion-dsa-serial-port "ext/orion-dsa-serial-port")

endif()