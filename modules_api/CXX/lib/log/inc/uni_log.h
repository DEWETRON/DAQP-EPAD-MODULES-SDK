// Copyright DEWETRON GmbH 2019
#pragma once


#define LOG_DISABLED
#ifdef LOG_DISABLED

// Empty logger
#define LOG_GROUP_DECLARE(LG)
#define LOG_GROUP_DEFINE(LG)

#define UNILOG_ERROR(LG, logdata)



#else

// TODO implement real logger

#endif



//LOG_GROUP_DECLARE(serial_port)


