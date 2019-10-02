// Copyright (c) DEWETRON GmbH 2015

#ifndef _DW_MODULES_SIM_FWD_H_
#define _DW_MODULES_SIM_FWD_H_
#pragma once

#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

namespace dw
{
    class IfModulesSim;
    typedef boost::shared_ptr<IfModulesSim> IfModulesSimPtr;
    typedef boost::weak_ptr<IfModulesSim> IfModulesSimWPtr;
} // dw


#endif // _DW_MODULES_SIM_FWD_H_
