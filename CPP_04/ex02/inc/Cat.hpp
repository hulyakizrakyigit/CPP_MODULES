#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
    private:
        Brain *brain;

    public:
        Cat();
        Cat(std::string type);
        Cat(const Cat &other);
        Cat &operator=(const Cat &other);
        virtual ~Cat();

        void makeSound() const;
        void setIdea(const std::string &idea, int index);
        std::string getIdea(int index) const;

};

#endif
