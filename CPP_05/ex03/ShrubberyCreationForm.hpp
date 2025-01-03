#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
    private:
    std::string target;

    public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string const target);
    ShrubberyCreationForm(ShrubberyCreationForm const &form);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &form);
    virtual ~ShrubberyCreationForm();

    std::string getTarget() const;
    void execute(Bureaucrat const &executor) const;
};

#endif