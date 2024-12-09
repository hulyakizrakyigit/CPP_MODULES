#include "./inc/Cat.hpp"
#include "./inc/Dog.hpp"

int main()
{
    int i = -1;
	Animal *animals[10];
	while (++i < 10)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	i = -1;
	while (++i < 10)
	{
		animals[i]->makeSound();
	}
	i = -1;
	while (++i < 10)
		delete animals[i];
	Cat	*cat = new Cat();
	cat->makeSound();
	cat->getIdea(2);
	cat->setIdea("Ben atim", 50);
    std::cout << cat->getIdea(50) << std::endl;
	delete cat;
	return (0);
    // Dog myDog;
    // Cat myCat;

    // myDog.setIdea("I want a bone!", 0);
    // myCat.setIdea("I want to sleep!", 0);

    // std::cout << "Dog's idea at index 0: " << myDog.getIdea(0) << std::endl;
    // std::cout << "Cat's idea at index 0: " << myCat.getIdea(0) << std::endl;
    // std::cout << "Dog's idea at index 5: " << myDog.getIdea(5) << std::endl;
    // std::cout << "Cat's idea at index 5: " << myCat.getIdea(5) << std::endl;

    // myCat.makeSound();
    // myDog.makeSound();

    // return 0;
}

__attribute ((destructor)) void zombieHordeDestructor()
{
	system("leaks Brain");
}
