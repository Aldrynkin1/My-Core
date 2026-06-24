#include <exception>
#include <string>

namespace Core
{
    class MyException : public std::exception
    {
    private:
        std::string error_message;

    public:
        explicit MyException(const std::string &msg);
        ~MyException();

        const char *what() const noexcept override
        {
            return error_message.c_str();
        }
    };
}
