// Copyright (c) DEWETRON GmbH 2015
#pragma once

#include "uni_defines.h"
#include "dw_if_module_cxx.h"
//#include "dw_modules_c_api.h"
#include "dw_config.h"

namespace dwcxx
{
    class ModulesApi;

    /**
     * Interface to DAQN, DAQP, HSI, PAD, EPAD modules
     */
    class ModuleCxx : public IfModule
    {
    public:
        ModuleCxx(ModuleHandle handle, ModulesApi* api);
        ~ModuleCxx() = default;

        /**
         * Get the name of the module
         * Can be different from the class.
         * @return the modules name
         */
        std::string getModuleName() const UNI_OVERRIDE;

        /**
         * Get the unique type of the module
         * @return the unique type id of the module.
         */
        uint32_t getModuleID() const UNI_OVERRIDE;

        /**
         * Get the module address
         * @return the module address
         */
        uint32_t getModuleAddress() const UNI_OVERRIDE;

        /**
         * Get the module type name attribute from XML.
         * "PAD" for PAD, EPAD and EPAD2
         * "DAQP" for DAQP and HSI
         * "DAQN" for DAQN
         */
        std::string getModuleTypename() const UNI_OVERRIDE;

        /**
         * setParamStr
         * Set a module parameter (eg change mode, range)
         * @param prop_source select the source document
         * @param prop_expr
         * @param val
         * return true if successful
         */
        bool setParamStr(const std::string& prop_source, const std::string& cmd_path, const std::string& var) UNI_OVERRIDE;

        /**
         * getParamStr
         * Get a module parameter (eg change mode, range)
         * @param prop_source select the source document
         * @param prop_expr
         * @param val
         * return true if successful
         */
        bool getParamStr(const std::string& prop_source, const std::string& cmd_path, std::string& var) UNI_OVERRIDE;

        /**
         * getParamXML
         * Get a module parameter (eg change mode, range) in XML format.
         * @param prop_source select the source document
         * @param prop_expr
         * @param val
         * return true if successful
         */
        bool getParamXML(const std::string& prop_source, const std::string& cmd_path, std::string& var) UNI_OVERRIDE;


        /**
         * setParam_i32
         * @param command
         * @param val
         * @return true if successful
         */
        bool setParam_i32(uint32_t command, int val) UNI_OVERRIDE;

        /**
         * getParam_i32
         * @param command
         * @param val
         * @return true if successful
         */
        bool getParam_i32(uint32_t command, int* val) UNI_OVERRIDE;

        /**
         * Apply module settings and parameters to the hardware.
         * @return true if successful
         */
        bool applyParam() UNI_OVERRIDE;


        /**
         * Convenience methods
         */
        /**
         * setChannelParamStr
         * Set a module parameter (eg change mode, range)
         * @param prop_source select the source document
         * @param ch_dx
         * @param prop_expr
         * @param val
         * return true if successful
         */
        bool setChannelParamStr(const std::string& prop_source, uint32_t ch_idx, const std::string& cmd_path, const std::string& var) UNI_OVERRIDE;

        /**
         * getChannelParamStr
         * Get a module parameter (eg change mode, range)
         * @param prop_source select the source document
         * @param ch_dx
         * @param prop_expr
         * @param val
         * return true if successful
         */
        bool getChannelParamStr(const std::string& prop_source, uint32_t ch_idx, const std::string& cmd_path, std::string& var) UNI_OVERRIDE;

        /**
         * getChannelParamXML
         * Get a module parameter (eg change mode, range)
         * @param prop_source select the source document
         * @param ch_dx
         * @param prop_expr
         * @param val
         * return true if successful
         */
        bool getChannelParamXML(const std::string& prop_source, uint32_t ch_idx, const std::string& cmd_path, std::string& var) UNI_OVERRIDE;


        /**
         * Retrieve EPAD sample values
         */
        bool getSamples(SampleValueVec& sample_vecn, uint32_t num_channels) UNI_OVERRIDE;
    private:
        ModuleHandle m_handle;
        ModulesApi*  m_api;
        mutable dw_std::mutex m_mutex;
    };

} // dwcxx
