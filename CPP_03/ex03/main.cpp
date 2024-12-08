#include "DiamondTrap.hpp"

int main()
{
     DiamondTrap d1("Diamond");
     std::cout << std::endl;
     DiamondTrap d2;
    std::cout << std::endl;
    d1.whoAmI();
    d1.attack("Enemy");
    std::cout << std::endl;
    d2.whoAmI();
    d2.attack("Target");
    std::cout << std::endl;

    return 0;
}
