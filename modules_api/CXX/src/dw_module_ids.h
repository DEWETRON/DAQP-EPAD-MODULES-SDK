// Copyright (c) Dewetron 2013
#pragma once

#include "boost/bimap.hpp"
#include <boost/bimap/multiset_of.hpp>

namespace dw
{

    enum ModuleId
    {
        ID_INVALID          = 0xFF,

        ID_DAQP_V           = 0x00,
        ID_DAQN_POT         = 0x01,
        ID_DAQP_BRIDGE      = 0x02,
        ID_DAQN_RTD         = 0x03,
        ID_DAQP_DMM         = 0x04,
        ID_DAQP_CHARGE      = 0x05,
        ID_DAQP_uV          = 0x06,
        ID_DAQP_TRQ         = 0x07,
        ID_DAQP_FREQ        = 0x08,
        ID_DAQP_ACC         = 0x09,

        ID_PAD_TH8_P        = 0x10,
        ID_PAD_V8_P         = 0x11,

        ID_DAQ_AAF          = 0x16,
        ID_DAQP_CHARGE_A    = 0x17,
        ID_DAQP_BRIDGE_A    = 0x18,
        ID_DAQN_OHM         = 0x19,
        ID_DAQP_FREQ_A      = 0x1A,
        ID_DAQP_ACC_A       = 0x1B,

        ID_CAL_SCANN        = 0x1D,
        ID_DAQP_CHARGE_B    = 0x1E,
        ID_DAQP_BRIDGE_B    = 0x1F,
        ID_CAL_BRIDGE       = 0x20,
        ID_MDAQ_V           = 0x21,
        ID_DAQP_V_A         = 0x22,
        ID_DAQP_V_B         = 0x23,
        ID_MDAQ_BASE_X      = 0x24,
        ID_MDAQ_SUB_ACC     = 0x25,
        ID_MDAQ_SUB_ACC_A   = 0x26,
        ID_MDAQ_SUB_V_200_BNC = 0x27,
        ID_MDAQ_SUB_BRIDGE  = 0x28,
        ID_MDAQ_SUB_V_200_D = 0x29,
        ID_DAQP_BRIDGE_S    = 0x2A,
        ID_DAQP_HV          = 0x2B,
        ID_DAQP_CFB         = 0x2C,
        ID_MDAQ_STG         = 0x2D,
        ID_MDAQ_BASE_XA     = 0x2E,
        ID_DAQP_LV          = 0x2F,
        ID_PQL_BASE         = 0x30,
        ID_PQL_HV           = 0x31,
        ID_PQL_LV           = 0x32,
        ID_PQL_CURR         = 0x33,
        ID_DAQP_LA          = 0x34,
        ID_DAQP_STG         = 0x35,
        ID_MDAQ_DIFF_OUT    = 0x36,
        ID_DAQP_THERM       = 0x37,
        ID_DAQP_MULTI       = 0x38,
        ID_HSI_HV           = 0x39,
        ID_HSI_LV           = 0x3A,
        ID_HSI_STG          = 0x3B,
        ID_DAQP_CFB2        = 0x3C,

        ID_PAD_DO7          = 0x40,

        // DAQN: not scanable ids: > 0xFF
        ID_DAQN_V           = 1000,
        ID_DAQN_AIN         = 1001,
        ID_DAQN_DMM         = 1002,

    };

    class ModulesApiXML;

    /**
     * Map the DAQP ID enum to a string name.
     */
    class ModuleIdNameMap
    {
        ModuleIdNameMap();
        ~ModuleIdNameMap() = default;

        friend class ModulesApiXML;
        static ModuleIdNameMap& getModulesNameMapForModification();

        bool insert(int id, const std::string& module_name);

    public:

        std::string getModuleName(ModuleId mode) const;
        ModuleId getModuleEnum(const std::string& module_name) const;

        static const ModuleIdNameMap& getModulesNameMap();

        void dump();
    private:
        typedef boost::bimap<boost::bimaps::multiset_of<int>, boost::bimaps::set_of<std::string>> NameMap;
        NameMap m_name_map;
    };
} //namespace dw

