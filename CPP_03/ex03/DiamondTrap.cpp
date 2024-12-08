#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
 : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap() {
    this->name = "Default_diamond_name";
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name") {
    this->name = name;
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap " << name << " created." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
    operator=(other);
    std::cout << "DiamondTrap copy constructor called." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    std::cout << "DiamondTrap copy assignment operator called." << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << this->name << " destroyed." << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << this->name << std::endl;
    std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
    ScavTrap::attack(target);
}
