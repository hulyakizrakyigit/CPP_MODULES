#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span {
    private:
        unsigned int maxSize;
        std::vector<int> numbers;
    
    public:
    Span();
    Span(unsigned int n);
    Span(const Span &src);
    ~Span();
    Span &operator=(const Span &src);

    void addNumber(int n);

    template <typename it>
    void addNumber(it begin, it end);

    int shortestSpan();
    int longestSpan();

    class SpanExceptionFull : public std::exception {
    virtual const char *what() const throw();
    };

    class SpanExceptionShort : public std::exception {
    virtual const char *what() const throw();
    };
};

template <typename it>
void Span::addNumber(it begin, it end) {
    if (numbers.size() + std::distance(begin, end) > maxSize)
        throw SpanExceptionFull();
    numbers.insert(numbers.end(), begin, end);
}

#endif