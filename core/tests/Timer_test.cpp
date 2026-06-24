#include "../include/MyCore.hpp"

void test_timer() {
    Core::Logger logger;
    Core::Timer timer("pip", logger);

    logger.log("Timer has been ended succsess", Core::LogLevel::Level::INFO);
}