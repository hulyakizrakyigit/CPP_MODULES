#include "HumanB.hpp"

HumanB::~HumanB(){}

HumanB::HumanB(const std::string& name)
{
	this->name = name;
	this->weapon = NULL;
}

void HumanB::setWeapon(Weapon* weapon)
{
	this->weapon = weapon; // weapon' referansının adresini 'this->weapon' işaretçisine atar
}

void	HumanB::attack()
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " has no weapon! " << std::endl;
}
