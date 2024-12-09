#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {
	protected:
		std::string type;
	
	public:
		AAnimal();
		AAnimal(std::string type);
		virtual ~AAnimal();
		AAnimal(const AAnimal &other);
		AAnimal &operator=(const AAnimal &other); 

		std::string getType() const;

		virtual void makeSound() const = 0;

		};

#endif
