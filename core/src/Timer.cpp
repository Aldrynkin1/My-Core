#include "../include/Timer.hpp"

namespace Core
{
    Timer::Timer(const std::string &name, Logger &logger)
        : m_name(name), m_logger(logger)
    {
        m_start_time = std::chrono::high_resolution_clock::now();
    }

    Timer::~Timer()
    {
        auto end_time = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - m_start_time).count();

        std::string message = "TIMER: " + m_name + " " + "took " +
                              std::to_string(duration) + " milliseconds";

        m_logger.log(message, Core::LogLevel::Level::INFO);
    }
}