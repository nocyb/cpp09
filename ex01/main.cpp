#include "RPN.hpp"

int main(int argc, char **argv) {
    if (!parseInput(argv[1])) {
        std::stderr << "Error" << std::endl;
        return 1;
    }
    return 0;
}
