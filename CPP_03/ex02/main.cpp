#include "FragTrap.hpp"

int main()
{
    FragTrap f1;
    f1.attack("TARGET");
    f1.takeDamage(400);
    f1.beRepaired(100);
    f1.highFivesGuys();
    FragTrap f2("FragTrap");
    f2.attack("target");
    f2.takeDamage(10);
    f2.beRepaired(10);
    f2.highFivesGuys();
    return 0;
}