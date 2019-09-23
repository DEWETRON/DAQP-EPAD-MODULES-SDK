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
    public:
        SerialPortWindows(const std::string& name, const SerialPortConfig& config);
        virtual ~SerialPortWindows();

        virtual const char* getPortName() const UNI_OVERRIDE { return m_name.c_str(); }
        virtual bool open() UNI_OVERRIDE;
        virtual bool isOpen() const UNI_OVERRIDE;
        virtual bool close() UNI_OVERRIDE;
        virtual sint32 numBytesAvailable() const UNI_OVERRIDE;
        virtual ReadResult read(BYTE* buf, std::size_t buf_size, uint32_t timeout_milli) UNI_OVERRIDE;
        virtual bool write(BYTE* buf, std::size_t buf_size, uint32_t addr, uint32_t command_id) UNI_OVERRIDE;
        virtual uint32_t getBaudRate() const UNI_OVERRIDE;
        //virtual ScopedTransaction getScopedTransaction() UNI_OVERRIDE;

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
