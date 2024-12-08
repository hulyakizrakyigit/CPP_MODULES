#include "DiamondTrap.hpp"

int main()
{
     DiamondTrap d1("Diamond");
     DiamondTrap d2;

    d1.whoAmI();
    d1.attack("Enemy");
    d2.whoAmI();
    d2.attack("Target");

    return 0;
}