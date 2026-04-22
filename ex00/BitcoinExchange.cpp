#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    std::ifstream data("data.csv");
    if (!data.is_open())
        throw(std::string) "cannot open the database file";
    std::string dataLine;
    getline(data, dataLine);
    if (dataLine != "date,exchange_rate")
        throw(std::string) "wrong format for database file:date ,exchange_rate";
    while (getline(data, dataLine))
    {
        size_t sep = dataLine.find(',');
        if (sep == std::string::npos)
            throw(std::string) "wrong format for database file:date ,exchange_rate";
        std::string datePart = dataLine.substr(0, sep);
        std::string exchangeRatePart = dataLine.substr(sep + 1);
        if (!checkDigits(datePart))
            throw(std::string) "error: only digits and - are allowed in data csv(date)";
        if (!checkExchangeRate(exchangeRatePart))
            throw(std::string) "error: only digits and . are allowed in data csv(exchangerate)";
        double rate = std::atof(exchangeRatePart.c_str());
        _database[datePart] = rate;
    }
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    _database = other._database;
    return *this;
}

BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::handleInputFile(std::string fileName)
{
    std::ifstream inputFile(fileName.c_str());
    if (!inputFile.is_open())
        throw(std::string) "cannot open the input file";
    std::string line;
    getline(inputFile, line);
    if (line != "date | value")
        throw(std::string) "wrong format for input file: expected date | value";
    while (getline(inputFile, line))
    {
        if (line.length() < 14) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        size_t sep = line.find('|');
        if (sep == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string datePart = line.substr(0, 10);
        std::string valuePart = line.substr(sep + 2);
        if (datePart.length() != 10) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (datePart[4] != '-' || datePart[7] != '-') {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (!checkDigits(datePart)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string year = datePart.substr(0, 4);
        std::string month = datePart.substr(5, 2);
        std::string day = datePart.substr(8, 2);
        int y = std::atoi(year.c_str());
        int m = std::atoi(month.c_str());
        int d = std::atoi(day.c_str());
        if (!checkDate(y, m, d)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (valuePart[1] != ' ') {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        double value = std::atof(valuePart.c_str());
        if (value < 0) {
            std::cout << "Error: not a positive number.";
            continue;
        }
        if (value > 1000) {
            std::cout << "Error: too large a number.";
            continue;
        }
        std::map<std::string, double>::iterator it = _database.lower_bound(datePart);
        if (it != _database.end() && it->first == datePart) {
            std::cout << datePart << " => " << value << " = " << (value * it->second) << std::endl;
        }
        else if (it == _database.begin())
            std::cout << "Error: bad input " << datePart <<  " (too old)" << std::endl;
        else
        {
            it--;
            std::cout << datePart << " => " << value << " = " << (value * it->second) << std::endl;
        }
    }
}

bool BitcoinExchange::checkDate(int y, int m, int d) {
    if (y < 0 || y > 9999 || m < 0 || m > 12 || d < 1)
        return false;
    int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
        months[1] = 29;
    if (d > months[m -1])
        return false;
    return true;
}

bool BitcoinExchange::checkDigits(std::string date) {
    int i = 0;
    while (date[i])
    {
        if (!std::isdigit(date[i]))
        {
            if (date[i] == '-')
                continue;
            else
                return false;
        }
        i++;
    }
    return true;
}

bool BitcoinExchange::checkExchangeRate(std::string rate)
{
    int i = 0;
    while(rate[i])
    {
        if (!std::isdigit(rate[i]))
        {
            if (rate[i] == '.')
                continue;
            else
                return false;
        }
        i++;
    }
    return true;
}