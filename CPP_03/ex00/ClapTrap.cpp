#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << name <<  " created" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    operator=(other);
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (hitPoints > 0 && energyPoints > 0) {
        energyPoints--;
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
    } else {
        std::cout << "ClapTrap " << name << " has no energy or hit points left" << std::endl; 
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
        hitPoints -= amount;
    if (hitPoints < 0) {
        hitPoints -= 0;
    }
     std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (hitPoints > 0 && energyPoints > 0) {
        energyPoints--;
        hitPoints += amount;
    std::cout << "ClapTrap " << name << " repairs itself, recovering " << amount << " hit points!" << std::endl;
    } else {
        std::cout << "ClapTrap " << name << " can not repairs itself, has no energy or hit points" << std::endl;
    }
}
