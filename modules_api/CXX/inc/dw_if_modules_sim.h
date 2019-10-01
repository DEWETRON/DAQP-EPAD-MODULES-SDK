// Copyright (c) DEWETRON GmbH 2019

#pragma once
#include "uni_types.h"
#include "dw_if_modules_sim_fwd.h"
#include "dw_module_name_tupel.h"
#include <string>

namespace dw
{
    /**
     * On purpose import namespace dwcxx
     * to share interface types with the user C++ frontend library.
     */
    using namespace dwcxx;

    /**
     * Configure a simulation environment interface.
     */
    class IfModulesSim
    {
    public:
        virtual ~IfModulesSim() = default;

        /**
         * Set the typical time a command would need to be finished.
         * @param delay in ms
         */
        virtual void setCommandDelay(uint32 delay) = 0;

        /**
         * Get the typical time a command would need to be finished.
         * @return delay in ms
         */
        virtual uint32 getCommandDelay() const = 0;

        /**
         * Add a serial port
         * @param com_name is the name of the serial port ("COM1", "ttyS16" ...)
         * @return true, if adding a serial port succeeded
         */
        virtual bool addSerialPort(const std::string& com_name) = 0;

        /**
         * Forget current simulation configuration
         */
        virtual void clearModules() = 0;

        /**
         * Add a module
         * @param com_name is the name of the serial port ("COM1", "ttyS16" ...)
         * @param mod_name is the name of the module ("DAQP-LV", ...)
         * @param slot_no is the number of the slot
         * @return true, if adding the module succeeded
         */
        virtual bool addModule(const ModuleNameTupel& mod_name, const std::string& com_name, uint32 slot_no) = 0;

        /**
         * Remove a module
         * @param com_name is the name of the serial port ("COM1", "HANSI" ...)
         * @param slot_no is the number of the slot
         * @return if removing succeeded
         */
        virtual bool removeModule(const std::string& com_name, uint32 slot_no) = 0;

        /**
         * Apply simulation config to main api
         * @return true, if successful
         */
        virtual bool applySimulationConfig() = 0;

        /**
         * Return the config as a string
         * @return the config
         */
        virtual std::string getSimConfig() = 0;

        /**
         * Simulate Filter Button Press
         * @param com_name is the name of the serial port ("COM1", "ttyS16" ...)
         * @param the slot_no of the module.
         */
        virtual void pushButton(const std::string& com_name, uint32 slot_no) = 0;

        /**
         * Serial Port Sim
         * @{
         */

        /** Number of bytes available in next Read().
         * @return number of bytes available, or -1 on error
         */
        virtual sint32 numBytesAvailable() const = 0;

        /**
         * Read from the serial port.
         * @param buf is pointer to a byte buffer.
         * @param buf_size is the size of the buffer.
         * @return the number of bytes read, or -1 in case of an error.
         */
        virtual std::size_t read(const std::string& port_name, BYTE* buf, std::size_t buf_size) = 0;

        /**
         * Write to the serial port.
         * @param port_name
         * @param addr
         * @param command_id
         * @param buf is pointer to a byte buffer.
         * @param buf_size is the size of the buffer.
         * @return true if writing succeeded
         */
        virtual bool write(const std::string& port_name, uint32 addr, uint32 command_id, BYTE* buf, std::size_t buf_size) = 0;


        /**
         * @}
         */


    };

}