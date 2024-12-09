#include "../inc/Dog.hpp"

Dog::Dog() : Animal("Dog") {
    brain = new Brain();
    int i = 0;
    while (i < 100)
        brain->setIdea(i++, "Dog idea");
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type) {
    brain = new Brain();
    int i = 0;
    while (i < 100)
        brain->setIdea(i++, "Dog idea");
    std::cout << "Dog type constructor called" << std::endl;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog) {
    brain = new Brain(*dog.brain);
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    if (this != &other)
    {
        Animal::operator=(other);
        *brain = *other.brain;
    }
    std::cout << "Dog assignation operator called" << std::endl;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof Woof" << std::endl;
}


void Dog::setIdea(const std::string &idea, int index) {
    brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
    return brain->getIdea(index);
}