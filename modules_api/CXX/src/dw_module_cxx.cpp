// Copyright (c) DEWETRON GmbH 2015

#include "dw_module_cxx.h"
#include "dw_modules_api_cxx.h"
#include "dw_modules_c_command.h"
#include "dw_modules_c_error.h"

#define DW_MODULES_NO_API_INJECTION
#include "dw_modules_load.h"

#include "dw_config.h"
#include "uni_assert.h"
#include "uni_logger.h"
#include <sstream>

#ifdef USE_BOOST
#include <boost/lexical_cast.hpp>
#endif

LOG_GROUP_DEFINE(dwmodcxx)

// default handle to access api instead of modules
ModuleHandle API_HANDLE = reinterpret_cast<ModuleHandle>(-1);


namespace dwcxx
{

    ModuleCxx::ModuleCxx(ModuleHandle handle, ModulesApi* api)
        : m_handle(handle)
        , m_api(api)
    {
        UNI_ASSERT(m_handle != nullptr);
        UNI_ASSERT(m_api != nullptr);
    }


    std::string ModuleCxx::getModuleName() const
    {
        dw_std::lock_guard<dw_std::mutex> lck(m_mutex);
        int ret = DW_SUCCESS;
        std::string buffer;
        uint32_t bufferlen = 0;

        if (DW_SUCCESS == (ret = DwModApi::DeWeGetParamStrLen(m_handle, "AllProp", "@Name", &bufferlen)))
        {
            UNI_ASSERT(bufferlen < 100); // just to catch -1 or other bogus returns in test
            if (bufferlen)
            {
                // strlen type return omits "\0"
                buffer.resize(bufferlen);
                buffer.reserve(bufferlen + 1);

                if (DW_SUCCESS != (ret = DwModApi::DeWeGetParamStr(m_handle, "AllProp", "@Name", &(*buffer.begin()), bufferlen + 1)))
                {
                    UNILOG_ERROR(dwmodcxx, "getModuleName: " << DwErrorStr(ret));
                    return std::string();
                }
                UNI_ASSERT(bufferlen == buffer.size());
            }
        }
        else
        {
            UNILOG_ERROR(dwmodcxx, "getModuleName: " << DwErrorStr(ret));
        }
        return buffer;
    }

    uint32_t ModuleCxx::getModuleID() const
    {
        dw_std::lock_guard<dw_std::mutex> lck(m_mutex);
        int ret = DW_SUCCESS;
        std::string buffer;
        uint32_t bufferlen = 0;

        if (DW_SUCCESS == (ret = DwModApi::DeWeGetParamStrLen(m_handle, "AllProp", "@Type", &bufferlen)))
        {
            UNI_ASSERT(bufferlen < 100); // just to catch -1 or other bogus returns in test
            if (bufferlen)
            {
                // strlen type return omits "\0"
                buffer.resize(bufferlen);
                buffer.reserve(bufferlen + 1);

                if (DW_SUCCESS != (ret = DwModApi::DeWeGetParamStr(m_handle, "AllProp", "@Type", &(*buffer.begin()), bufferlen + 1)))
                {
                    UNILOG_ERROR(dwmodcxx, "getModuleID: " << DwErrorStr(ret));
                    return static_cast<uint32_t>(0xFF);
                }
                UNI_ASSERT(bufferlen == buffer.size());

#ifdef USE_BOOST
                try
                {
                    return boost::lexical_cast<uint32_t>(buffer);
                }
                catch (boost::bad_lexical_cast* /* e */)
                {
                    return static_cast<uint32_t>(0xFF);
                }
#else

#ifdef USE_CXX17
                return std::stoi(buffer);
#else
# error Select USE_CXX17 or USE_BOOST
#endif // USE_CXX17

#endif // USE_BOOST
            }
        }
        else
        {
            UNILOG_ERROR(dwmodcxx, "getModuleID: " << DwErrorStr(ret));
        }

        return static_cast<uint32_t>(0xFF);
    }

    uint32_t ModuleCxx::getModuleAddress() const
    {
        dw_std::lock_guard<dw_std::mutex> lck(m_mutex);
        int ret = DW_SUCCESS;
        uint32_t address = static_cast<uint32_t>(-1);
        std::string buffer;
        uint32_t bufferlen = 0;

        if (DW_SUCCESS == (ret = DwModApi::DeWeGetParamStrLen(m_handle, "CurrProp", "Address", &bufferlen)))
        {
            UNI_ASSERT(bufferlen < 100); // just to catch -1 or other bogus returns in test
            if (bufferlen)
            {
                // strlen type return omits "\0"
                buffer.resize(bufferlen);
                buffer.reserve(bufferlen + 1);

                if (DW_SUCCESS != (ret = DwModApi::DeWeGetParamStr(m_handle, "CurrProp", "Address", &(*buffer.begin()), bufferlen + 1)))
                {
                    UNILOG_ERROR(dwmodcxx, "getModuleAddress: " << DwErrorStr(ret));            
                    return static_cast<uint32_t>(-1);
                }
                UNI_ASSERT(bufferlen == buffer.size());

#ifdef USE_BOOST
                try
                {
                    return boost::lexical_cast<uint32_t>(buffer);
                }
                catch (boost::bad_lexical_cast* /* e */)
                {
                    return static_cast<uint32_t>(-1);
                }
#else

#ifdef USE_CXX17
                return std::stoi(buffer);
#else
# error Select USE_CXX17 or USE_BOOST
#endif // USE_CXX17

#endif // USE_BOOST
            }
        }
        else
        {
            UNILOG_ERROR(dwmodcxx, "getModuleAddress: " << DwErrorStr(ret));            
        }

        return address;
    }

    std::string ModuleCxx::getModuleTypename() const
    {
        dw_std::lock_guard<dw_std::mutex> lck(m_mutex);
        int ret = DW_SUCCESS;
        std::string buffer;
        uint32_t bufferlen = 0;

        if (DW_SUCCESS == (ret = DwModApi::DeWeGetParamStrLen(m_handle, "AllProp", "@ModuleType", &bufferlen)))
        {
            UNI_ASSERT(bufferlen < 100); // just to catch -1 or other bogus returns in test
            if (bufferlen)
            {
                // strlen type return omits "\0"
                buffer.resize(bufferlen);
                buffer.reserve(bufferlen + 1);

                if (DW_SUCCESS != (ret = DwModApi::DeWeGetParamStr(m_handle, "AllProp", "@ModuleType", &(*buffer.begin()), bufferlen + 1)))
                {
                    UNILOG_ERROR(dwmodcxx, "getModuleTypename: " << DwErrorStr(ret));
                    return std::string();
                }
                UNI_ASSERT(bufferlen == buffer.size());
            }
        }
        else
        {
            UNILOG_ERROR(dwmodcxx, "getModuleTypename: " << DwErrorStr(ret));
        }
        return buffer;
    }

    bool ModuleCxx::setParamStr(const std::string& prop_source, const std::string& cmd_path, const std::string& var)
    {
        dw_std::lock_guard<dw_std::mutex> lck(m_mutex);
        int ret = DW_SUCCESS;
        if (DW_SUCCESS != (ret = DwModApi::DeWeSetParamStr(m_handle, prop_source.c_str(), cmd_path.c_str(), var.c_str())))
        {
            UNILOG_ERROR(dwmodcxx, "setParamStr: " << DwErrorStr(ret));
            return false;
        }
        return true;
    }

    bool ModuleCxx::getParamStr(const std::string& prop_source, const std::string& cmd_path, std::string& var)
    {
        dw_std::lock_guard<dw_std::mutex> lck(m_mutex);
        int ret = DW_SUCCESS;
        uint32_t bufferlen = 0;

        if (DW_SUCCESS == (ret = DwModApi::DeWeGetParamStrLen(m_handle, prop_source.c_str(), cmd_path.c_str(), &bufferlen)))
        {
            UNI_ASSERT(bufferlen < 100000); // just to catch -1 or other bogus returns in test
            if (bufferlen)
            {
                // strlen type return omits "\0"
                var.resize(bufferlen);
                var.reserve(bufferlen + 1);

                if (DW_SUCCESS != (ret = DwModApi::DeWeGetParamStr(m_handle, prop_source.c_str(), cmd_path.c_str(), &(*var.begin()), bufferlen + 1)))
                {
                    UNILOG_ERROR(dwmodcxx, "getParamStr: " << DwErrorStr(ret));
                    var.clear();
                    return false;
                }

                UNI_ASSERT(bufferlen == var.size());

                return true;
            }
        }
        else
        {
            UNILOG_ERROR(dwmodcxx, "getParamStr: " << DwErrorStr(ret));
        }
        return false;
    }

    bool ModuleCxx::getParamXML(const std::string& prop_source, const std::string& cmd_path, std::string& var)
    {
        dw_std::lock_guard<dw_std::mutex> lck(m_mutex);
        int ret = DW_SUCCESS;
        uint32_t bufferlen = 0;

        if (DW_SUCCESS == (ret = DwModApi::DeWeGetParamXMLLen(m_handle, prop_source.c_str(), cmd_path.c_str(), &bufferlen)))
        {
            UNI_ASSERT(bufferlen < 100000); // just to catch -1 or other bogus returns in test
            if (bufferlen)
            {
                // strlen type return omits "\0"
                var.resize(bufferlen);
                var.reserve(bufferlen + 1);

                if (DW_SUCCESS != (ret = DwModApi::DeWeGetParamXML(m_handle, prop_source.c_str(), cmd_path.c_str(), &(*var.begin()), bufferlen + 1)))
                {
                    UNILOG_ERROR(dwmodcxx, "getParamXML: " << DwErrorStr(ret));
                    var.clear();
                    return false;
                }

                UNI_ASSERT(bufferlen == var.size());
                return true;
            }
        }
        else
        {
            UNILOG_ERROR(dwmodcxx, "getParamXML: " << DwErrorStr(ret));
        }

        return false;
    }

    bool ModuleCxx::setParam_i32(uint32_t command, int val)
    {
        dw_std::lock_guard<dw_std::mutex> lck(m_mutex);
        int ret = DW_SUCCESS;
        if (DW_SUCCESS == (ret = DwModApi::DeWeSetParam_i32(m_handle, command, val)))
        {
            return true;
        }
        UNILOG_ERROR(dwmodcxx, "setParam_i32: " << DwErrorStr(ret));
        return false;
    }

    bool ModuleCxx::getParam_i32(uint32_t command, int* val)
    {
        dw_std::lock_guard<dw_std::mutex> lck(m_mutex);
        int ret = DW_SUCCESS;
        if (DW_SUCCESS == (ret = DwModApi::DeWeGetParam_i32(m_handle, command, val)))
        {
            return true;
        }
        UNILOG_ERROR(dwmodcxx, "getParam_i32: " << DwErrorStr(ret));
        return false;
    }

    bool ModuleCxx::applyParam()
    {
        dw_std::lock_guard<dw_std::mutex> lck(m_mutex);
        int ret = DW_SUCCESS;
        if (DW_SUCCESS == (ret = DwModApi::DeWeSetParam_i32(m_handle, DWCMD_APPLY_PARAM, 0)))
        {
            return true;
        }
        UNILOG_ERROR(dwmodcxx, "applyParam: " << DwErrorStr(ret));
        return false;
    }


    bool ModuleCxx::setChannelParamStr(const std::string& prop_source, uint32_t ch_idx, const std::string& sub_path, const std::string& var)
    {
        dw_std::lock_guard<dw_std::mutex> lck(m_mutex);
        int ret = DW_SUCCESS;
        std::stringstream ss;
        // Note: xpath idx == ch_idx + 1
        ss << "Channel[" << ch_idx + 1 << "]/" << sub_path;
        std::string cmd_path = ss.str();

        if (DW_SUCCESS != (ret = DwModApi::DeWeSetParamStr(m_handle, prop_source.c_str(), cmd_path.c_str(), var.c_str())))
        {
            UNILOG_ERROR(dwmodcxx, "setChannelParamStr: " << DwErrorStr(ret));
            return false;
        }
        return true;
    }


    bool ModuleCxx::getChannelParamStr(const std::string& prop_source, uint32_t ch_idx, const std::string& sub_path, std::string& var)
    {
        dw_std::lock_guard<dw_std::mutex> lck(m_mutex);
        int ret = DW_SUCCESS;
        uint32_t bufferlen = 0;

        std::stringstream ss;
        // Note: xpath idx == ch_idx + 1
        ss << "Channel[" << ch_idx + 1 << "]/" << sub_path;
        std::string cmd_path = ss.str();

        if (DW_SUCCESS == (ret = DwModApi::DeWeGetParamStrLen(m_handle, prop_source.c_str(), cmd_path.c_str(), &bufferlen)))
        {
            UNI_ASSERT(bufferlen < 100000); // just to catch -1 or other bogus returns in test
            if (bufferlen)
            {
                // strlen type return omits "\0"
                var.resize(bufferlen);
                var.reserve(bufferlen + 1);

                if (DW_SUCCESS != (ret = DwModApi::DeWeGetParamStr(m_handle, prop_source.c_str(), cmd_path.c_str(), &(*var.begin()), bufferlen + 1)))
                {
                    UNILOG_ERROR(dwmodcxx, "getChannelParamStr: " << DwErrorStr(ret));
                    var.clear();
                    return false;
                }

                UNI_ASSERT(bufferlen == var.size());

                return true;
            }
        }
        else
        {
            UNILOG_ERROR(dwmodcxx, "getChannelParamStr: " << DwErrorStr(ret));
        }

        return false;
    }

    bool ModuleCxx::getChannelParamXML(const std::string& prop_source, uint32_t ch_idx, const std::string& sub_path, std::string& var)
    {
        dw_std::lock_guard<dw_std::mutex> lck(m_mutex);
        int ret = DW_SUCCESS;
        uint32_t bufferlen = 0;

        std::stringstream ss;
        // Note: xpath idx == ch_idx + 1
        ss << "Channel[" << ch_idx + 1 << "]/" << sub_path;
        std::string cmd_path = ss.str();

        if (DW_SUCCESS == (ret = DwModApi::DeWeGetParamXMLLen(m_handle, prop_source.c_str(), cmd_path.c_str(), &bufferlen)))
        {
            UNI_ASSERT(bufferlen < 100000); // just to catch -1 or other bogus returns in test
            if (bufferlen)
            {
                // strlen type return omits "\0"
                var.resize(bufferlen);
                var.reserve(bufferlen + 1);

                if (DW_SUCCESS != (ret = DwModApi::DeWeGetParamXML(m_handle, prop_source.c_str(), cmd_path.c_str(), &(*var.begin()), bufferlen + 1)))
                {
                    UNILOG_ERROR(dwmodcxx, "getChannelParamXML: " << DwErrorStr(ret));
                    var.clear();
                    return false;
                }

                UNI_ASSERT(bufferlen == var.size());

                return true;
            }
        }
        else
        {
            UNILOG_ERROR(dwmodcxx, "getChannelParamXML: " << DwErrorStr(ret));
        }
        
        return false;
    }

    bool ModuleCxx::getSamples(SampleValueVec& sample_vec, uint32_t num_channels)
    {
        // dont mutex here
        int ret = DW_SUCCESS;
        sample_vec.resize(num_channels);

        if (DW_SUCCESS != (ret = DwModApi::DeWeGetParam_Ptr(m_handle,
            DWCMD_SAMPLES,
            &(sample_vec[0]),
            static_cast<uint32_t>(sample_vec.size() * sizeof(SampleValueVec::value_type)))
            ))
        {
            UNILOG_ERROR(dwmodcxx, "getSamples: " << DwErrorStr(ret));
            sample_vec.clear();
            return false;
        }

        return true;
    }
} // dwcxxl
