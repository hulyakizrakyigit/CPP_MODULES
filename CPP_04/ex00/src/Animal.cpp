#include "../inc/Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type) {
    std::cout << "Animal type constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &other) {
    *this = other;
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
    if (this != &other)
        this->type = other.type;
    std::cout << "Animal assignation operator called" << std::endl;
    return *this;
}

std::string Animal::getType() const {
    return type;
}

void Animal::makeSound() const {
    std::cout << "Animal sound" << std::endl;
}