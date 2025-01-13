#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>

int main() {
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);
        vec.push_back(40);
        vec.push_back(50);
        vec.push_back(60);
        Span sp2 = Span(10);
        sp2.addNumber(vec.begin(), vec.end());

        std::cout << "Shortest Span (sp2): " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest Span (sp2): " << sp2.longestSpan() << std::endl;

        try {
            sp2.addNumber(70);
            sp2.addNumber(80);
            sp2.addNumber(90);
            sp2.addNumber(100);
            sp2.addNumber(110);
        } catch (const std::exception &e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        try {
            std::cout << "Shortest Span (sp2): " << sp2.shortestSpan() << std::endl;
            std::cout << "Longest Span (sp2): " << sp2.longestSpan() << std::endl;
        } catch (const std::exception &e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        std::list<int> lst;
        lst.push_back(100);
        lst.push_back(200);
        lst.push_back(300);
        lst.push_back(400);
        Span sp3 = Span(5);
        sp3.addNumber(lst.begin(), lst.end());

        std::cout << "Shortest Span (sp3): " << sp3.shortestSpan() << std::endl;
        std::cout << "Longest Span (sp3): " << sp3.longestSpan() << std::endl;

        try {
            sp3.addNumber(500);
            sp3.addNumber(600);
        } catch (const std::exception &e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        Span sp4 = Span(2);
        sp4.addNumber(5);
        try {
            std::cout << "Shortest Span (sp4): " << sp4.shortestSpan() << std::endl;
        } catch (const std::exception &e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

    } catch (const std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    Span sp5 = Span(10000);
    for (int i = 0; i < 10000; i++) {
        sp5.addNumber(rand() % 10000);
    }

    std::cout << "Shortest Span (sp5): " << sp5.shortestSpan() << std::endl;
    std::cout << "Longest Span (sp5): " << sp5.longestSpan() << std::endl;

    return 0;
}