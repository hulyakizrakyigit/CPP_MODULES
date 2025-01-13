#include "MutantStack.hpp"
#include <list>

int main () {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "MutantStack top element: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "MutantStack size after pop: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    std::cout << "MutantStack first element: " << mstack.front() << std::endl;
    std::cout << "MutantStack last element: " << mstack.back() << std::endl;
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "MutantStack elements:" << std::endl;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    
    std::cout << "MutantStack elements (reverse):" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    while (rit != rite) {
        std::cout << *rit << std::endl;
        ++rit;
    }

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << "List top element: " << lst.back() << std::endl;
    lst.pop_back();
    std::cout << "List size after pop: " << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();
    ++lit;
    --lit;
    std::cout << "List elements:" << std::endl;
    while (lit != lite) {
        std::cout << *lit << std::endl;
        ++lit;
    }

    std::list<int>::reverse_iterator lrit = lst.rbegin();
    std::list<int>::reverse_iterator rlite = lst.rend();
    std::cout << "List elements (reverse):" << std::endl;
    while (lrit != rlite) {
        std::cout << *lrit << std::endl;
        ++lrit;
    }

    std::cout << "Stack elements:" << std::endl;
    std::stack<int> s(mstack);
    while (!s.empty()) {
        std::cout << s.top() << std::endl;
        s.pop();
    }
    
    return 0;
}