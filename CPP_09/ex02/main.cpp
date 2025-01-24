#include "PmergeMe.hpp"
#include <cstdlib>

bool isPositiveInteger(const std::string &str) {
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.length(); ++i) {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::vector<int> numbersVector;
    std::deque<int> numbersDeque;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (!isPositiveInteger(arg)) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        
        int num = std::atoi(arg.c_str());
        if (num <= 0) {
            std::cerr << "Error" << std::endl;
            return 1;
        }

        if (argc == 2) {
            std::cout << "Single number: " << num << std::endl;
            return 0;
        }

        numbersVector.push_back(num);
        numbersDeque.push_back(num);
    }

    if (numbersVector.empty() || numbersDeque.empty()) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    PmergeMe sorter;

    sorter.sortAndPrint(numbersVector);
    sorter.sortAndPrint(numbersDeque);

    return 0;
}