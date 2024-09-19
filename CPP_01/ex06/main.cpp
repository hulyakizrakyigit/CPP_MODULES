#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl harl;

	if (ac != 2)
	{
		std::cout << "Usage: ./harlFilter <level>" << std::endl;
		return 1;
	}

	harl.complain(av[1]);
	return 0;
}
//Örneğin, ./harlFilter "ERROR" komutunu çalıştırdığınızda, sadece ERROR seviyesindeki mesajları görmek isteyebilirsiniz,
// böylece Harl’ın daha düşük seviyedeki (DEBUG, INFO, WARNING) mesajlarını "kapatmış" olursunuz.
