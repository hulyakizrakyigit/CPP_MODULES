#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
class ClapTrap {
    protected:   //miras alan sınıf erişebilsin diye protected
    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;

    public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& other);
    virtual ~ClapTrap();
    ClapTrap& operator=(const ClapTrap& other);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

};

#endif