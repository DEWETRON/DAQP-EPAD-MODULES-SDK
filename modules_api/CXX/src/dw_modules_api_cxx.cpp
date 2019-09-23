// Copyright (c) DEWETRON GmbH 2015

#include "dw_modules_api_cxx.h"
#include "dw_modules_load.h"
#include "dw_modules_c_command.h"
#include "dw_modules_c_error.h"
#include "dw_module_cxx.h"
#include "sp_if_serial_port.h"
#include <memory>
#include <shared_mutex>

namespace dwcxx
{
    int ModulesApi::m_load_counter(0);

    ModulesApi::ModulesApi()
    {
        load();
    }

    ModulesApi::~ModulesApi()
    {
        unload();
    }

    bool ModulesApi::load()
    {
        std::unique_lock<std::shared_mutex> lck(m_mutex);
        if (0 == m_load_counter++)
        {
            auto success = (DeWeModulesLoad() > 0);
            if (!success)
            {
                m_load_counter--;
            }
        }

        return m_load_counter != 0;
    }

    bool ModulesApi::unload()
    {
        deInit();
        if (m_load_counter > 0)
        {
            --m_load_counter;
        }
        else
        {
            m_load_counter = 0;
        }
        std::unique_lock<std::shared_mutex> lck(m_mutex);
        if (0 == m_load_counter)
        {
            DeWeModulesUnload();
        }
        return m_load_counter == 0;
    }

    bool ModulesApi::init()
    {
        if (m_load_counter != 0)
        {
            std::unique_lock<std::shared_mutex> lck(m_mutex);
            if (DW_SUCCESS == DwModApi::DeWeInit())
            {
                if (!m_module_sim)
                {
                    m_module_sim = std::make_shared<ModulesSim>(this);
                }

                return true;
            }
        }
        return false;
    }

    void ModulesApi::deInit()
    {
        if (m_load_counter == 1)
        {
            std::unique_lock<std::shared_mutex> lck(m_mutex);
            DwModApi::DeWeDeInit();
        }
    }

    IfModuleWPtr ModulesApi::getModule(const std::string& com_port, uint8 address)
    {
        if (m_load_counter != 0)
        {
            std::shared_lock<std::shared_mutex> lck(m_mutex);
            std::lock_guard<std::mutex> port_lck(m_port_mutex[com_port]);
            auto mh = DwModApi::DeWeGetModule(com_port.c_str(), address);
            if (mh)
            {
                auto match = m_module_handle_map.find(reinterpret_cast<uintptr_t>(mh));
                if (match != m_module_handle_map.end())
                {
                    return match->second;
                }

                auto module_cxx = std::make_shared<ModuleCxx>(mh, this);
                if (module_cxx)
                {
                    // store shared_ptr to handle map
                    m_module_handle_map[reinterpret_cast<uintptr_t>(mh)] = module_cxx;
                    return module_cxx;
                }
            }
        }
        return IfModuleWPtr();
    }

    IfModuleWPtr ModulesApi::createModule(const ModuleNameTupel& module_name, const std::string& com_port, uint8 chan_no)
    {
        if (m_load_counter != 0)
        {
            std::unique_lock<std::shared_mutex> lck(m_mutex);
            auto mh = DwModApi::DeWeCreateModule(module_name.getName().c_str(), module_name.getRevision().c_str(), com_port.c_str(), chan_no);
            if (mh)
            {
                auto module_cxx = std::make_shared<ModuleCxx>(mh, this);
                if (module_cxx)
                {
                    // store shared_ptr to handle map
                    m_module_handle_map[reinterpret_cast<uintptr_t>(mh)] = module_cxx;
                    return module_cxx;
                }
            }
        }
        return IfModuleWPtr();
    }

    bool ModulesApi::addSerialPort(sp::IfSerialPort* ser_port)
    {
        if (m_load_counter != 0)
        {
            std::unique_lock<std::shared_mutex> lck(m_mutex);
            if (DW_SUCCESS == DwModApi::DeWeSetParam_Ptr(API_HANDLE, DWCMD_ADD_SERIALPORT, ser_port, sizeof(ser_port)))
            {
                return true;
            }
        }
        return false;
    }

    bool ModulesApi::removeSerialPort(sp::IfSerialPort* ser_port)
    {
        if (m_load_counter != 0)
        {
            std::unique_lock<std::shared_mutex> lck(m_mutex);
            if (DW_SUCCESS == DwModApi::DeWeSetParam_Ptr(API_HANDLE, DWCMD_REMOVE_SERIALPORT, ser_port, sizeof(ser_port)))
            {
                return true;
            }
        }
        return false;
    }

    bool ModulesApi::clearSerialPort()
    {
        if (m_load_counter != 0)
        {
            std::unique_lock<std::shared_mutex> lck(m_mutex);
            if (DW_SUCCESS == DwModApi::DeWeSetParam_i32(API_HANDLE, DWCMD_CLEAR_SERIALPORT, 32))
            {
                return true;
            }
        }
        return false;
    }

    bool ModulesApi::openPort(const std::string& com_port)
    {
        if (m_load_counter != 0)
        {
            std::unique_lock<std::shared_mutex> lck(m_mutex);
            if (DW_SUCCESS == DwModApi::DeWeSetParamStr(API_HANDLE, "", "OPEN_PORT", com_port.c_str()))
            {
                // default create port mutex
                m_port_mutex[com_port];
                return true;
            }
        }
        return false;
    }

    bool ModulesApi::closePort(const std::string& com_port)
    {
        if (m_load_counter != 0)
        {
            std::unique_lock<std::shared_mutex> lck(m_mutex);
            if (DW_SUCCESS == DwModApi::DeWeSetParamStr(API_HANDLE, "", "CLOSE_PORT", com_port.c_str()))
            {
                m_port_mutex.erase(com_port);
                return true;
            }
        }
        return false;

    }

    int ModulesApi::scanPort()
    {
        if (m_load_counter != 0)
        {
            std::unique_lock<std::shared_mutex> lck(m_mutex);
            if (DW_SUCCESS == DwModApi::DeWeSetParam_i32(API_HANDLE, DWCMD_SCAN, 32))
            {
                int num_modules = 0;
                if (DW_SUCCESS == DwModApi::DeWeGetParam_i32(API_HANDLE, DWCMD_SCAN, &num_modules))
                {
                    return num_modules;
                }
                return 0;
            }
        }
        return 0;
    }

    int ModulesApi::scanAddress(const std::string& port, uint8 addr)
    {
        if (m_load_counter != 0)
        {
            int status = -1;

            std::shared_lock<std::shared_mutex> lck(m_mutex);
            std::lock_guard<std::mutex> port_lck(m_port_mutex[port]);

            if (DW_SUCCESS == DwModApi::DeWeScanAddress(API_HANDLE, port.c_str(), addr, &status))
            {
                return status;
            }
        }
        return -1;
    }

    bool ModulesApi::setAddress(uint32_t addr, const std::string& port)
    {
        if (m_load_counter != 0)
        {
            std::shared_lock<std::shared_mutex> lck(m_mutex);
            std::lock_guard<std::mutex> port_lck(m_port_mutex[port]);
            if (DW_SUCCESS == DwModApi::DeWeSetAddress(API_HANDLE, port.c_str(), addr))
            {
                return true;;
            }
        }
        return false;
    }


    bool ModulesApi::setParam_i32(uint32_t command, int val)
    {
        if (m_load_counter != 0)
        {
            std::unique_lock<std::shared_mutex> lck(m_mutex);
            if (DW_SUCCESS == DwModApi::DeWeSetParam_i32(API_HANDLE, command, val))
            {
                return true;
            }
        }
        return false;
    }


    bool ModulesApi::getParam_i32(uint32_t command, int* val)
    {
        if (m_load_counter != 0)
        {
            std::unique_lock<std::shared_mutex> lck(m_mutex);
            if (DW_SUCCESS == DwModApi::DeWeGetParam_i32(API_HANDLE, command, val))
            {
                return true;
            }
        }
        return false;
    }

    ModulesSimWPtr ModulesApi::getModelSim()
    {
        std::shared_lock<std::shared_mutex> lck(m_mutex);
        return m_module_sim;
    }

    bool ModulesApi::enableSimulation(bool enable)
    {
        if (m_load_counter != 0)
        {
            std::unique_lock<std::shared_mutex> lck(m_mutex);
            if (DW_SUCCESS == DwModApi::DeWeSetParam_i32(API_HANDLE, DWCMD_ENABLE_SIMULATION, enable))
            {
                return true;
            }
        }
        return false;
    }

    bool ModulesApi::clearSim()
    {
        if (m_load_counter != 0)
        {
            std::unique_lock<std::shared_mutex> lck(m_mutex);
            if (DW_SUCCESS == DwModApi::DeWeSetParam_i32(API_HANDLE, DWCMD_CLEAR_SIMULATION, 0))
            {
                return true;
            }
        }
        return false;
    }

    bool ModulesApi::setSimCommandDelay(int delay)
    {
        if (m_load_counter != 0)
        {
            std::unique_lock<std::shared_mutex> lck(m_mutex);
            if (DW_SUCCESS == DwModApi::DeWeSetParam_i32(API_HANDLE, DWCMD_SIM_COMMAND_DELAY, delay))
            {
                return true;
            }
        }
        return false;
    }

    bool ModulesApi::addSimSerialPort(const std::string& port)
    {
        if (m_load_counter != 0)
        {
            std::unique_lock<std::shared_mutex> lck(m_mutex);
            return DwModApi::DeWeSimAddSerialPort(port.c_str()) == DW_SUCCESS;
        }
        return false;
    }

    bool ModulesApi::addSimModule(const ModuleNameTupel& mod_name, const std::string& port, uint32_t slot_no)
    {
        if (m_load_counter != 0)
        {
            std::unique_lock<std::shared_mutex> lck(m_mutex);
            return DwModApi::DeWeSimAddModule(mod_name.getName().c_str(), mod_name.getRevision().c_str(), port.c_str(), slot_no) == DW_SUCCESS;
        }
        return false;
    }

    bool ModulesApi::removeSimModule(const std::string& port, uint32_t slot_no)
    {
        if (m_load_counter != 0)
        {
            std::unique_lock<std::shared_mutex> lck(m_mutex);
            return DwModApi::DeWeSimRemoveModule(port.c_str(), slot_no) == DW_SUCCESS;
        }
        return false;
    }
} //dwcxx
