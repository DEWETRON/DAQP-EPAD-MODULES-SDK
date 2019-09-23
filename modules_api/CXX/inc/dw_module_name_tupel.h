// Copyright (c) DEWETRON GmbH 2015
#pragma once

#include <string>

namespace dwcxx
{
     /**
     * Modules are not 100% identifiable by the name alone.
     * for complete identification the firmware revision is needed too.
     */
    class ModuleNameTupel
    {
    public:
        ModuleNameTupel();
        ModuleNameTupel(const char* module_name);
        ModuleNameTupel(const std::string& module_name);
        ModuleNameTupel(const std::string& module_name, const std::string& fw_rev);

        const std::string& getName() const;
        const std::string& getRevision() const;
    private:
        std::string m_module_name;
        std::string m_firmare_rev;
    };

} // dwcxx
