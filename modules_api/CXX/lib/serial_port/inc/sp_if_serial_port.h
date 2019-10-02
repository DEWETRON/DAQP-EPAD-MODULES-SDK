// Copyright DEWETRON GmbH 2013

#ifndef _IF_SERIAL_PORT_H_
#define _IF_SERIAL_PORT_H_
#pragma once

#include "sp_if_serial_port_fwd.h"
#include <memory>


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
        SerialPortConfig(uint32_t baudrate = 9600)
        : m_baudrate(baudrate),
          m_parity(Parity::NONE),
          m_csize(8),
          m_flow(FlowControl::NONE),
          m_stop_bits(StopBits::ONE) {}

        SerialPortConfig& setBaudrate(uint32_t b) { m_baudrate=b; return *this; }
        SerialPortConfig& setParity(Parity::ParEnum p) { m_parity=p; return *this; }
        SerialPortConfig& setCSize(uint32_t cs) { m_csize=cs; return *this; }
        SerialPortConfig& setFlow(FlowControl::FlowEnum f) { m_flow=f; return *this; }
        SerialPortConfig& setStop_bits(StopBits::StopEnum sb) { m_stop_bits=sb; return *this; }

        uint32_t getBaudrate() const { return m_baudrate; }
        Parity::ParEnum getParity() const { return m_parity; }
        uint32_t getCSize() const { return m_csize; }
        FlowControl::FlowEnum getFlow() const { return m_flow; }
        StopBits::StopEnum getStopBits() const { return m_stop_bits; }

    private:
        uint32_t m_baudrate;
        Parity::ParEnum m_parity;
        uint32_t m_csize;
        FlowControl::FlowEnum m_flow;
        StopBits::StopEnum m_stop_bits;
    };

    /** IfSerialPort::Read() can have many different meanings */
    class ReadResult
    {
    public:
        enum Type
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

    private:
        Type m_type;
        union
        {
            std::size_t num_bytes;
        } m_what;

    public:
        enum _Timeout { Timeout };
        enum _LowLevel { LowLevel };
        ReadResult(_Timeout) : m_type(TIMEOUT) {}
        ReadResult(_LowLevel) : m_type(LOWLEVEL_ERROR) {}
        explicit ReadResult(uint32_t num) : m_type(OK) { m_what.num_bytes = num; }
    };


    /**
     * IfSerialPort is an abstract interface to be implemented by other modules
     * providing serial port(s) for this library.
     * Open,Close,
     * Read,write
     */
    class IfSerialPort
    {
    public:
        virtual ~IfSerialPort() = default;

        /**
         * Get the name of the serial port. Must be unique!
         * @return the name of the serial port
         */
         virtual const char* getPortName() const = 0;

        /**
         * Open the port.
         * @return true if opening succeeded
         */
        virtual bool open() = 0;

        /**
         * Check if the port has been opened.
         * @return true if the board is open.
         */
        virtual bool isOpen() const = 0;

        /**
         * Close the port.
         * @return true if closing succeeded
         */
        virtual bool close() = 0;

        /** Number of bytes available in next Read().
         * @return number of bytes available, or -1 on error
         */
        virtual int32_t numBytesAvailable() const = 0;

        /**
         * Read from the serial port.
         * @param buf is pointer to a byte buffer.
         * @param buf_size is the size of the buffer.
         * @param timeout in msec
         * @return nicely encapsulated error indicator (containing number of bytes read)
         */
        virtual ReadResult read(BYTE* buf, std::size_t buf_size, uint32_t timeout) = 0;

        /**
         * Write to the serial port.
         * @param buf is pointer to a byte buffer.
         * @param buf_size is the size of the buffer.
         * @param addr the modules address (for simulation)
         * @param command_id the command identifier (for simulation)
         * @return true if writing succeeded
         */
        virtual bool write(BYTE* buf, std::size_t buf_size, uint32_t addr, uint32_t command_id) = 0;

        /**
         * Get the serial ports configured baud rate
         * @return the baudrate
         */
        virtual uint32_t getBaudRate() const = 0;


        /**
         * Concurrency
         * @{
         */

        /**
         * Start a serial port transaction.
         * (Locking for multi threaded access)
         */
        //virtual ScopedTransaction getScopedTransaction() = 0;

        /**
         * @}
         */

    };

} // end namespace dw


#endif // _IF_SERIAL_PORT_H_
