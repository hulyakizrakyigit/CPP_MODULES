#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
	private:
		std::string type;

	public:
		Weapon();
		Weapon(const std::string& type); // Constructor ve burada referans yollandı çünkü stringin kopyasını oluşturmak yerine aynı stringi kullanmak daha mantıklı
		~Weapon();
		const std::string& getType();
		void setType(const std::string& type); // Burada da referans yolladık çünkü stringin kopyasını oluşturmak yerine aynı stringi kullanmak daha mantıklı


};

#endif
