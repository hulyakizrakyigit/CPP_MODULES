#include "RobotomyRequestForm.hpp"
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("Default") {
    //std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("RobotomyRequestForm", 72, 45), target(target) {
    //std::cout << "RobotomyRequestForm constructor with target called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &form) : AForm(form), target(form.target) {
    //std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &form) {
    if (this != &form) {
        target = form.target;
    }
    //std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const {
    return target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (!getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw Bureaucrat::GradeTooLowException();
    std::cout << "**********Drilling noises**********" << std::endl;
    srand(time(NULL));
    if (rand() % 2)
        std::cout << target << " has been robotomized" << std::endl;
    else
        std::cout << target << " robotomization failed" << std::endl;
}