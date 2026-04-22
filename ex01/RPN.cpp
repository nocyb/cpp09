#include "RPN.hpp"

Rpn::Rpn() {}

Rpn::Rpn(Rpn const &other)
{
    *this = other;
}

Rpn &Rpn::operator=(const Rpn &other)
{
    if (this != &other)
        this->nbStack = other.nbStack;
    return *this;
}

Rpn::~Rpn() {}

void Rpn::calculate(std::string input) {
    for (size_t i = 0; i < input.length(); i++) {
        if (input[i] == ' ')
            continue;
        if (isdigit(input[i])) {
            int value = input[i] - '0';
            nbStack.push(value);
        }
        else {
            if (nbStack.size() < 2) {
                std::cerr << "Error" << std::endl;
                return;
            }
            int b = nbStack.top();
            nbStack.pop();
            int a = nbStack.top();
            nbStack.pop();
            if (input[i] == '/' && b == 0) {
                std::cerr << "Error" << std::endl;
                return;
            }
            if (input[i] == '+')
                nbStack.push(a + b);
            else if (input[i] == '-')
                nbStack.push(a - b);
            else if (input[i] == '*')
                nbStack.push(a * b);
            else if (input[i] == '/')
                nbStack.push(a / b);
        }
    }
    if (nbStack.size() != 1) {
        std::cerr << "Error" << std::endl;
        return;
    }
    std::cout << nbStack.top() << std::endl;
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