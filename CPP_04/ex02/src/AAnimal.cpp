#include "../inc/AAnimal.hpp"

AAnimal::AAnimal() : type("Animal") {
    std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type) {
    std::cout << "AAnimal type constructor called" << std::endl;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) {
    *this = other;
    std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other) {
    if (this != &other)
        this->type = other.type;
    std::cout << "AAnimal assignation operator called" << std::endl;
    return *this;
}

std::string AAnimal::getType() const {
    return type;
}

void AAnimal::makeSound() const {
    std::cout << "AAnimal sound" << std::endl;
}