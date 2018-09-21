#pragma once

#include <iostream>
#include <string>

namespace logger
{
    class Logger
    {

    public:

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

        void setLevel( const LoggerLevel & level );

        bool isLevelEnabled( const LoggerLevel & level );

        std::string getLevelAsString( );

        bool log( const LoggerLevel & level, const std::string & message );

    private:

        LoggerLevel mLevel;

    };
}