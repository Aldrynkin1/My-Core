#pragma once
#include <iostream>
#include <string>
#include <string_view>

namespace Core
{
    struct LogLevel
    {
        enum class Level
        {
            INFO = 1,
            WARNING,
            ERROR,
            FATAL,
        };

        Level value;

        std::string_view To_string() const
        {
            switch (value)
            {
            case Level::INFO:
                return "INFO";
            case Level::WARNING:
                return "WARNING";
            case Level::ERROR:
                return "ERROR";
            case Level::FATAL:
                return "FATAL";
            default:
                return "UNKNOWN";
            }
        }
    };

    class Logger
    {
    private:
    public:
        virtual ~Logger() = default;
        void log(const std::string &message, LogLevel::Level level);
    };
}
