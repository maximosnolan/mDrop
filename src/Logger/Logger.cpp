////////////////////////////////////////////////////////////////////////////////
// Copyright Maximos Nolan 2023
////////////////////////////////////////////////////////////////////////////////
// Main

////////////////////////////////////////////////////////////////////////////////
// Includes

#include "Logger.h"

void Logger::Initialize(const std::string& filename)
{
    mFilename = filename;
    mFile.open(mFilename, std::ios_base::app);
    
    if (!mFile.is_open())
    {
        mFile.open(mFilename);
    }
}

Logger::~Logger()
{
    if (mFile.is_open())
    {
        mFile.close();
    }
}

[[nodiscard]] std::time_t Logger::GetCurrentTimeStamp() const 
{
    auto now = std::chrono::system_clock::now();
    return std::chrono::system_clock::to_time_t(now);
}

[[nodiscard]] std::string Logger::GetCurrentTimeStampAsString() const
{
    const std::time_t timeNow = Logger::GetCurrentTimeStamp();
    std::string stringTimeNow = std::ctime(&timeNow);

    // Remove extranious new line char
    stringTimeNow.pop_back();

    return stringTimeNow; 
}