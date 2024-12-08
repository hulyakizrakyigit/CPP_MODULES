#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name <<  " created" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << name << " destroyed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
   std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
        }
   std::cout << "ScavTrap copy assignment operator called" << std::endl;
    return *this;
}

void ScavTrap::attack(const std::string& target) {
    if (hitPoints > 0 && energyPoints > 0) {
        energyPoints--;
        std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
    } else {
        std::cout << "\033[31m" << "ScavTrap " << name << " has no energy or hit points left" << "\033[0m" << std::endl;
    }
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap  " << name << " is now guarding the gate " << std::endl;
}




