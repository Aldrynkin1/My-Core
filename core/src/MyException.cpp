#include "../include/MyException.hpp"

Core::MyException::MyException(const std::string &msg) : error_message(msg) {}

Core::MyException::~MyException()
{
}
