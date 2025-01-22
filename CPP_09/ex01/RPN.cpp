#include "RNP.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) {
    stack = other.stack;
}

RPN &RPN::operator=(const RPN &other) {
    if (this == &other)
        return *this;
    stack = other.stack;
    return *this;
}

RPN::~RPN() {}

int RPN::evaluate(const std::string &expression) {
    std::string::const_iterator it = expression.begin();
    while (it != expression.end()) {
        if (std::isdigit(*it)) {
            stack.push(*it - '0');
        } else if (*it == '+') {
            if (stack.size() < 2)
                throw std::runtime_error("Error: not enough operands");
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            stack.push(a + b);
        } else if (*it == '-') {
            if (stack.size() < 2)
                throw std::runtime_error("Error: not enough operands");
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            stack.push(b - a);
        } else if (*it == '*') {
            if (stack.size() < 2)
                throw std::runtime_error("Error: not enough operands");
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            stack.push(a * b);
        } else if (*it == '/') {
            if (stack.size() < 2)
                throw std::runtime_error("Error: not enough operands");
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            if (a == 0)
                throw std::runtime_error("Error: division by zero");
            stack.push(b / a);
        } else if (!std::isspace(*it)) {
            throw std::runtime_error("Error");
        }
        ++it;
    }
    if (stack.size() != 1)
        throw std::runtime_error("Error");
    return stack.top();
}