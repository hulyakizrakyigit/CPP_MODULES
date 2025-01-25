#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include <algorithm>

class PmergeMe {
private:
    std::vector<int> vector;
    std::deque<int> deque;
    
    void mergeInsertSortVector(std::vector<int>& v);
    void mergeInsertSortDeque(std::deque<int>& d);
    std::vector<int> generateJacobsthalNumbers(int n);

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    bool processInput(int argc, char** argv);
    void sortAndDisplay();
};

#endif