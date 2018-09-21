#include "Logger.h"
#include <iostream>

int main( int argc, char *argv[] )
{
    // TODO Read in command-line argument as a parameter file

    // Create logger
    logger::Logger logger( logger::Logger::DEBUG );

    // Log a message
    logger.log( logger::Logger::INFO, "Jake was here" );

    return 0;

}
