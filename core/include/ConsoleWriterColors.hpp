#pragma once
#include <iostream>
#include <string>
#include <string_view>

namespace Core
{
    enum class ConsoleTextStyle {
        None, 
        Bold,
        UnderLine,
        ReverseColors,
    };

    enum class ConsoleColor
    {
        Reset,
        Black,
        Red,
        Green,
        Yellow,
        Blue,
        Magenta,
        Cyan,
        White,
        BrightRed,
        BrightGreen,
        BrightYellow,
        BrightBlue,
    };

    class ConsoleWriterColors
    {
    private:
        ConsoleColor backColor;
        ConsoleColor foreColor;
        ConsoleTextStyle textStyle;

        std::string_view get_text_style(ConsoleTextStyle style) const {
            switch (style) {
                case ConsoleTextStyle::Bold:          return "\033[1m";
                case ConsoleTextStyle::UnderLine:     return "\033[4m";
                case ConsoleTextStyle::ReverseColors: return "\033[7m";
                default:                              return ""; 
            }
        }

        std::string_view getForeColorCode(ConsoleColor color) const
        {
            switch (color)
            {
                case ConsoleColor::Black:        return "\033[30m";
                case ConsoleColor::Red:          return "\033[31m";
                case ConsoleColor::Green:        return "\033[32m";
                case ConsoleColor::Yellow:       return "\033[33m";
                case ConsoleColor::Blue:         return "\033[34m";
                case ConsoleColor::Magenta:      return "\033[35m";
                case ConsoleColor::Cyan:         return "\033[36m";
                case ConsoleColor::White:        return "\033[37m";
                case ConsoleColor::BrightRed:    return "\033[91m";
                case ConsoleColor::BrightGreen:  return "\033[92m";
                case ConsoleColor::BrightYellow: return "\033[93m";
                case ConsoleColor::BrightBlue:   return "\033[94m";
                default:                         return "";
            }
        }

        std::string_view getBackColorCode(ConsoleColor color) const
        {
            switch (color)
            {
                case ConsoleColor::Black:   return "\033[40m";
                case ConsoleColor::Red:     return "\033[41m";
                case ConsoleColor::Green:   return "\033[42m";
                case ConsoleColor::Yellow:  return "\033[43m";
                case ConsoleColor::Blue:    return "\033[44m";
                case ConsoleColor::Magenta: return "\033[45m";
                case ConsoleColor::Cyan:    return "\033[46m";
                case ConsoleColor::White:   return "\033[47m";
                default:                    return "";
            }
        }

    public:
        std::string color;
        inline static const std::string_view reset = "\033[0m";

        void setTextStyle(ConsoleTextStyle style);

        ConsoleWriterColors(ConsoleColor back, ConsoleColor fore, ConsoleTextStyle style = ConsoleTextStyle::None);
        ~ConsoleWriterColors() = default;
    };

    inline std::ostream& operator<<(std::ostream& os, const ConsoleWriterColors& config) {
        return os << config.color;
    }
}
