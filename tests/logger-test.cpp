#include <iostream>
#include <string>

#include "../include/logger.h"


int main ()
{
    std::cout << "Test My Logger" << std::endl;

//  Logger::LogInfo("Hi");

    Logger::LogInfo("daemon started");
    Logger::LogInfo("waiting . . . ");

    return 0;
}