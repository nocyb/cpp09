#include "RPN.hpp"

Rpn::Rpn(std::string input) {

}

Rpn::Rpn(Rpn const &other)
{
    *this = other;
}

Rpn &Rpn::operator=(const Rpn &other)
{
    void(other);
    return *this;
}

bool parseInput(std::string input)
{
    for (size_t i = 0; i < input.length(); i++) {
        if (!std::isdigit(input[i]) && input[i] != ' ' && input[i] != '+' && input[i] != '-' && 
        input[i] != '/' && input[i] != '*')
            return false;
        if (std::isdigit(input[i]) && i + 1 < input.length() && std::isdigit(input[i + 1]))
            return false;
    }
    return true;
}