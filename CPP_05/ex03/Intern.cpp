#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &src) {
    *this = src;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &src) {
    (void)src;
    return *this;
}

AForm *createShrubberyCreationForm(std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm *createRobotomyRequestForm(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm *createPresidentialPardonForm(std::string target) {
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target) {
    AForm *(*formCreators[])(std::string target) = {
        createShrubberyCreationForm,
        createRobotomyRequestForm,
        createPresidentialPardonForm
    };
    	std::string	formNames[] = {
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"
	};

    AForm *form = NULL;

    for (int i = 0; i < 3; i++) {
        if (name == formNames[i]) {
            form = formCreators[i](target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }
    std::cout << "Intern doesn't know how to create " << name << std::endl;
    return NULL;
}