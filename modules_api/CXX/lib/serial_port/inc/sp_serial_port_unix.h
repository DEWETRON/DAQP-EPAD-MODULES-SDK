// Copyright DEWETRON GmbH 2015

#ifndef _SP_SERIAL_PORT_UNIX_H_
#define _SP_SERIAL_PORT_UNIX_H_
#pragma once

#include "sp_if_serial_port.h"

namespace sp
{
    class SerialPortUnix : public IfSerialPort
    {
        SerialPortUnix(const SerialPortUnix&) = delete;
        SerialPortUnix& operator=(const SerialPortUnix&) = delete;

    public:
        SerialPortUnix(const std::string& path, const SerialPortConfig& config);

        virtual const char* getPortName() const override { return m_path.c_str(); }
        virtual BOOL open() override;
        virtual BOOL isOpen() const override { return m_fd >= 0; }
        virtual BOOL close() override;
        virtual int numBytesAvailable() const override;
        virtual BOOL read(BYTE* buf, size_t buf_size, unsigned int timeout, sp::ReadResult* read_result) override;
        virtual BOOL write(BYTE* buf, size_t buf_size, unsigned int addr, unsigned int command_id) override;
        virtual unsigned int getBaudRate() const override;

    private:
        const std::string m_path;
        const SerialPortConfig m_config;
        int m_fd;
    };
}

#endif
