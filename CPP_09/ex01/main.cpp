#include "RPN.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Error: Invalid number of arguments" << std::endl;
        return 1;
    }

    try {
        RPN rpn;
        std::string expression = av[1];
        int result = rpn.evaluate(expression);
        std::cout << result << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}