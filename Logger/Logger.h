#pragma once

#include <iostream>
#include <fstream>
#include <string>

namespace logger
{
    class Logger
    {

    public:

        // All available log levels
        enum LoggerLevel
        {
            DEBUG,
            INFO,
            WARN,
            ERROR
        };
        
        // Constructors
        Logger( );
        Logger( const LoggerLevel & level);

        // Destructor
        ~Logger( );

        // Set log level
        void setLevel( const LoggerLevel & level );

        // Check if a log level is enabled
        bool isLevelEnabled( const LoggerLevel & level );

        // Get a string representation of the log level
        std::string getLevelAsString( );

        // Attempt to log a string message at a log level
        bool log( const LoggerLevel & level, const std::string & message );

    private:

        // Log level
        LoggerLevel mLevel;

        // Output file stream
        std::ofstream mLogFile;

    };
}