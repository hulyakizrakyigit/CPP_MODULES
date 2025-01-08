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
    ::iter(tab, arrayLength(tab), print<int>);
    std::cout << std::endl;
    ::iter(tab, arrayLength(tab), add);
    ::iter(tab, arrayLength(tab), print<int>);
    std::cout << std::endl;
    ::iter(tab, arrayLength(tab), mul);
    ::iter(tab, arrayLength(tab), print<int>);
    std::cout << std::endl;

    std::string tab2[] = {"one", "two", "three", "four", "five"};

    ::iter(tab2, arrayLength(tab2), print<std::string>);
    std::cout << std::endl;
    ::iter(tab2, arrayLength(tab2), toUpper);
    ::iter(tab2, arrayLength(tab2), print<std::string>);
    std::cout << std::endl;
    ::iter(tab2, arrayLength(tab2), size);
    std::cout << std::endl;

    return 0;

    return 0;
}