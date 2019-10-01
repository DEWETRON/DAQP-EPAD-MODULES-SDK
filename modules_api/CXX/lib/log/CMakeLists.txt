#
# log wrapper library
#

set(LIBNAME log)

set(LOG_HEADER_FILES
    inc/uni_log.h
    inc/uni_logger.h
)
source_group("Log Header Files" FILES ${LOG_HEADER_FILES})

set(LOG_SOURCE_FILES
    src/uni_log.cpp
)
source_group("Log Source Files" FILES ${LOG_SOURCE_FILES})


add_library(${LIBNAME}
    ${LOG_HEADER_FILES}
    ${LOG_SOURCE_FILES}
)

target_include_directories(${LIBNAME}
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

set_target_properties(${LIBNAME} PROPERTIES FOLDER "log")
