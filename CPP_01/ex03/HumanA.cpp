#include "HumanA.hpp"

HumanA::~HumanA(){}

HumanA::HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon){} // Üye Başlatma Listesi ile başlatma

void	HumanA::attack()
{
	std::cout << this->name << " attacks with their " << weapon.getType() << std::endl;
}

