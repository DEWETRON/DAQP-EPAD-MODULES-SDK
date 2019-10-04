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
        ~SerialPortWindows();

        virtual const char* getPortName() const override { return m_name.c_str(); }
        virtual BOOL open() override;
        virtual BOOL isOpen() const override;
        virtual BOOL close() override;
        virtual int numBytesAvailable() const override;
        virtual BOOL read(BYTE* buf, size_t buf_size, unsigned int timeout, sp::ReadResult* read_result) override;
        virtual BOOL write(BYTE* buf, size_t buf_size, unsigned int addr, unsigned int command_id) override;
        virtual unsigned int getBaudRate() const override;

    private:
        void printError_(const std::string& msg) const;
        void printLastError_(const std::string& msg) const;
        ReadResult read(BYTE* buf, std::size_t buf_size, unsigned int timeout_milli, unsigned int recursive_calls = 0);

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
