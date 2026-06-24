#include "../include/Logger.hpp"
#include "../include/FileLogger.hpp"
void test_log() {
    Core::Logger logger;
    std::string a = "myCore";

    if (a == "myCore") {
        logger.log("Fatal error", Core::LogLevel::Level::FATAL);
    } else {
        logger.log("Some info", Core::LogLevel::Level::INFO);
    }
}

void test_file_create() {
    std::string workpath = std::string(PROJECT_ROOT_DIR);
    Core::FileLogger filelogger(workpath + "/logs/logs.log");
    filelogger.WriteLogToFile(Core::LogLevel::Level::INFO, "Logger add log to file");
    filelogger.WriteLogToFile(Core::LogLevel::Level::WARNING, "C++ is hard language");
    filelogger.WriteLogToFile(Core::LogLevel::Level::FATAL, "My brain after C++");
    filelogger.WriteLogToFile(Core::LogLevel::Level::ERROR, "don't create .lib");
}