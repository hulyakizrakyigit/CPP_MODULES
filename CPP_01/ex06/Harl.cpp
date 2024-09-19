#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
	std::cout << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
	std::cout << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable. I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}
	// İşlev İşaretçileri Tanımlama: functions dizisi, Harl sınıfındaki işlevlerin adreslerini saklar.
	// Bu işaretçiler, her seviyeye karşılık gelen işlevleri çağırmak için kullanılır.

// (Harl::*functions[4])(void):

// Harl::*: Bu, işaretçinin Harl sınıfına ait bir üye işlevi işaret edeceğini belirtir. Yani, işaretçi Harl sınıfındaki işlevlere işaret eder.
// functions[4]: Bu, 4 elemanlı bir dizidir. Dizinin her elemanı bir işlev işaretçisidir.
//Bu tanım, Harl sınıfında bulunan 4 farklı işlevi işaret eden bir dizi işaretçi oluşturur. Her işaretçi, Harl sınıfının bir üye işlevini temsil eder.

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	int levelIndex = -1;
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			levelIndex = i;
			break;
		}
	}

	switch (levelIndex)
	{
		case 0:
			(this->*f[0])();
		case 1:
			(this->*f[1])();
		case 2:
			(this->*f[2])();
		case 3:
			(this->*f[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
