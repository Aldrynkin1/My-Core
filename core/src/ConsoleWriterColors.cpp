#include "../include/ConsoleWriterColors.hpp"
namespace Core
{
    ConsoleWriterColors::ConsoleWriterColors(ConsoleColor back, ConsoleColor fore, ConsoleTextStyle style)
        : backColor(back), foreColor(fore), textStyle(style)
    {
        if (back == ConsoleColor::Reset || fore == ConsoleColor::Reset)
        {
            color = reset;
        }
        else
        {
            color = std::string(get_text_style(textStyle)) +
                    std::string(getBackColorCode(backColor)) +
                    std::string(getForeColorCode(foreColor));
        }
    }

    void ConsoleWriterColors::setTextStyle(ConsoleTextStyle style)
    {
        textStyle = style;
        color = std::string(get_text_style(textStyle)) +
                std::string(getBackColorCode(backColor)) +
                std::string(getForeColorCode(foreColor));
    }
}
