#include "./inc/Cat.hpp"
#include "./inc/Dog.hpp"

int main()
{
    Dog myDog;
    Cat myCat;

	// AAnimal animal;

    myDog.setIdea("I want a bone!", 0);
    myCat.setIdea("I want to sleep!", 0);

    std::cout << "Dog's idea at index 0: " << myDog.getIdea(0) << std::endl;
    std::cout << "Cat's idea at index 0: " << myCat.getIdea(0) << std::endl;
    std::cout << "Dog's idea at index 5: " << myDog.getIdea(5) << std::endl;
    std::cout << "Cat's idea at index 5: " << myCat.getIdea(5) << std::endl;

    myCat.makeSound();
    myDog.makeSound();

    return 0;
}

// __attribute ((destructor)) void zombieHordeDestructor()
// {
// 	system("leaks Brain");
// }
