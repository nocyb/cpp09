#pragma once

#include <string>
#include <map>
#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

class BitcoinExchange
{
    public:
    BitcoinExchange();
    ~BitcoinExchange();

    private:
    void handleInputFile(std::strign fileName);
    void checkValues(float value);
    bool checkDate(int y, int m, int d);
}