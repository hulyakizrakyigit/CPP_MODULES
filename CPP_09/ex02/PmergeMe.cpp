#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
    (void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {}
    return *this;
}

PmergeMe::~PmergeMe() {}

template <typename T>
void mergeInsertSort(T &container) {
    if (container.size() <= 1)
        return; // error?
    
    size_t mid = container.size() / 2;
    T left(container.begin(), container.begin() + mid);
    T right(container.begin() + mid, container.end());

    mergeInsertSort(left);
    mergeInsertSort(right);

    typename T::iterator it = container.begin();
    typename T::iterator it_left = left.begin();
    typename T::iterator it_right = right.begin();

    while (it_left != left.end() && it_right != right.end()) {
        if (*it_left < *it_right) {
            *it = *it_left;
            ++it_left;
        } else {
            *it = *it_right;
            ++it_right;
        }
        ++it;
    }

    while (it_left != left.end()) {
        *it = *it_left;
        ++it_left;
        ++it;
    }

    while (it_right != right.end()) {
        *it = *it_right;
        ++it_right;
        ++it;
    }
}

void PmergeMe::sortAndPrint(const std::vector<int> &v) {
    std::vector<int> sorted(v);

    std::cout << "BEFORE:" << std::endl;
    for (size_t i = 0; i < sorted.size(); ++i)
        std::cout << sorted[i] << " ";
    std::cout << std::endl;

    clock_t start = clock();
    mergeInsertSort(sorted);
    clock_t end = clock();

    std::cout << "AFTER:" << std::endl;
    for (size_t i = 0; i < sorted.size(); ++i)
        std::cout << sorted[i] << " ";
    std::cout << std::endl;
    
    double time_spent = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
    std::cout << "Time to process a range of " << sorted.size() << " elementd with std::vector: " << time_spent << " µs" << std::endl;
}

void PmergeMe::sortAndPrint(const std::deque<int> &d) {
    std::deque<int> sorted(d);

    clock_t start = clock();
    mergeInsertSort(sorted);
    clock_t end = clock();
    
    double time_spent = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
    std::cout << "Time to process a range of " << sorted.size() << " elementd with std::deque: " << time_spent << " µs" << std::endl;
}