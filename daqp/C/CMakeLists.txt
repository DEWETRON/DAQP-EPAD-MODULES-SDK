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
# Configure part start

# 
include(${DAQP_SDK_ROOT}/cmake/CMakeSettings.cmake)


# Common build settings
SetCommonOutputDirectory()


# Add C language bindings
if (EXISTS ${DAQP_SDK_ROOT}/modules_api/C/CMakeLists.txt)
  if (NOT TARGET modules_api_inc_c)
    add_subdirectory(${DAQP_SDK_ROOT}/modules_api/C modules_api_inc_c)
  endif()
else()
  message(status "${DAQP_SDK_ROOT}/modules_api/C not found")
endif()


macro(SampleBuildSettings SAMPLE FOLDER)
  set_target_properties(${SAMPLE} PROPERTIES FOLDER ${FOLDER})
  target_link_libraries(${SAMPLE}
    modules_api_inc_c
    )
  if(UNIX)
    target_link_libraries(${SAMPLE}
      dl
      pthread
      )
  endif()
endmacro()


add_subdirectory(daqp-stg)
