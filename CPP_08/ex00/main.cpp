#include "EasyFind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <set>

int main() {
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
        std::cout << *it << " ";

    std::cout << std::endl;

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

    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
        std::cout << *it << " ";
    
    std::cout << std::endl;

    int valueToFind = 9;
    try {
        std::list<int>::iterator it = easyFind(lst, valueToFind);
        std::cout << "Value found: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::deque<int> dq;
    dq.push_back(100);
    dq.push_back(200);
    dq.push_back(300);
    dq.push_back(400);

    for (std::deque<int>::iterator it = dq.begin(); it != dq.end(); it++)
        std::cout << *it << " ";
    
    std::cout << std::endl;

    valueToFind = 200;

    try {
        std::deque<int>::iterator it = easyFind(dq, valueToFind);
        std::cout << "Value found: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}