#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    std::ifstream data("data.csv");
    if (!data.is_open())
        throw(std::string) "cannot open the database file";
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
        std::string datePart = line.substr(0, sep);
        std::string valuePart = line.substr(sep + 1);
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
        if (!checkDate(y, m, d) {
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
            if (date[i] == 'i')
                continue;
            else
                return false;
        }
        i++;
    }
    return true;
}