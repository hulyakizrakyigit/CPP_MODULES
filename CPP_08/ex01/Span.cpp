#include "Span.hpp"
#include <algorithm>

Span::Span(unsigned int n) : maxSize(n), numbers(std::vector<int>()){}

Span::Span(const Span &src) : maxSize(src.maxSize), numbers(src.numbers){}

Span::~Span(){}

Span &Span::operator=(const Span &src) {
    if (this == &src)
        return *this;
    maxSize = src.maxSize;
    numbers = src.numbers;
    return *this;
}

char const *Span::SpanExceptionShort::what() const throw() {
    return "Not enough numbers to calculate span";
}

char const *Span::SpanExceptionFull::what() const throw() {
    return "Span is full";
}

void Span::addNumber(int n) {
    if (numbers.size() >= maxSize)
        throw SpanExceptionFull();
    numbers.push_back(n);
}

int Span::shortestSpan() {
    if (numbers.size() < 2)
        throw SpanExceptionShort();
    
    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());
    int min = sorted[1] - sorted[0];
    for (size_t i = 2; i < sorted.size(); i++) {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < min)
            min = diff;
    }
    return min;
}

int Span::longestSpan() {
    if (numbers.size() < 2)
        throw SpanExceptionShort();
    
    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());
    return sorted[sorted.size() - 1] - sorted[0];
}