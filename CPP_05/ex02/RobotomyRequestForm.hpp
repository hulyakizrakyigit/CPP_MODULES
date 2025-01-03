#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    private:
    std::string target;

    public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string const target);
    RobotomyRequestForm(RobotomyRequestForm const &form);
    RobotomyRequestForm &operator=(RobotomyRequestForm const &form);
    virtual ~RobotomyRequestForm();

    std::string getTarget() const;
    void execute(Bureaucrat const &executor) const;
};


#endif