#include "İter.hpp"

template <typename T>
void print(const T &element) {
    std::cout << element << " ";
}

void add(int &i) {
    i += 1;
}

void mul(int &i) {
    i *= 2;
}

void toUpper(std::string &str) {
    for (size_t i = 0; i < str.length(); i++) {
        str[i] = std::toupper(str[i]);
    }
}

void size(std::string &str) {
    std::cout << str.length() << " ";
}


int main()
{
    int tab[] = {0, 1, 2, 3, 4};
    ::iter(tab, 5, print<int>);
    std::cout << std::endl;
    ::iter(tab, 5, add);
    ::iter(tab, 5, print<int>);
    std::cout << std::endl;
    ::iter(tab, 5, mul);
    ::iter(tab, 5, print<int>);
    std::cout << std::endl;

    std::string tab2[] = {"one", "two", "three", "four", "five"};

    ::iter(tab2, 5, print<std::string>);
    std::cout << std::endl;
    ::iter(tab2, 5, toUpper);
    ::iter(tab2, 5, print<std::string>);
    std::cout << std::endl;
    ::iter(tab2, 5, size);
    std::cout << std::endl;

    return 0;
}