#include "../include/Logger.hpp"
#include "../c_include/include/allocator.h"

void Core::Logger::log(const std::string &message, LogLevel::Level level)
{
    switch (level)
    {
    case LogLevel::Level::INFO:
        std::cout << "[INFO] ";
        break;
    case LogLevel::Level::WARNING:
        std::cout << "[WARNING] ";
        break;
    case LogLevel::Level::ERROR:
        std::cout << "[ERROR] ";
        break;
    case LogLevel::Level::FATAL:
        std::cout << "[FATAL] ";
        break;
    }
    std::cout << message.c_str() << std::endl;
}