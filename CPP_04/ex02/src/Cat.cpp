#include "../inc/Cat.hpp"

Cat::Cat() : AAnimal("Cat") {
    brain = new Brain();
    int i = 0;
    while (i < 100)
        brain->setIdea(i++, "Cat idea");
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string type) : AAnimal(type) {
    brain = new Brain();
    std::cout << "Cat type constructor called" << std::endl;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &cat) : AAnimal(cat) {
    brain = new Brain(*cat.brain);
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat) {
    if (this != &cat)
    {
        AAnimal::operator=(cat);
        *brain = *cat.brain;
    }
    std::cout << "Cat assignation operator called" << std::endl;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow Meow" << std::endl;
}

void Cat::setIdea(const std::string &idea, int index) {
    brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
    return brain->getIdea(index);
}