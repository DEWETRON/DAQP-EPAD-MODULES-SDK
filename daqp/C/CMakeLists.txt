#
# Project DEWETRON DAQP SDK
#
cmake_minimum_required(VERSION 3.8)

#
# studio project name
project(DAQP_SDK_C C)

#
# common settings
get_filename_component(DAQP_SDK_ROOT ../.. ABSOLUTE)

#
# Enable target folders in IDEs
set_property(GLOBAL
  PROPERTY USE_FOLDERS ON)

#
# Speed up compile time
set(MSVC_BUILD_USING_MP TRUE)

#
# Configure part start

#
# Check for 64 bit build
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  set(BUILD_X64 TRUE)
  set(BUILD_X86 FALSE)
else()
  set(BUILD_X64 FALSE)
  set(BUILD_X86 TRUE)
endif()


# Settings for GCC (UNIX)
if(UNIX)

  # set UNIX flag
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DUNIX")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DUNIX")

  if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-multichar -std=c++11 -Wno-unused-variable")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wmultichar -Wno-unused-variable")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-multichar -std=c++0x")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wmultichar")
  endif()


  if(BUILD_X64)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DBUILD_X64")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DBUILD_X64")
  elseif (BUILD_X86)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DBUILD_X86")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DBUILD_X86")
  endif()

  #
  # Allow function pointers to void* assignments
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

  #
  # Position Independent Code
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")

endif()


if (EXISTS ${DAQP_SDK_ROOT}/modules_api/C/CMakeLists.txt)
  if (NOT TARGET modules_api_inc)
    add_subdirectory(${DAQP_SDK_ROOT}/modules_api/C modules_api)
  endif()
else()
  message(status "${DAQP_SDK_ROOT}/modules_api/C not found")
endif()


include_directories(
  ${TRION_SDK_INCLUDE_DIR}
  ${TRIONET_SDK_INCLUDE_DIR}
  ${DAQP_SDK_ROOT}/trion_sdk_util/C/
)

if(MSVC)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
  
  if(BUILD_X64)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /DBUILD_X64")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /DBUILD_X64")
  elseif(BUILD_X86)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /DBUILD_X86")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /DBUILD_X86")
  endif()
  
endif()

macro(SampleBuildSettings SAMPLE FOLDER)
  set_target_properties(${SAMPLE} PROPERTIES FOLDER ${FOLDER})
  target_link_libraries(${SAMPLE}
    modules_api_inc
    )
  if(UNIX)
    target_link_libraries(${SAMPLE}
      dl
      pthread
      )
  endif()
endmacro()


add_subdirectory(daqp-stg)
