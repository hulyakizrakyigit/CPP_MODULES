#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: ./a.out [filename]" << std::endl;
        return 1;
    }

    try {
        BitcoinExchange exchange;
        exchange.loadDatabase("data.csv");
        exchange.processInput(av[1]);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}