// Copyright DEWETRON GmbH 2015

#ifndef _SP_SERIAL_PORT_UNIX_H_
#define _SP_SERIAL_PORT_UNIX_H_

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
        virtual bool open() override;
        virtual bool isOpen() const override { return m_fd >= 0; }
        virtual bool close() override;
        virtual int32_t numBytesAvailable() const override;
        virtual ReadResult read(BYTE* buf, std::size_t buf_size, uint32_t timeout_milli) override;
        virtual bool write(BYTE* buf, std::size_t buf_size, uint32_t addr, uint32_t command_id) override;
        virtual uint32_t getBaudRate() const override;

    private:
        const std::string m_path;
        const SerialPortConfig m_config;
        int m_fd;
    };
}

#endif
