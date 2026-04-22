#pragma once

#include <string>
#include <iostream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <stack>

class Rpn
{
    public:
    Rpn();
    Rpn(Rpn const &other);
    Rpn &operator=(const Rpn &other);
    ~Rpn();
    void calculate(std::string input);

    private:
    std::stack<int> nbStack;
};

bool parseInput(std::string input);