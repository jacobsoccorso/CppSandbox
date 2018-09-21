#define _CRT_SECURE_NO_WARNINGS
#include "Logger.h"
#include <iostream>
#include <string>
#include <ctime>
#include <memory>

namespace logger
{
    // Default constructor
    Logger::Logger( )
        : mLevel( Logger::DEBUG )
    {
    }

    // Constructor setting a LoggerLevel
    Logger::Logger( const LoggerLevel & level )
        : mLevel(level)
    {
    }

    // Destructor
    Logger::~Logger()
    {

    }

    // Set the log level
    void Logger::setLevel(const LoggerLevel & level)
    {
        mLevel = level;
    }

    // Check if a log level is enabled
    bool Logger::isLevelEnabled(const LoggerLevel & level)
    {
        if (level == LoggerLevel::ERROR)
        {
            // ERROR logs are enabled if log level is set to ERROR, WARN, INFO or DEBUG
            return (mLevel == LoggerLevel::ERROR || mLevel == LoggerLevel::WARN || mLevel == LoggerLevel::INFO || mLevel == LoggerLevel::DEBUG);
        }

        if (level == LoggerLevel::WARN)
        {
            // WARN logs are enabled if log level is set to WARN, INFO or DEBUG
            return (mLevel == LoggerLevel::WARN || mLevel == LoggerLevel::INFO || mLevel == LoggerLevel::DEBUG);
        }

        if (level == LoggerLevel::INFO)
        {
            // INFO logs are enabled if log level is set to INFO or DEBUG
            return (mLevel == LoggerLevel::INFO || mLevel == LoggerLevel::DEBUG);
        }

        if (level == LoggerLevel::DEBUG)
        {
            // DEBUG logs are enabled if log level is set to DEBUG
            return (mLevel == LoggerLevel::DEBUG);
        }

        // Should never get here, just return false
        return false;
    }

    // Returns a std::string representation of the current log level
    std::string Logger::getLevelAsString( )
    {
        switch (mLevel)
        {
        case LoggerLevel::DEBUG :
            return "DEBUG";
            break;
        case LoggerLevel::INFO :
            return "DEBUG";
            break;
        case LoggerLevel::WARN :
            return "DEBUG";
            break;
        case LoggerLevel::ERROR :
            return "DEBUG";
            break;
        }

        return "UNKNOWN";
    }

    /*
    * Attempt to log a message at a given level.
    * Returns a bool indicate if logging was successful.
    */
    bool Logger::log(const LoggerLevel & level, const std::string & message)
    {
        if (!isLevelEnabled(level))
        {
            return false;
        }

        /*std::time_t currentTime = std::time(nullptr);
        std::unique_ptr<tm> gmtm( std::gmtime(&currentTime) );
        char* dt = std::asctime( gmtm.get() );*/
        
        std::cout << /*gmtm->tm_year << " " <<*/ getLevelAsString() << ": " << message << std::endl;

        return true;
    }
}