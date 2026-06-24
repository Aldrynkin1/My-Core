#include "../include/FileLogger.hpp"
#include <filesystem>

Core::FileLogger::FileLogger(const std::string &filename) : filename(filename)
{
    std::filesystem::path filepath(filename);
    std::filesystem::path dirpath = filepath.parent_path();
    if (!dirpath.empty())
    {
        std::filesystem::create_directories(dirpath);
    }
    filestream.open(filename, std::ios::app);
    if (filestream.is_open())
    {
        is_file_open = true;
    }
}

Core::FileLogger::~FileLogger()
{
    if (is_file_open)
    {
        filestream.close();
    }
}

void Core::FileLogger::WriteLogToFile(LogLevel::Level level, const std::string &text)
{
    LogLevel obj{level};
    std::string lvl = std::string(obj.To_string());
    if (!filename.empty())
    {
        if (is_file_open)
        {
            filestream << lvl << " ";
            filestream << text << std::endl
                       << std::endl;
        }
    }
}