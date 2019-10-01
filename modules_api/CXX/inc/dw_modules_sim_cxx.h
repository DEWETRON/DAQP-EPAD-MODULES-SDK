// Copyright (c) DEWETRON GmbH 2015
#pragma once

#include "dw_config.h"
#include <string>

namespace dwcxx
{
    class ModulesApi;
    class ModuleNameTupel;

    /**
     * Configure a simulation environment interface.
     */
    class ModulesSim
    {
    public:
        ModulesSim(ModulesApi* api);

        /**
         * Forget current simulation configuration
         */
        void clear();

        /**
         * Set the typical time a command would need to be finished.
         * @param delay in ms
         */
        void setCommandDelay(int delay);

        /**
         * Add a serial port
         * @param port is the name of the serial port ("COM1", "HANSI" ...)
         * @return true, if adding a serial port succeeded
         */
        bool addSerialPort(const std::string& port);

        /**
         * Add a module
         * @param mod_name is the name of the module ("DAQP-LV", ...)
         * @param port is the name of the serial port ("COM1", "HANSI" ...)
         * @param slot_no is the number of the slot
         * @return true, if adding the module succeeded
         */
        bool addModule(const ModuleNameTupel& mod_name, const std::string& port, uint32_t slot_no);

        /**
         * Remove a module
         * @param port is the name of the serial port ("COM1", "HANSI" ...)
         * @param slot_no is the number of the slot
         * @return if removing succeeded
         */
        bool removeModule(const std::string& port, uint32_t slot_no);
    private:
        ModulesApi* m_api;
    };

    using ModulesSimWPtr = dw_std::weak_ptr<ModulesSim>;
    using ModulesSimPtr =  dw_std::shared_ptr<ModulesSim>;

} // dwcxx
