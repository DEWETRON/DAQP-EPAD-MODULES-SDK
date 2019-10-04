#
# Project DEWETRON DAQP SDK
#
cmake_minimum_required(VERSION 3.8)

#
# studio project name
project(EPAD_SDK_CXX CXX)

#
# common settings
get_filename_component(EPAD_SDK_ROOT ../.. ABSOLUTE)

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
include(${EPAD_SDK_ROOT}/cmake/CMakeSettings.cmake)


# Common build settings
SetCommonOutputDirectory()


# Add C language bindings
if (EXISTS ${EPAD_SDK_ROOT}/modules_api/C/CMakeLists.txt)
  if (NOT TARGET modules_api_inc_c)
    add_subdirectory(${EPAD_SDK_ROOT}/modules_api/C modules_api_inc_c)
  endif()
else()
  message(status "${EPAD_SDK_ROOT}/modules_api/C not found")
endif()

# Add CXX language bindings and utility libraries
if (EXISTS ${EPAD_SDK_ROOT}/modules_api/CXX/CMakeLists.txt)
  if (NOT TARGET dw_modules_api_cxx)
    add_subdirectory(${EPAD_SDK_ROOT}/modules_api/CXX dw_modules_api_cxx)
  endif()
else()
  message(status "${EPAD_SDK_ROOT}/modules_api/CXX not found")
endif()

# Add XML processing library
if (NOT TARGET pugixml)
  add_subdirectory(${EPAD_SDK_ROOT}/3rdparty/pugixml-1.9 pugixml)
endif()

# Add XML processing utility library
if (NOT TARGET xpugixml)
  add_subdirectory(${EPAD_SDK_ROOT}/modules_api/CXX/lib/xpugixml xpugixml)
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


add_subdirectory(epad2-th8)
