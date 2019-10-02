#
# Project DEWETRON DAQP EPAD SDK import project
#
cmake_minimum_required(VERSION 3.8)

set(LIBNAME modules_api_inc_c)

set(API_HEADER_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/public/dw_modules_c_command.h
  ${CMAKE_CURRENT_SOURCE_DIR}/public/dw_modules_c_core.h
  ${CMAKE_CURRENT_SOURCE_DIR}/public/dw_modules_c_error.h
  ${CMAKE_CURRENT_SOURCE_DIR}/public/dw_modules_exports.h
  ${CMAKE_CURRENT_SOURCE_DIR}/public/dw_modules_load.h
)

source_group("C Header Files" FILES ${API_HEADER_FILES})


add_library(${LIBNAME} INTERFACE)

#  adding source files to the import library adds those file to every dependent (direct or derived) project
#  => we do not want that
#  target_sources(${LIBNAME} INTERFACE
#    ${API_HEADER_FILES}
#  )


target_include_directories(${LIBNAME}
  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/public
  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)

