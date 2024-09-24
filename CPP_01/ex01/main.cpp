#include "Zombie.hpp"

int main()
{
	Zombie a("hkizrak-");
	a.announce();
	Zombie* b = zombieHorde(5, "ZOMBIE");
	for (int i = 0; i < 5; i++)
		b[i].announce();
	delete[] b;
	return (0);
}
// __attribute ((destructor)) void zombieHordeDestructor()
// {
// 	system("leaks zombieHorde");
// }
