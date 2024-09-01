// HumanB başlangıçta bir silaha sahip olmayabilir, bu nedenle silahı bir işaretçi (Weapon*) olarak saklar.
// İşaretçiler, bir nesneye işaret edebilir, ancak aynı zamanda nullptr (yani, hiçbir şeye işaret etmeyen bir gösterici) olabilir. HumanB'nin silahsız olabileceği düşünüldüğünde, işaretçi kullanmak mantıklıdır çünkü:
// İşaretçi, silahı olmadığı durumda nullptr olabilir.
// İşaretçi, sonradan bir silahı gösterebilir, bu da esneklik sağlar. HumanB'ye sonradan bir silah verilebilir veya hiç verilmez.
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
	std::string name;
	Weapon* weapon;

	public:
	~HumanB();
	HumanB(const std::string& name);
	void setWeapon(Weapon* weapon); //Kopyalama Maliyetini Önlemek, Orijinal Nesne Üzerinde İşlem Yapmak
	void attack();
};

#endif
