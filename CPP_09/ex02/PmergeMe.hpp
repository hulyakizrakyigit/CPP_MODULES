#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>

class PmergeMe {
    public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();


    void sortAndPrint(const std::vector<int> &v);
    void sortAndPrint(const std::deque<int> &d);

};


#endif