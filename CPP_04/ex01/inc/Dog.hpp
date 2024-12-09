#ifndef DOG_HPPP
#define DOG_HPPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    private:
        Brain *brain;

    public:
        Dog();
        Dog(std::string type);
        Dog(const Dog &other);
        Dog &operator=(const Dog &other);
        virtual ~Dog();

        void makeSound() const;
        void setIdea(const std::string &idea, int index);
        std::string getIdea(int index) const;
};

#endif
