#pragma once

#include "Logger.hpp"
#include <string>
#include <fstream>

namespace Core
{
    class FileLogger : public Logger
    {
    private:
        std::string filename;
        std::ofstream filestream;
        bool is_file_open = false;

    public:
        FileLogger(const std::string &filename);
        ~FileLogger();
        void WriteLogToFile(LogLevel::Level level, const std::string &text);
    };
}
