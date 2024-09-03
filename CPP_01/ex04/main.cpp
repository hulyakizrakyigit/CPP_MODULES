#include "Replace.hpp"

int main(int ac, char *av[])
{
	if (ac != 4)
	{
		std::cout << "Usage: ./ex04 [filename] [s1] [s2]" << std::endl;
		return 1;
	}

	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	if (s1.empty())
	{
		std::cout << "Error: s1 must not be empty" << std::endl;
		return 1;
	}
	replacInFile(filename, s1, s2);
}
__attribute ((destructor)) void zombieHordeDestructor()
{
	system("leaks replace");
}
