////////////////////////////////////////////////////////////////////////////////
// Copyright Maximos Nolan 2023
////////////////////////////////////////////////////////////////////////////////
// Singleton.h

#pragma once

////////////////////////////////////////////////////////////////////////////////
// Includes

#include <mutex>

template<typename T>
class Singleton
{
public:

    // Used in non MT instances
    [[nodiscard]] static T& Instance()
    {
        static T instance;
        return instance;
    }

    [[nodiscard]] static T& ThreadSafeInstance()
    {
        static std::mutex mutex;
        std::lock_guard<std::mutex> lock(mutex);
        static T instance;
        return instance;
    }
protected:
    Singleton() {}
    ~Singleton() {}

private:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};
