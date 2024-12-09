#include "./inc/Cat.hpp"
#include "./inc/Dog.hpp"
#include "./inc/WrongAnimal.hpp"
#include "./inc/WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound();
j->makeSound();
meta->makeSound();

const WrongAnimal* wrongmeta = new WrongAnimal();
const WrongAnimal* wrongj = new WrongCat();
std::cout << wrongj->getType() << " " << std::endl;
std::cout << wrongmeta->getType() << " " << std::endl;
wrongj->makeSound();
wrongmeta->makeSound();


delete meta;
delete j;
delete i;
delete wrongmeta;
delete wrongj;
return 0;
}
