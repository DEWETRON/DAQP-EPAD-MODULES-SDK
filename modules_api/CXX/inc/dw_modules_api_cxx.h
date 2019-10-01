// Copyright (c) DEWETRON GmbH 2015
#pragma once

#include "dw_if_module_cxx.h"
#include "dw_modules_sim_cxx.h"
#include "dw_module_name_tupel.h"
#include "dw_modules_sim_cxx.h"
#include "public/dw_modules_c_command.h"
#include "public/dw_modules_c_error.h"
#include "sp_if_serial_port_fwd.h"
#include "dw_config.h"
#include <map>

namespace dwcxx
{

    /**
     * CXX Frontend class to for dw_modules_api.
     * Encapsulates C interface methods and rebuilds a similar interface
     * to the APIs internal core class.
     */
    class ModulesApi
    {
        friend class ModulesSim;

    public:
        ModulesApi();
        ~ModulesApi();

        /**
         * Dynamically load dw_modules
         * @return true if successful
         */
        bool load();
        bool unload();


        /**
         * Init DwModulesApi
         * @return true if successful
         */
        bool init();

        /**
         * Uninitialize
         */
        void deInit();


        /**
         * Get the module at the given address
         * @param com_port
         * @param address
         * @return a valid ptr (0 if no modules at the address)
         */
        IfModuleWPtr getModule(const std::string& com_port, uint8_t address);


        /**
         * Instantiate the module with the given name.
         * This is used for offline setup or for instantiating DAQN (non programmable) modules
         * @param module_name
         * @param com_port
         * @param chan_no
         * @return a valid ptr (0 if no modules at the address)
         */
        IfModuleWPtr createModule(const ModuleNameTupel& module_name, const std::string& com_port, uint8_t address);


        /**
         * Simulation
         * @{
         */

        /**
         * Enable/Disable simulation
         * @param enable
         */
        bool enableSimulation(bool enable);

        /**
         * Get a pointer to the main ModulesSim object.
         * @return a ptr to the main ModulesSim instance.
         */
        ModulesSimWPtr getModelSim();

        /**
         * @}
         */

        /**
         * Serial Port Config
         * @{
         */

        /**
         * Add a Serial Port
         * @param ser_port is a pointer to a serial port
         * @return true if adding succeeded
         */
        bool addSerialPort(sp::IfSerialPort* ser_port);

        /**
         * Remove a Serial Port
         * @param ser_port is a pointer to a serial port
         * @return true if removing succeeded
         */
        bool removeSerialPort(sp::IfSerialPort* ser_port);

        bool clearSerialPort();

        bool openPort(const std::string& com_port);
        bool closePort(const std::string& com_port);

        /**
         * @}
         */

        /**
         * Scan for connected Dewetron Modules on the given serial ports.
         * In case of an scan error, the function returns -1.
         * @return number of found Modules
         */
        int scanPort();

        /**
         * scanAddress has similar functionality to scan port, abut allows to
         * specify the used port and address.
         * @param port
         * @param addr
         * @return 1 if a module was found, 0 for none, -1 for error
         */
        int scanAddress(const std::string& port, uint8_t addr);

        /**
        * sends new address "SETP" command and checks for valid response
        * return true: valid response, address saved by module
        * @param addr
        * @param port
        * return false: no/wrong response, address not saved by any module
        */
        bool setAddress(
            uint32_t addr,
            const std::string& port
            );


        /**
         * setParam_i32
         * @param command
         * @param val
         * @return true if successful
         */
        bool setParam_i32(uint32_t command, int val);

        /**
         * getParam_i32
         * @param command
         * @param val
         * @return true if successful
         */
        bool getParam_i32(uint32_t command, int* val);

    protected:

        /**
         * Clear simulation
         */
        bool clearSim();

        /**
         * Set the typical time a command would need to be finished.
         * @param delay in ms
         */
        bool setSimCommandDelay(int delay);

        /**
         * Add a serial port
         * @param port is the name of the serial port ("COM1", "HANSI" ...)
         * @return true, if adding a serial port succeeded
         */
        bool addSimSerialPort(const std::string& port);

        /**
         * Add a module
         * @param mod_name is the name of the module ("DAQP-LV", ...)
         * @param port is the name of the serial port ("COM1", "HANSI" ...)
         * @param slot_no is the number of the slot
         * @return true, if adding the module succeeded
         */
        bool addSimModule(const ModuleNameTupel& mod_name, const std::string& com_port, uint32_t address);

        /**
         * Remove a module
         * @param com_name is the name of the serial port ("COM1", "HANSI" ...)
         * @param slot_no is the number of the slot
         * @return if removing succeeded
         */
        bool removeSimModule(const std::string& com_name, uint32_t slot_no);
    private:
        static int m_load_counter;

        using ModuleHandleMap = std::map<uintptr_t, IfModulePtr>;
        ModuleHandleMap     m_module_handle_map;
        ModulesSimPtr       m_module_sim;
        dw_std::shared_mutex    m_mutex;
        std::map<std::string, dw_std::mutex> m_port_mutex;
    };
} // dwcxx
