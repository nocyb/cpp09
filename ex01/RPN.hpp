#pragma once

#include <string>
#include <map>
#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stack>

class Rpn
{
    public:
    Rpn(std::string input);
    Rpn(Rpn const &other);
    Rpn &operator=(const Rpn &other);
    ~Rpn();

    private:
    stack<int> nbStack;
}

bool parseInput(std::string input);