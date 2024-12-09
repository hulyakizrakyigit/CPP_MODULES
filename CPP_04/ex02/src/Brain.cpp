#include "../inc/Brain.hpp"

Brain::Brain() {
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
    *this = other; // deep copy
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
    if (this != &other) {
        for (int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    std::cout << "Brain assignation operator called" << std::endl;
    return *this;
}

void Brain::setIdea(int index, std::string idea) {
    ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
    if (index < 0 || index >= 100)
        return "Invalid index";
    return ideas[index];
}
