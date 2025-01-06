#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>

Base * generate(void) {
    srand(time(NULL));
    int random = rand() % 3;
    if (random == 0) {
        std::cout << "A generated" << std::endl;
        return new A();
    } else if (random == 1) {
        std::cout << "B generated" << std::endl;
        return new B();
    } else {
        std::cout << "C generated" << std::endl;
        return new C();
    }
}

void identify(Base* p) {
    std::cout << "Identifying pointer: ";
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown" << std::endl;
    }
}

void identify(Base& p) {
    std::cout << "Identifying reference: ";
    try {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (...) {}

    try {
        dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (...) {}

    try {
        dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (...) {}
}

int main() {
    Base* base = generate();
    Base& ref = *base;
    identify(base);
    identify(ref);
    delete base;

    return 0;
}