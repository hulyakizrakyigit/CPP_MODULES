#include "ClapTrap.hpp"

int main() {
    ClapTrap c1;
    ClapTrap c2("Hunter");

    c1.attack("enemy1");
    c1.takeDamage(5);
    c1.beRepaired(3);
    c1.takeDamage(15);
    c1.beRepaired(10);
    c1.attack("enemy2");
    for (int i = 0; i < 11; i++) {
    c2.attack("enemy3");
    }
    c2.beRepaired(5);
    ClapTrap* c3 = new ClapTrap("hulya");
    c3->attack("enemy4");
    delete c3;
    return 0;
}