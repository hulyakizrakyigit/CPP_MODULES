#include "AForm.hpp"

AForm::AForm() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
    // std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const int gradeToSign, const int gradeToExecute) : name("Default"), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    // std::cout << "AForm constructor with gradeToSign and gradeToExecute called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(std::string const name, const int gradeToSign, const int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    // std::cout << "AForm constructor with name, gradeToSign and gradeToExecute called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &form) : name(form.name), isSigned(form.isSigned), gradeToSign(form.gradeToSign), gradeToExecute(form.gradeToExecute) {
    // std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(AForm const &form) {
    if (this != &form) {
        isSigned = form.isSigned;
    }
    // std::cout << "AForm assignation operator called" << std::endl;
    return *this;
}

AForm::~AForm() {
    std::cout << "AForm destructor called" << std::endl;
}

const std::string &AForm::getName() const {
    return name;
}

bool AForm::getIsSigned() const {
    return isSigned;
}

int AForm::getGradeToSign() const {
    return gradeToSign;
}

int AForm::getGradeToExecute() const {
    return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign)
        throw AForm::GradeTooLowException();
    isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed";
}

std::ostream &operator<<(std::ostream &out, AForm const &f) {
    out << "AForm " << f.getName() << " is ";
    if (!f.getIsSigned())
        out << "not ";
    out << "signed, grade to sign: " << f.getGradeToSign() << ", grade to execute: " << f.getGradeToExecute();
    return out;
}