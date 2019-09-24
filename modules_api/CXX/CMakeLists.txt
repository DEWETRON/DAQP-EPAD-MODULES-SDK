#
# dw_modules_api
# Userland CXX
#

set(LIBNAME_CXX dw_modules_api_cxx)

#
# Force C++17
set(CMAKE_CXX_STANDARD 17)


include_directories(
  SYSTEM
)

include_directories(
  inc
  src
  util/inc
  serial_port/inc
)

#
# User C++ interface
set(DW_CXX_API_HEADER_FILES
  inc/dw_if_module_cxx.h
  inc/dw_modules_api_cxx.h
  inc/dw_modules_sim_cxx.h
  inc/dw_module_name_tupel.h 
)
source_group("C++ Header Files" FILES ${DW_CXX_API_HEADER_FILES})

set(DW_CXX_API_SOURCE_FILES
  src/dw_module_cxx.h
  src/dw_module_cxx.cpp
  src/dw_modules_api_cxx.cpp
  src/dw_modules_sim_cxx.cpp
  src/dw_module_name_tupel.cpp
)
source_group("C++ Source Files" FILES ${DW_CXX_API_SOURCE_FILES})

set(DW_CXX_PRIVATE_API_HEADER_FILES
  src/dw_if_module_cxx.h
  src/dw_module_ids.h
)
source_group("C++ Header Files" FILES ${DW_CXX_API_HEADER_FILES})


set(SP_HEADER_FILES
  serial_port/inc/sp_if_serial_port.h
  serial_port/inc/sp_if_serial_port_fwd.h
  serial_port/inc/sp_serial_port_native.h
  serial_port/inc/sp_serial_port_unix.h
  serial_port/inc/sp_serial_port_windows.h
  serial_port/inc/sp_serial_port_enum.h
  serial_port/inc/sp_serial_port_util.h
)
source_group("SP Header Files" FILES ${SP_HEADER_FILES})


if(WIN32)
  set(SP_SOURCE_FILES
    ${SP_SOURCE_FILES}
    serial_port/src/sp_serial_port_enum_win32.cpp
    serial_port/src/sp_serial_port_util.cpp
    serial_port/src/sp_serial_port_windows.cpp
    )
else()
  set(SP_SOURCE_FILES
    ${SP_SOURCE_FILES}
    serial_port/src/sp_serial_port_enum_unix.cpp
    serial_port/src/sp_serial_port_unix.cpp
    serial_port/src/sp_serial_port_util.cpp
    )

  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
endif()


set(UTIL_HEADER_FILES
  util/inc/uni_log.h
)
source_group("util Header Files" FILES ${UTIL_HEADER_FILES})

set(UTIL_SOURCE_FILES
  util/src/uni_log.cpp
)
source_group("Util Source Files" FILES ${UTIL_SOURCE_FILES})


add_library(${LIBNAME_CXX}
  ${DW_CXX_API_HEADER_FILES}
  ${DW_CXX_API_SOURCE_FILES}
  ${SP_HEADER_FILES}
  ${SP_SOURCE_FILES}
  ${UTIL_HEADER_FILES}
  ${UTIL_SOURCE_FILES}
)

target_link_libraries(${LIBNAME_CXX}
  modules_api_inc
)

if (UNIX)
  target_link_libraries(${LIBNAME_CXX}
    stdc++fs
  )
endif()

set_property(TARGET ${LIBNAME_CXX}
  APPEND PROPERTY COMPILE_DEFINITIONS
  DEWE_MODULES_NS
)

target_include_directories(${LIBNAME_CXX}
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/serial_port/inc
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/util/inc
)

set_target_properties(${LIBNAME_CXX} PROPERTIES FOLDER "api/dw_modules_api")
