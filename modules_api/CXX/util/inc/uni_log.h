// Copyright DEWETRON GmbH 2019

#ifndef _SP_SERIAL_PORT__LOG_H_
#define _SP_SERIAL_PORT__LOG_H_
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


#endif //_SP_SERIAL_PORT__LOG_H_