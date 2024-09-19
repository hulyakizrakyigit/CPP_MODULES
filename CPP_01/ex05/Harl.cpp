#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable. I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	// İşlev İşaretçileri Tanımlama: functions dizisi, Harl sınıfındaki işlevlerin adreslerini saklar.
	// Bu işaretçiler, her seviyeye karşılık gelen işlevleri çağırmak için kullanılır.

// (Harl::*functions[4])(void):

// Harl::*: Bu, işaretçinin Harl sınıfına ait bir üye işlevi işaret edeceğini belirtir. Yani, işaretçi Harl sınıfındaki işlevlere işaret eder.
// functions[4]: Bu, 4 elemanlı bir dizidir. Dizinin her elemanı bir işlev işaretçisidir.
//Bu tanım, Harl sınıfında bulunan 4 farklı işlevi işaret eden bir dizi işaretçi oluşturur. Her işaretçi, Harl sınıfının bir üye işlevini temsil eder.



	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*f[i])();
			return ;
		}
	}
}
