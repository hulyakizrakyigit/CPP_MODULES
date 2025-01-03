#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("Default") {
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {
    std::cout << "ShrubberyCreationForm constructor with target called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &form) : AForm(form), target(form.target) {
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &form) {
    if (this != &form) {
        target = form.target;
    }
    std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const {
    return target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &execute) const {
    if (!getIsSigned())
        throw AForm::FormNotSignedException();
    if (execute.getGrade() > getGradeToExecute())
        throw Bureaucrat::GradeTooLowException();

    std::ofstream outFile ((target + "_shrubbery").c_str());

    if (!outFile.is_open()) {
        std::cerr << "Error: could not open file" << std::endl;
        return;
    }

	outFile << "      /\\      " << std::endl;
	outFile << "     /\\*\\     " << std::endl;
	outFile << "    /\\O\\*\\    " << std::endl;
	outFile << "   /*/\\/\\/\\   " << std::endl;
	outFile << "  /\\O\\/\\*\\/\\  " << std::endl;
	outFile << " /\\*\\/\\*\\/\\/\\ " << std::endl;
	outFile << "/\\O\\/\\/*/\\/O/\\" << std::endl;
	outFile << "      ||      " << std::endl;
	outFile <<      "      ||      " << std::endl;
	outFile <<      "      ||      " << std::endl;
	outFile << "      ||      " << std::endl;
	outFile << "      ||      " << std::endl;
	outFile << "      ||      " << std::endl;
	outFile << "     /||\\     " << std::endl;
	outFile << "    / || \\    " << std::endl;
	outFile << "   /  ||  \\ " << std::endl;
	outFile.close();
    std::cout << "ShrubberyCreationForm " << getName() << " executed" << std::endl;
}