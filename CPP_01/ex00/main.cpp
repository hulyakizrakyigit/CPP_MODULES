
#include "Zombie.hpp"

int main()
{
	Zombie *zombie = newZombie("hulya");
	zombie->announce();
	Zombie zombie2("kizrak");
	zombie2.announce();
	randomChump("yigit");
	delete zombie;
	return (0);
}
// __attribute ((destructor)) void zombieHordeDestructor()
// {
// 	system("leaks zombie");
// }
