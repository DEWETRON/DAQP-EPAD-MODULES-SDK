// Copyright DEWETRON GmbH 2013

#ifndef _IF_SERIAL_PORT_H_
#define _IF_SERIAL_PORT_H_
#pragma once

#include "sp_if_serial_port_fwd.h"

#ifdef WIN32
# include <windows.h>
# define SP_IMPORT WINAPI
#else
# define SP_IMPORT
#endif


typedef unsigned char BYTE;


namespace sp
{
    /**
     * Allowed parity settings
     */
    struct Parity
    {
        enum ParEnum
        {
            NONE,
            ODD,
            EVEN
        };
    };

    /**
     * Allowed Flow Control settings
     */
    struct FlowControl
    {
        enum FlowEnum
        {
            NONE,
            SOFTWARE,
            HARDWARE
        };
    };

    /**
     * Allowed Stop Bit settings
     */
    struct StopBits
    {
        enum StopEnum
        {
            ONE,
            ONEP_POINT_FIVE,
            TWO
        };
    };

    class SerialPortConfig
    {
    public:
        SerialPortConfig(unsigned int baudrate = 9600)
        : m_baudrate(baudrate),
          m_parity(Parity::NONE),
          m_csize(8),
          m_flow(FlowControl::NONE),
          m_stop_bits(StopBits::ONE) {}

        SerialPortConfig& setBaudrate(unsigned int b) { m_baudrate=b; return *this; }
        SerialPortConfig& setParity(Parity::ParEnum p) { m_parity=p; return *this; }
        SerialPortConfig& setCSize(unsigned int cs) { m_csize=cs; return *this; }
        SerialPortConfig& setFlow(FlowControl::FlowEnum f) { m_flow=f; return *this; }
        SerialPortConfig& setStop_bits(StopBits::StopEnum sb) { m_stop_bits=sb; return *this; }

        unsigned int getBaudrate() const { return m_baudrate; }
        Parity::ParEnum getParity() const { return m_parity; }
        unsigned int getCSize() const { return m_csize; }
        FlowControl::FlowEnum getFlow() const { return m_flow; }
        StopBits::StopEnum getStopBits() const { return m_stop_bits; }

    private:
        unsigned int m_baudrate;
        Parity::ParEnum m_parity;
        unsigned int m_csize;
        FlowControl::FlowEnum m_flow;
        StopBits::StopEnum m_stop_bits;
    };

    /** IfSerialPort::Read() can have many different meanings */
    struct ReadResult
    {
        enum class Type
        {
            OK,
            TIMEOUT,
            LOWLEVEL_ERROR,
        };

        Type getType() const
        {
            return m_type;
        }
        std::size_t getNumBytes() const
        {
            return m_what.num_bytes;
        }


        Type m_type;
        union
        {
            size_t num_bytes;
        } m_what;

        enum _Timeout { Timeout };
        enum _LowLevel { LowLevel };

        ReadResult(_Timeout) : m_type(Type::TIMEOUT) {}
        ReadResult(_LowLevel) : m_type(Type::LOWLEVEL_ERROR) {}
        explicit ReadResult(unsigned int num) : m_type(Type::OK) { m_what.num_bytes = num; }
    };



    /**
     * IfSerialPort is an abstract interface to be implemented by other modules
     * providing serial port(s) for this library.
     * Open,Close,
     * Read,write
     * (C compatible)
     */
    class IfSerialPort
    {
    public:
        /**
         * Get the name of the serial port. Must be unique!
         * @return the name of the serial port
         */
        virtual const char* SP_IMPORT getPortName() const = 0;

        /**
         * Open the port.
         * @return true if opening succeeded
         */
        virtual BOOL SP_IMPORT open() = 0;

        /**
         * Check if the port has been opened.
         * @return true if the board is open.
         */
        virtual BOOL SP_IMPORT isOpen() const = 0;

        /**
         * Close the port.
         * @return true if closing succeeded
         */
        virtual BOOL SP_IMPORT close() = 0;

        /** Number of bytes available in next Read().
         * @return number of bytes available, or -1 on error
         */
        virtual int SP_IMPORT numBytesAvailable() const = 0;

        /**
         * Read from the serial port.
         * @param buf is pointer to a byte buffer.
         * @param buf_size is the size of the buffer.
         * @param timeout in msec
         * @param out nicely encapsulated error indicator (containing number of bytes read)
         * @return true if reading succeeded
         */
        virtual BOOL SP_IMPORT read(BYTE* buf, size_t buf_size, unsigned int timeout, ReadResult* read_result) = 0;

        /**
         * Write to the serial port.
         * @param buf is pointer to a byte buffer.
         * @param buf_size is the size of the buffer.
         * @param addr the modules address (for simulation)
         * @param command_id the command identifier (for simulation)
         * @return true if writing succeeded
         */
        virtual BOOL SP_IMPORT write(BYTE* buf, size_t buf_size, unsigned int addr, unsigned int command_id) = 0;

        /**
         * Get the serial ports configured baud rate
         * @return the baudrate
         */
        virtual unsigned int SP_IMPORT getBaudRate() const = 0;
    };

} // end namespace dw


#endif // _IF_SERIAL_PORT_H_
