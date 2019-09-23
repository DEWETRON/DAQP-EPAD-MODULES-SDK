// Copyright (c) DEWETRON GmbH 2015

#include "dw_modules_sim_cxx.h"
#include "dw_modules_api_cxx.h"
#include "dw_module_name_tupel.h"
#include "assert.h"

namespace dwcxx
{
    ModulesSim::ModulesSim(ModulesApi* api)
        : m_api(api)
    {

    }

    void ModulesSim::clear()
    {
        assert(m_api);
        if (m_api)
        {
            m_api->clearSim();
        }
    }

    void ModulesSim::setCommandDelay(int delay)
    {
        assert(m_api);
        if (m_api)
        {
            m_api->setSimCommandDelay(delay);
        }
    }

    bool ModulesSim::addSerialPort(const std::string& port)
    {
        assert(m_api);
        if (m_api)
        {
            return m_api->addSimSerialPort(port);
        }
        return false;
    }

    bool ModulesSim::addModule(const ModuleNameTupel& mod_name, const std::string& port, uint32_t slot_no)
    {
        assert(m_api);
        if (m_api)
        {
            return m_api->addSimModule(mod_name, port, slot_no);
        }
        return false;
    }

    bool ModulesSim::removeModule(const std::string& port, uint32_t slot_no)
    {
        assert(m_api);
        if (m_api)
        {
            return m_api->removeSimModule(port, slot_no);
        }
        return false;
    }
}  // dwcxx
