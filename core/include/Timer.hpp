#pragma once
#include <iostream>
#include <utility>
#include <chrono>
#include <string>
#include "Logger.hpp"

namespace Core
{
    class Logger;

    class Timer
    {
    private:
        std::string m_name;
        std::chrono::time_point<std::chrono::high_resolution_clock> m_start_time;
        Logger &m_logger;

    public:
        Timer(const std::string &name, Logger &logger);
        ~Timer();
    };

}