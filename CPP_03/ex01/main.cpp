#include "ScavTrap.hpp"

int main() {
    ClapTrap c1;
    ClapTrap c2("Clappy");
    ScavTrap s1;
    ScavTrap s2("Scavvy");
    c1.attack("enemy1");
    s1.attack("enemy2");
    c2.attack("enemy3");
    s2.attack("enemy4");
    s1.guardGate();
    s2.guardGate();



    return 0;
}