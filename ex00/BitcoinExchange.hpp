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
    std::map<std::string, double> _database;
    void handleInputFile(std::strign fileName);
    void checkValues(float value);
    bool checkDate(int y, int m, int d);
    bool checkExchangeRate(std::string rate);
}