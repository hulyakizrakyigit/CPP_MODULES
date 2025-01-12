#include "EasyFind.hpp"
#include <vector>
#include <list>

int main() {
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    try {
        std::vector<int>::iterator it = easyFind(v, 3);
        std::cout << "Value found: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyFind(v, 6);
        std::cout << "Value found: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);

    int valueToFind = 5;
    try {
        std::list<int>::iterator it = easyFind(lst, valueToFind);
        std::cout << "Value found: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }



    return 0;
}