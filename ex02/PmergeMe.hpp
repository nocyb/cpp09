#pragma once

#include <string>
#include <iostream>
#include <string>
#include <cstlib>

class PmergeMe
{
    public:
    PmergeMe();
    PmergeMe(PmergeMe const &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    private:
};