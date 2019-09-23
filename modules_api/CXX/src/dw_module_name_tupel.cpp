// Copyright (c) DEWETRON GmbH 2015

#include "dw_module_name_tupel.h"

namespace dwcxx
{
    ModuleNameTupel::ModuleNameTupel(const char* module_name)
        : m_module_name(module_name)
    {}

    ModuleNameTupel::ModuleNameTupel(const std::string& module_name)
        : m_module_name(module_name)
    {}

    ModuleNameTupel::ModuleNameTupel(const std::string& module_name, const std::string& fw_rev)
        : m_module_name(module_name)
        , m_firmare_rev(fw_rev)
    {
    }

    ModuleNameTupel::ModuleNameTupel()
        : m_module_name()
        , m_firmare_rev()
    {

    }

    const std::string& ModuleNameTupel::getName() const
    {
        return m_module_name;
    }

    const std::string& ModuleNameTupel::getRevision() const
    {
        return m_firmare_rev;
    }
} // dwcxx
