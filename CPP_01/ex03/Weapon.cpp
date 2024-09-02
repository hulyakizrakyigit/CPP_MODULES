#include "Weapon.hpp"

Weapon::Weapon(const std::string& type)
{
	this->type = type;
} // parametre olarak geçirilen type string'inin bir kopyasını oluşturmadan, doğrudan orijinal string üzerinde işlem yapar.


Weapon::~Weapon()
{
}

const std::string& Weapon::getType() // const std::string& döndürerek, type string'inin bir kopyasını oluşturmadan, doğrudan type değişkeninin kendisini referans olarak geri döndürürsünüz.
{
	return (this->type);
}

void Weapon::setType(const std::string& type)
{
	this->type = type;
}
