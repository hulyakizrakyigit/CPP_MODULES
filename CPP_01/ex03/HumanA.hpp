// HumanA her zaman bir silaha sahip olduğundan, silahı bir referans (Weapon&) olarak saklar.
// Referanslar, bir değişkenin başka bir adı gibidir ve oluşturulduktan sonra başka bir nesneye bağlanamazlar. Yani bir referans, tanımlandığı nesneye sıkı sıkıya bağlıdır. HumanA'nın her zaman bir silahı olması gerektiği için, referans kullanmak mantıklıdır çünkü:
// Referans, mutlaka geçerli bir nesneye (yani, bir silaha) işaret eder.
// Referansın içeriği değiştirilemez; HumanA'nın silahı her zaman olmalıdır ve silahsız bir duruma geçmemelidir.
#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon& weapon;

	public:
		~HumanA();
		HumanA(const std::string& name, Weapon& weapon);
		void attack();
};

#endif
