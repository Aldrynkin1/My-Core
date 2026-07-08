#include "../include/ConsoleWriterColors.hpp"
#include "../include/Logger.hpp"

void test_colors_and_text_style() {
    Core::ConsoleWriterColors colors(Core::ConsoleColor::Green, Core::ConsoleColor::Black, Core::ConsoleTextStyle::UnderLine);
    Core::Logger logger;
    std::string log_text = colors.color + "red on white" + std::string(Core::ConsoleWriterColors::reset);

    logger.log(log_text, Core::LogLevel::Level::INFO);
}