#
# serial port interface library
#

set(LIBNAME sp_serial_port)

set(SP_HEADER_FILES
    inc/sp_if_serial_port_fwd.h
    inc/sp_if_serial_port.h
    inc/sp_serial_port_enum.h
    inc/sp_serial_port_native.h
    inc/sp_serial_port_unix.h
    inc/sp_serial_port_util.h
    inc/sp_serial_port_windows.h
)
source_group("SP Header Files" FILES ${SP_HEADER_FILES})

if(WIN32)
  set(SP_SOURCE_FILES
    ${SP_SOURCE_FILES}
    src/sp_serial_port_enum_win32.cpp
    src/sp_serial_port_util.cpp
    src/sp_serial_port_windows.cpp
    )
else()
  set(SP_SOURCE_FILES
    ${SP_SOURCE_FILES}
    src/sp_serial_port_enum_unix.cpp
    src/sp_serial_port_unix.cpp
    src/sp_serial_port_util.cpp
    )

  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
endif()
source_group("SP Source Files" FILES ${SP_SOURCE_FILES})

add_library(${LIBNAME}
    ${SP_HEADER_FILES}
    ${SP_SOURCE_FILES}
)

target_link_libraries(${LIBNAME}
	uni_base
	log
)

target_include_directories(${LIBNAME}
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

set_target_properties(${LIBNAME} PROPERTIES FOLDER "sp_serial_port")
