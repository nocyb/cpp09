#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: Usage ./RPN \"expression\"" << std::endl;
        return 1;
    }
    if (!parseInput(argv[1])) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    Rpn calcResult;
    calcResult.calculate(argv[1]);
    return 0;
}