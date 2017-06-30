#include <iostream>
#include "../include/logger.h"
#include <ctime>

std::ofstream Logger::s_logfile;
const std::string Logger::LOG_FILE_NAME = "/Users/hamza/Work/programming/SyncIt/syncit.log";

Logger::Logger() {}

void Logger::LogInfo(std::string p_msg)
{
    Logger::CheckLogFileIsOpen();
    Logger::s_logfile <<  "[INFO] : " << p_msg << "  ( " << Logger::GetCurrentTime() << " )" <<  std::endl;
}

void Logger::LogError(std::string p_msg)
{
    Logger::CheckLogFileIsOpen();
    Logger::s_logfile <<  "[ERROR] : " << p_msg << "  ( " << Logger::GetCurrentTime() << " )" <<  std::endl;
}

void Logger::CheckLogFileIsOpen()
{
    if (Logger::s_logfile.is_open())
        return;
    else
    {
        std::cout << "Opening Log File  : " << Logger::LOG_FILE_NAME << "..." << std::endl;
        Logger::s_logfile.open(Logger::LOG_FILE_NAME, std::ofstream::app);
        Logger::s_logfile << "--------- " << Logger::GetCurrentDate() << "---------" << std::endl;
    }
}

void Logger::CloseLogFile()
{
    Logger::LogInfo("[LOGGER] : CLOSING LOG FILE ...");
    Logger::s_logfile.close();
}

std::string Logger::GetCurrentDate()
{
    time_t current_time;
    struct tm *local_time;

    time (&current_time);
    local_time = localtime(&current_time);

    std::string ret = std::to_string(local_time->tm_mday);
    ret += "/";
    ret += std::to_string(local_time->tm_mon + 1);
    ret += "/";
    ret += std::to_string(local_time->tm_year + 1900); 

    return ret;
}

std::string Logger::GetCurrentTime()
{
    time_t current_time;
    struct tm *local_time;

    time (&current_time);
    local_time = localtime(&current_time);

    std::string ret = std::to_string(local_time->tm_hour);
    ret += ":";
    ret+= std::to_string(local_time->tm_min);
    ret += ":";
    ret+= std::to_string(local_time->tm_sec);

    return ret;
}

Logger::~Logger()
{
    std::cout << "Destroy" << std::endl;
}