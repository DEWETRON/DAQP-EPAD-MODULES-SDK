// Copyright (c) Dewetron 2013

#ifndef _DW_MODULES_SIM_H_
#define _DW_MODULES_SIM_H_
#pragma once


#include "sp_if_serial_port.h"
#include "dw_if_module.h"
//#include "dw_module_base_sim.h"
#include "dw_module_name_tupel.h"
#include <inttypes.h>
#include <map>
#include <vector>


namespace dw
{
    /**
     * On purpose import namespace dwcxx
     * to share interface types with the user C++ frontend library.
     */
    using namespace dwcxx;

    class ModulesApi;

    class ModuleFactorySim;
    using ModuleFactorySimPtr = std::shared_ptr<ModuleFactorySim>;

    enum class CommandType
    {
        SINGLE,
        BROADCAST
    };


    /**
     * Configure a simulation environment interface.
     */
    class ModulesSim
    {
    public:
        ModulesSim();
        ~ModulesSim();

        /**
         * init ModulesSim
         * @return true if successfully
         */
        bool init(ModulesApi* api);

        /**
         * DeInit ModulesSim
         */
        void deInit();

        /**
         * Set the typical time a command would need to be finished.
         * @param delay in ms
         */
        void setCommandDelay(uint32_t delay);


        uint32_t getCommandDelay() const;

        /**
         * Add a serial port
         * @param com_name is the name of the serial port ("COM1", "HANSI" ...)
         * @return true, if adding a serial port succeeded
         */
        bool addSerialPort(const std::string& com_name);

        /**
         * Forget current simulation configuration
         */
        void clearModules();

        /**
         * Add a module
         * @param com_name is the name of the serial port ("COM1", "HANSI" ...)
         * @param mod_name is the name of the module ("DAQP-LV", ...)
         * @param slot_no is the number of the slot
         * @return true, if adding the module succeeded
         */
        bool addModule(const ModuleNameTupel& mod_name, const std::string& com_name, uint32_t slot_no);

        /**
         * Remove a module
         * @param com_name is the name of the serial port ("COM1", "HANSI" ...)
         * @param slot_no is the number of the slot
         * @return if removing succeeded
         */
        bool removeModule(const std::string& com_name, uint32_t slot_no);

        /**
         * Apply simulation config to main api
         * @return true, if successful
         */
        bool applySimulationConfig();

        /**
         * Return the config as a string
         * @return the config
         */
        std::string getDump();


        /**
         * Simulate Filter Button Press
         * @param com_name is the name of the serial port ("COM1", "HANSI" ...)
         * @param the slot_no of the module.
         */
        void pushButton(const std::string& com_name, uint32_t slot_no);

        /**
         * Serial Port Fake
         * @{
         */

        /** Number of bytes available in next Read().
         * @return number of bytes available, or -1 on error
         */
        int32_t numBytesAvailable() const;

        /**
         * Read from the serial port.
         * @param buf is pointer to a byte buffer.
         * @param buf_size is the size of the buffer.
         * @return the number of bytes read, or -1 in case of an error.
         */
        std::size_t read(const std::string& port_name, BYTE* buf, std::size_t buf_size);

        /**
         * Write to the serial port.
         * @param port_name
         * @param addr
         * @param command_id
         * @param buf is pointer to a byte buffer.
         * @param buf_size is the size of the buffer.
         * @return true if writing succeeded
         */
         bool write(const std::string& port_name, uint32_t addr, uint32_t command_id, BYTE* buf, std::size_t buf_size);


        /**
         * @}
         */


    private:

    //    ModulesApi*     m_modules_api;
    //    ModuleFactorySimPtr m_sim_factory;


    //    // ID -> Port
    //    typedef std::map<std::string, sp::IfSerialPortPtr> SerialPortMap;
    //    SerialPortMap   m_serial_ports;

    //    // ID -> slot -> Module
    //    typedef std::map<uint32_t, ModuleBaseSim::Ptr> SlotToModuleMap;
    //    typedef std::map<std::string, SlotToModuleMap> SerialPortToSlotModuleMap;
    //    SerialPortToSlotModuleMap       m_sim_modules;

    //    std::string     m_fifo_stored_response;
    //    uint32_t          m_delay;

    //private:
    //    bool doCommand(const std::string& command,
    //        uint32_t command_id,
    //        std::string& response,
    //        SlotToModuleMap& slot_module_map,
    //        SlotToModuleMap::iterator slot_entry,
    //        CommandType cmd_type = CommandType::SINGLE
    //        );

    };


} // end namespace dw


#endif // _DW_MODULES_SIM_H_
