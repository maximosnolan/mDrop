////////////////////////////////////////////////////////////////////////////////
// Copyright Maximos Nolan 2023
////////////////////////////////////////////////////////////////////////////////
// Logger
#pragma once
////////////////////////////////////////////////////////////////////////////////
// Includes

// Utils
#include "../Utils/Singleton.h"

// Standard 
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <sstream>

static constexpr const char * const kLogName = "mDropLog-";

class Logger : public Singleton<Logger>
{
public:
    Logger() = default;
    ~Logger(); 

    void Initialize(const std::string& filename);

    template<typename... Args> 
    void Log(const std::string delimiter, const Args&... args)
    {
        if (mFile.is_open())
        {
            const std::time_t timeNow = Logger::GetCurrentTimeStamp();

            std::string timestamp = std::ctime(&timeNow);

            // Remove trailing new line char 
            timestamp.pop_back();

            std::ostringstream oss; 
            //((oss << args << delimiter), ...);
            AppendWithDelimiter(oss, delimiter, args...); 

            mFile << timestamp << " - " << oss.str() << "\n";
            mFile.flush();  
        }
    }   

    [[nodiscard]] std::time_t GetCurrentTimeStamp() const; 
    [[nodiscard]] std::string GetCurrentTimeStampAsString() const; 

    [[nodiscard]] const std::string GenerateLogFileName() 
    {
        return kLogName + Logger::Instance().GetCurrentTimeStampAsString();
    }

private:
    std::string mFilename; 
    std::ofstream mFile;

    template <typename T>
    void AppendWithDelimiter(std::ostringstream& oss, const std::string& delimiter, const T& arg) {
        oss << arg;
    }

    template <typename T, typename... Args>
    void AppendWithDelimiter(std::ostringstream& oss, const std::string& delimiter, const T& arg, const Args&... args) {
        oss << arg;
        if (sizeof...(args) > 0) 
        {
            oss << delimiter;
        }
        AppendWithDelimiter(oss, delimiter, args...);
    }
};

