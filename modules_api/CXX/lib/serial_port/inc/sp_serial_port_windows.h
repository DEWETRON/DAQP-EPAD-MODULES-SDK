// Copyright DEWETRON GmbH 2015

#ifndef _SP_SERIAL_PORT_WINDOWS_H_
#define _SP_SERIAL_PORT_WINDOWS_H_

#include "sp_if_serial_port.h"
#include <mutex>
#include <windows.h>


namespace sp
{
    class SerialPortWindows : public IfSerialPort
    {
        SerialPortWindows(const SerialPortWindows&) = delete;
        SerialPortWindows& operator=(const SerialPortWindows&) = delete;
    public:
        SerialPortWindows(const std::string& name, const SerialPortConfig& config);
        virtual ~SerialPortWindows();

        virtual const char* getPortName() const override { return m_name.c_str(); }
        virtual bool open() override;
        virtual bool isOpen() const override;
        virtual bool close() override;
        virtual int32_t numBytesAvailable() const override;
        virtual ReadResult read(BYTE* buf, std::size_t buf_size, uint32_t timeout_milli) override;
        virtual bool write(BYTE* buf, std::size_t buf_size, uint32_t addr, uint32_t command_id) override;
        virtual uint32_t getBaudRate() const override;

    private:
        void printError_(const std::string& msg) const;
        void printLastError_(const std::string& msg) const;
        ReadResult read(BYTE* buf, std::size_t buf_size, uint32_t timeout_milli, uint32_t recursive_calls = 0);

    private:
        const std::string m_name;
        const SerialPortConfig m_config;
        HANDLE m_port;

        // we use overlapped IO in order to apply the read timeout. to
        // wait for completion during read and write, we have to have
        // an event in place.
        HANDLE m_event;

        std::mutex m_mutex;
    };
}

#endif
