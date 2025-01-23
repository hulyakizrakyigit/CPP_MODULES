#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN {
    private:
    std::stack<int> stack;

    public:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();

    int evaluate(std::string &expression);
    bool isOperator(char c);
};


#endif