// Copyright (c) DEWETRON GmbH 2015
#pragma once

#include "dw_if_module_cxx.h"
#include "dw_modules_c_api.h"
#include <mutex>

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
        std::string getModuleName() const override;

        /**
         * Get the unique type of the module
         * @return the unique type id of the module.
         */
        uint32_t getModuleID() const override;

        /**
         * Get the module address
         * @return the module address
         */
        uint32_t getModuleAddress() const override;

        /**
         * Get the module type name attribute from XML.
         * "PAD" for PAD, EPAD and EPAD2
         * "DAQP" for DAQP and HSI
         * "DAQN" for DAQN
         */
        std::string getModuleTypename() const override;

        /**
         * setParamStr
         * Set a module parameter (eg change mode, range)
         * @param prop_source select the source document
         * @param prop_expr
         * @param val
         * return true if successful
         */
        bool setParamStr(const std::string& prop_source, const std::string& cmd_path, const std::string& var) override;

        /**
         * getParamStr
         * Get a module parameter (eg change mode, range)
         * @param prop_source select the source document
         * @param prop_expr
         * @param val
         * return true if successful
         */
        bool getParamStr(const std::string& prop_source, const std::string& cmd_path, std::string& var) override;

        /**
         * getParamXML
         * Get a module parameter (eg change mode, range) in XML format.
         * @param prop_source select the source document
         * @param prop_expr
         * @param val
         * return true if successful
         */
        bool getParamXML(const std::string& prop_source, const std::string& cmd_path, std::string& var) override;


        /**
         * setParam_i32
         * @param command
         * @param val
         * @return true if successful
         */
        bool setParam_i32(uint32_t command, int val) override;

        /**
         * getParam_i32
         * @param command
         * @param val
         * @return true if successful
         */
        bool getParam_i32(uint32_t command, int* val) override;

        /**
         * Apply module settings and parameters to the hardware.
         * @return true if successful
         */
        bool applyParam() override;


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
        bool setChannelParamStr(const std::string& prop_source, uint32_t ch_idx, const std::string& cmd_path, const std::string& var) override;

        /**
         * getChannelParamStr
         * Get a module parameter (eg change mode, range)
         * @param prop_source select the source document
         * @param ch_dx
         * @param prop_expr
         * @param val
         * return true if successful
         */
        bool getChannelParamStr(const std::string& prop_source, uint32_t ch_idx, const std::string& cmd_path, std::string& var) override;

        /**
         * getChannelParamXML
         * Get a module parameter (eg change mode, range)
         * @param prop_source select the source document
         * @param ch_dx
         * @param prop_expr
         * @param val
         * return true if successful
         */
        bool getChannelParamXML(const std::string& prop_source, uint32_t ch_idx, const std::string& cmd_path, std::string& var) override;


        /**
         * Retrieve EPAD sample values
         */
        bool getSamples(SampleValueVec& sample_vecn, uint32_t num_channels) override;
    private:
        ModuleHandle m_handle;
        ModulesApi*  m_api;
        mutable std::mutex m_mutex;
    };

} // dwcxx
