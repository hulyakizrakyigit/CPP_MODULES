#include "RPN.hpp"

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

int RPN::evaluate(std::string &expression) {
    for (size_t i = 0; i < expression.length(); i++) {
        char c = expression[i];
        if (c == ' ')
            continue;
        if (std::isdigit(c))
            stack.push(c - '0');
        else if (isOperator(c)) {
            if (stack.size() < 2)
                throw std::runtime_error("ERROR: Invalid expression");
            
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            if (c == '/' && a == 0)
                throw std::runtime_error("ERROR: Division by zero");
            switch (c) {
                case '+':
                    stack.push(a + b);
                    break;
                case '-':
                    stack.push(b - a);
                    break;
                case '*':
                    stack.push(a * b);
                    break;
                case '/':
                    stack.push(b / a);
                    break;
            }
        } else {
            throw std::runtime_error("ERROR: Invalid character in expression");
        }
    }
    if (stack.size() != 1)
        throw std::runtime_error("ERROR: Invalid expression");

    return stack.top();  
}

bool RPN::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}