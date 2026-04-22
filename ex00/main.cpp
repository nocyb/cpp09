#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    try {
        BitcoinExchange btc;
        btc.handleInputFile(argv[1]);
    } catch (const std::string &e) {
        std::cout << "Error: " << e << std::endl;
        return 1;
    }
    return 0;
}