#
# dw_modules_api
# Userland CXX
#

set(LIBNAME_CXX dw_modules_api_cxx)


#
# Enable target folders in IDEs
set_property(GLOBAL
  PROPERTY USE_FOLDERS ON)

#
# Speed up compile time
set(MSVC_BUILD_USING_MP TRUE)

#
# Select used libraries: one of following
if (NOT DEFINED USE_BOOST)
  set(USE_BOOST FALSE)
  set(USE_CXX17 TRUE)
endif()

if (USE_CXX17)
  #
  # Force C++17
  # needed for filesystem, shared_mutex
  set(CMAKE_CXX_STANDARD 17)
endif()


#
# Check for 64 bit build
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  set(BUILD_X64 TRUE)
  set(BUILD_X86 FALSE)
else()
  set(BUILD_X64 FALSE)
  set(BUILD_X86 TRUE)
endif()


if(BUILD_X64)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DBUILD_X64")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DBUILD_X64")
elseif (BUILD_X86)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DBUILD_X86")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DBUILD_X86")
endif()


include_directories(
  SYSTEM
)

include_directories(
  inc
  src
)

#
# add utility libraries
if (NOT TARGET uni_base)
  add_subdirectory(lib/uni_base uni_base)
endif()

if (NOT TARGET sp_serial_port)
  add_subdirectory(lib/serial_port sp_serial_port)
endif()

if (NOT TARGET log)
  add_subdirectory(lib/log log)
endif()

# C interface
if (NOT TARGET modules_api_inc_c)
  add_subdirectory(../C modules_api_inc_c)
endif()


#
# C++ interface
set(DW_CXX_API_HEADER_FILES
  inc/dw_if_module_cxx.h
  inc/dw_modules_api_cxx.h
  inc/dw_modules_sim_cxx.h
  inc/dw_module_name_tupel.h 
  inc/dw_module_cxx.h
)
source_group("C++ Header Files" FILES ${DW_CXX_API_HEADER_FILES})

set(DW_CXX_API_SOURCE_FILES
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

add_library(${LIBNAME_CXX}
  ${DW_CXX_API_HEADER_FILES}
  ${DW_CXX_API_SOURCE_FILES}
)

if (USE_CXX17)
  set_property(TARGET ${LIBNAME_CXX}
    APPEND PROPERTY COMPILE_DEFINITIONS
    USE_CXX17
  )
endif()

if (USE_BOOST)
  set_property(TARGET ${LIBNAME_CXX}
    APPEND PROPERTY COMPILE_DEFINITIONS
    USE_BOOST
  )
endif()

target_link_libraries(${LIBNAME_CXX}
  uni_base
  modules_api_inc_c
  sp_serial_port
  log
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
)

set_target_properties(${LIBNAME_CXX} PROPERTIES FOLDER "api/dw_modules_api")
