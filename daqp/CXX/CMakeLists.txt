#
# Project DEWETRON DAQP SDK
#
cmake_minimum_required(VERSION 3.8)

#
# studio project name
project(DAQP_SDK_CXX CXX)

#
# common settings
get_filename_component(DAQP_SDK_ROOT ../.. ABSOLUTE)

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
  if (NOT TARGET modules_api_inc_c)
    add_subdirectory(${DAQP_SDK_ROOT}/modules_api/C modules_api_inc_c)
  endif()
else()
  message(status "${DAQP_SDK_ROOT}/modules_api/C not found")
endif()


if (EXISTS ${DAQP_SDK_ROOT}/modules_api/CXX/CMakeLists.txt)
  if (NOT TARGET dw_modules_api_cxx)
    add_subdirectory(${DAQP_SDK_ROOT}/modules_api/CXX dw_modules_api_cxx)
  endif()
else()
  message(status "${DAQP_SDK_ROOT}/modules_api/CXX not found")
endif()

if (NOT TARGET pugixml)
  add_subdirectory(${DAQP_SDK_ROOT}/3rdparty/pugixml-1.9 pugixml)
endif()

if (NOT TARGET xpugixml)
  add_subdirectory(${DAQP_SDK_ROOT}/modules_api/CXX/lib/xpugixml xpugixml)
endif()


include_directories(
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
    modules_api_inc_c
    dw_modules_api_cxx
    xpugixml
    pugixml
    )
  if(UNIX)
    target_link_libraries(${SAMPLE}
      dl
      pthread
      )
  endif()
  if (USE_CXX17)
    set_property(TARGET ${SAMPLE}
      APPEND PROPERTY COMPILE_DEFINITIONS
      USE_CXX17
  )
  endif()
  if (USE_BOOST)
    set_property(TARGET ${SAMPLE}
      APPEND PROPERTY COMPILE_DEFINITIONS
      USE_BOOST
  )
  endif()

endmacro()


add_subdirectory(daqp-stg)
