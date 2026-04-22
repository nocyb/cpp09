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
    BitcoinExchange(BitcoinExchange const &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();
    void handleInputFile(std::string fileName);

    private:
    std::map<std::string, double> _database;
    void checkValues(float value);
    bool checkDate(int y, int m, int d);
    bool checkExchangeRate(std::string rate);
    bool checkDigits(std::string date);
};