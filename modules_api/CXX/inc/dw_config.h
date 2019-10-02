// Copyright (c) DEWETRON GmbH 2019
#pragma once

#if !defined(USE_BOOST) && !defined(USE_CXX17)
#error Select USE_CXX17 or USE_BOOST
#endif


#ifdef USE_BOOST

#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

#include <boost/thread/mutex.hpp>
#include <boost/thread/shared_mutex.hpp>
#include <boost/thread/lock_guard.hpp> 

#include <boost/make_shared.hpp>

namespace dw_std
{
    using mutex = boost::mutex;
    using shared_mutex = boost::shared_mutex;

    template<class T>
    using shared_ptr = boost::shared_ptr<T>;
    template<class T>
    using weak_ptr = boost::weak_ptr<T>;
    template<class T>
    using shared_lock = boost::shared_lock<T>;
    template<class T>
    using unique_lock = boost::unique_lock<T>;
    template<class T>
    using lock_guard = boost::lock_guard<T>;

    template<class T, class... Args>
    shared_ptr<T> make_shared(Args&& ... args)
    {
        return boost::make_shared<T>(args...);
    }
}

#endif


#ifdef USE_CXX17

#include <memory>
#include <mutex>
#include <shared_mutex>

namespace dw_std
{
    using mutex = std::mutex;
    using shared_mutex = std::shared_mutex;

    template<class T>
    using shared_ptr = std::shared_ptr<T>;
    template<class T>
    using weak_ptr = std::weak_ptr<T>;
    template<class T>
    using shared_lock = std::shared_lock<T>;
    template<class T>
    using unique_lock = std::unique_lock<T>;
    template<class T>
    using lock_guard = std::lock_guard<T>;

    template<class T, class... Args>
    shared_ptr<T> make_shared(Args&&... args)
    {
        return std::make_shared<T>(args...);
    }

}

#endif