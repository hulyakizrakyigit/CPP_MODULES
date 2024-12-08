#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " created" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << name << " destroyed" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
   std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    return *this;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << name << " high fives guys" << std::endl;
}

