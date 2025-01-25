#include "PmergeMe.hpp"
#include <cstdlib>
#include <climits>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        this->vector = other.vector;
        this->deque = other.deque;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::processInput(int argc, char** argv) {
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        for (size_t j = 0; j < arg.length(); j++) {
            if (!isdigit(arg[j])) {
                std::cerr << "Error" << std::endl;
                return false;
            }
        }
        
        long num = std::atol(argv[i]);
        if (num <= 0 || num > INT_MAX) {
            std::cerr << "Error" << std::endl;
            return false;
        }
        // single number?
        
        vector.push_back(static_cast<int>(num));
        deque.push_back(static_cast<int>(num));
    }
    
    if (vector.empty()) {
        std::cerr << "Error" << std::endl;
        return false;
    }
    return true;
}

std::vector<int> PmergeMe::generateJacobsthalNumbers(int n) {
    std::vector<int> jacobsthal;
    if (n <= 0) return jacobsthal;
    
    jacobsthal.push_back(0);
    if (n == 1) return jacobsthal;
    
    jacobsthal.push_back(1);
    for (int i = 2; i < n; i++) {
        jacobsthal.push_back(jacobsthal[i-1] + 2 * jacobsthal[i-2]);
    }
    return jacobsthal;
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& arr) {
    if (arr.size() <= 1) return;

    // 1. Çiftleri oluştur ve sırala
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size() - 1; i += 2) {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    // Tek eleman kalırsa
    int lastElement = -1;
    if (arr.size() % 2)
        lastElement = arr[arr.size() - 1];

    // 2. Çiftleri büyük elemana göre sırala
    for (size_t i = 1; i < pairs.size(); i++) {
        std::pair<int, int> key = pairs[i];
        int j = i - 1;
        while (j >= 0 && pairs[j].first > key.first) {
            pairs[j + 1] = pairs[j];
            j--;
        }
        pairs[j + 1] = key;
    }

    // 3. Ana zinciri oluştur
    std::vector<int> mainChain;
    std::vector<int> pend;
    for (size_t i = 0; i < pairs.size(); i++) {
        mainChain.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }

    // 4. İlk elemanı ekle
    mainChain.insert(mainChain.begin(), pend[0]);
    pend.erase(pend.begin());

    // 5. Jacobsthal sayılarını kullanarak insertion
    std::vector<int> jacobsthal = generateJacobsthalNumbers(pend.size() + 1);
    std::vector<bool> inserted(pend.size(), false);
    
    for (size_t i = 1; i < jacobsthal.size(); i++) {
        int idx = jacobsthal[i];
        while (idx > 0 && idx <= (int)pend.size()) {
            if (!inserted[idx - 1]) {
                int elem = pend[idx - 1];
                std::vector<int>::iterator insertPos = 
                    std::lower_bound(mainChain.begin(), mainChain.end(), elem);
                mainChain.insert(insertPos, elem);
                inserted[idx - 1] = true;
            }
            idx--;
        }
    }

    // Kalan elemanları ekle
    for (size_t i = 0; i < inserted.size(); i++) {
        if (!inserted[i]) {
            int elem = pend[i];
            std::vector<int>::iterator insertPos = 
                std::lower_bound(mainChain.begin(), mainChain.end(), elem);
            mainChain.insert(insertPos, elem);
        }
    }

    // Son tek elemanı ekle (varsa)
    if (lastElement != -1) {
        std::vector<int>::iterator insertPos = 
            std::lower_bound(mainChain.begin(), mainChain.end(), lastElement);
        mainChain.insert(insertPos, lastElement);
    }

    arr = mainChain;
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr) {
    if (arr.size() <= 1) return;

    // 1. Çiftleri oluştur ve sırala
    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size() - 1; i += 2) {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    // Tek eleman kalırsa
    int lastElement = -1;
    if (arr.size() % 2)
        lastElement = arr[arr.size() - 1];

    // 2. Çiftleri büyük elemana göre sırala
    for (size_t i = 1; i < pairs.size(); i++) {
        std::pair<int, int> key = pairs[i];
        int j = i - 1;
        while (j >= 0 && pairs[j].first > key.first) {
            pairs[j + 1] = pairs[j];
            j--;
        }
        pairs[j + 1] = key;
    }

    // 3. Ana zinciri oluştur
    std::deque<int> mainChain;
    std::deque<int> pend;
    for (size_t i = 0; i < pairs.size(); i++) {
        mainChain.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }

    // 4. İlk elemanı ekle
    mainChain.push_front(pend.front());
    pend.pop_front();

    // 5. Jacobsthal sayılarını kullanarak insertion
    std::vector<int> jacobsthal = generateJacobsthalNumbers(pend.size() + 1);
    std::vector<bool> inserted(pend.size(), false);
    
    for (size_t i = 1; i < jacobsthal.size(); i++) {
        int idx = jacobsthal[i];
        while (idx > 0 && idx <= (int)pend.size()) {
            if (!inserted[idx - 1]) {
                int elem = pend[idx - 1];
                std::deque<int>::iterator insertPos = 
                    std::lower_bound(mainChain.begin(), mainChain.end(), elem);
                mainChain.insert(insertPos, elem);
                inserted[idx - 1] = true;
            }
            idx--;
        }
    }

    // Kalan elemanları ekle
    for (size_t i = 0; i < inserted.size(); i++) {
        if (!inserted[i]) {
            int elem = pend[i];
            std::deque<int>::iterator insertPos = 
                std::lower_bound(mainChain.begin(), mainChain.end(), elem);
            mainChain.insert(insertPos, elem);
        }
    }

    // Son tek elemanı ekle (varsa)
    if (lastElement != -1) {
        std::deque<int>::iterator insertPos = 
            std::lower_bound(mainChain.begin(), mainChain.end(), lastElement);
        mainChain.insert(insertPos, lastElement);
    }

    arr = mainChain;
}

void PmergeMe::sortAndDisplay() {
    std::cout << "Before: ";
    for (size_t i = 0; i < vector.size(); i++) {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;

    clock_t startVector = clock();
    mergeInsertSortVector(vector);
    clock_t endVector = clock();

    clock_t startDeque = clock();
    mergeInsertSortDeque(deque);
    clock_t endDeque = clock();

    std::cout << "After: ";
    for (size_t i = 0; i < vector.size(); i++) {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;

    double vectorTime = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000000;
    double dequeTime = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Time to process a range of " << vector.size() 
              << " elements with std::vector : " << std::fixed << std::setprecision(5) 
              << vectorTime << " μs" << std::endl;
    std::cout << "Time to process a range of " << deque.size() 
              << " elements with std::deque : " << dequeTime << " μs" << std::endl;
}

