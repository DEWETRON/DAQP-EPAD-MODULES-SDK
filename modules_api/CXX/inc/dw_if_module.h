// Copyright (c) Dewetron 2013
#ifndef _IF_MODULES_H_
#define _IF_MODULES_H_
#pragma once

#include <inttypes.h>
#include <string>
#include <memory>

namespace dw
{
    /**
     * Abstract interface for Dewetron modules with TEDS support
     */
    //class IfTEDS
    //{
    //public:
    //    virtual ~IfTEDS()
    //    {}

    //    /**
    //     * Retrieves: FamilyCode (2 char hex)
    //     *            Serial (12 char hex)
    //     *            CRC    (2 chars hex)
    //     * or TEDS Error Response
    //     */
    //    bool readTEDSChip();

    //    /**
    //     *
    //     * or TEDS Error Response
    //     */
    //    bool readTEDSE2PROM();

    //    bool writeTEDSE2PROM();

    //    bool readTEDSIOState();

    //    bool writeTEDSIOPin();
    //};


    /**
     * Abstract interface for Dewetron modules.
     */
    class IfModule
    {
    public:
        typedef std::shared_ptr<IfModule> Ptr;

    public:

        virtual ~IfModule()
        {}

        /**
         * Get the name of the module
         * Can be different from the class.
         * @return the modules name
         */
        virtual std::string getModuleName() const = 0;

        /**
         * Get the unique type of the module
         * @return the unique type id of the module.
         */
        virtual uint32_t getModuleID() const = 0;

        /**
         * Get the module address
         * @return the module address
         */
        virtual uint32_t getModuleAddress() const = 0;

        /**
        * setParamStr
        * Set a module parameter (eg change mode, range)
        * @param prop_source select the source document
        * @param prop_expr
        * @param val
        * return true if successful
        */
        virtual bool setParamStr(const std::string& prop_source, const std::string& cmd_path, const std::string& var) = 0;

        /**
        * getParamStr
        * Get a module parameter (eg change mode, range)
        * @param prop_source select the source document
        * @param prop_expr
        * @param val
        * return true if successful
        */
        virtual bool getParamStr(const std::string& prop_source, const std::string& cmd_path, std::string& var) = 0;

        /**
        * getParamXML
        * Get a module parameter (eg change mode, range) in XML format.
        * @param prop_source select the source document
        * @param prop_expr
        * @param val
        * return true if successful
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
         * getParam_Ptr
         * @param command
         * @param val
         * @return true if successful
         */
        virtual bool getParam_Ptr(uint32_t command, void* val, uint32_t size) = 0;


        /**
         * Apply module settings and parameters to the hardware.
         * @return true if successful
         */
        virtual bool applyParam() = 0;
    };

    using IfModulePtr = std::shared_ptr<IfModule>;
    using IfModuleWPtr = std::weak_ptr<IfModule>;

} // dw


#endif // _IF_MODULES_H_
