#include <iostream>
#include "../include/logger.h"

std::ofstream Logger::s_logfile;
const std::string Logger::LOG_FILE_NAME = "/Users/hamza/Work/programming/SyncIt/syncit.log";

Logger::Logger() {}

void Logger::LogInfo(std::string p_msg)
{
    Logger::CheckLogFileIsOpen();
    Logger::s_logfile << "[INFO] : " << p_msg << std::endl;
}

void Logger::LogError(std::string p_msg)
{
    Logger::CheckLogFileIsOpen();
    Logger::s_logfile << "[ERROR] : " << p_msg << std::endl;
}

void Logger::CheckLogFileIsOpen()
{
    if (Logger::s_logfile.is_open())
        return;
    else
    {
        std::cout << "Opening Log File  : " << Logger::LOG_FILE_NAME << "..." << std::endl;
        Logger::s_logfile.open(Logger::LOG_FILE_NAME, std::ofstream::app);

    }
}

Logger::~Logger()
{
    std::cout << "Destroy" << std::endl;
}