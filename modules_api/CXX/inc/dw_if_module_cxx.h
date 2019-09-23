// Copyright (c) DEWETRON GmbH 2015
#pragma once

#include "dw_modules_c_command.h"
#include "dw_modules_c_error.h"
#include <inttypes.h>
#include <memory>
#include <string>
#include <vector>

namespace dwcxx
{
    /**
     * Interface to DAQN, DAQP, HSI, PAD, EPAD modules
     */
    class IfModule
    {
    public:
        virtual ~IfModule() = default;

        /**
         * Get the name of the module
         * Can be different from the class.
         * @return the modules name
         */
        virtual std::string getModuleName() const = 0;

        /**
         * Get the unique type id of the module
         * @return the unique type id of the module.
         */
        virtual uint32_t getModuleID() const = 0;

        /**
         * Get the module address
         * @return the module address
         */
        virtual uint32_t getModuleAddress() const = 0;

        /**
         * Get the module type name attribute from XML.
         * "PAD" for PAD, EPAD and EPAD2
         * "DAQP" for DAQP and HSI
         * "DAQN" for DAQN
         */
        virtual std::string getModuleTypename() const = 0;

        /**
        * setParamStr
        * Set a module parameter (eg change mode, range)
        * @param prop_source select the source document
        * @param prop_expr
        * @param val
        * @return true if successful
        */
        virtual bool setParamStr(const std::string& prop_source, const std::string& cmd_path, const std::string& var) = 0;

        /**
        * getParamStr
        * Get a module parameter (eg change mode, range)
        * @param prop_source select the source document
        * @param prop_expr
        * @param val
        * @return true if successful
        */
        virtual bool getParamStr(const std::string& prop_source, const std::string& cmd_path, std::string& var) = 0;

        /**
        * getParamXML
        * Get a module parameter (eg change mode, range) in XML format.
        * @param prop_source select the source document
        * @param prop_expr
        * @param val
        * @return true if successful
        */
        virtual bool getParamXML(const std::string& prop_source, const std::string& cmd_path, std::string& var) = 0;

        /**
         * setParam_i32
         * @param command
         * @param val
         * @return true if successful
         */
        virtual bool setParam_i32(uint32_t command, int val) = 0;

        /**
         * getParam_i32
         * @param command
         * @param val
         * @return true if successful
         */
        virtual bool getParam_i32(uint32_t command, int* val) = 0;

        /**
         * Apply module settings and parameters to the hardware.
         * @return true if successful
         */
        virtual bool applyParam() = 0;


        /**
         * Convenience methods
         */
        /**
         * setParamStr
         * Set a module parameter (eg change mode, range)
         * @param prop_source select the source document
         * @param ch_dx
         * @param prop_expr
         * @param val
         * return true if successful
         */
        virtual bool setChannelParamStr(const std::string& prop_source, uint32_t ch_idx, const std::string& cmd_path, const std::string& var) = 0;

        /**
         * getParamStr
         * Get a module parameter (eg change mode, range)
         * @param prop_source select the source document
         * @param ch_dx
         * @param prop_expr
         * @param val
         * return true if successful
         */
        virtual bool getChannelParamStr(const std::string& prop_source, uint32_t ch_idx, const std::string& cmd_path, std::string& var) = 0;

        virtual bool getChannelParamXML(const std::string& prop_source, uint32_t ch_idx, const std::string& cmd_path, std::string& var) = 0;


        using SampleValueVec = std::vector<double>;
        virtual bool getSamples(SampleValueVec& sample_vec, uint32_t num_channels) = 0;
    };


    typedef std::shared_ptr<IfModule> IfModulePtr;
    typedef std::weak_ptr<IfModule> IfModuleWPtr;


} // dwxcc

