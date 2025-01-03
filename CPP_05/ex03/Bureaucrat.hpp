#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
    std::string const name;
    int grade;

    public:
    Bureaucrat();
    Bureaucrat(std::string const name, int grade);
    Bureaucrat(int grade);
    Bureaucrat(Bureaucrat const &bureaucrat);
    Bureaucrat &operator=(Bureaucrat const &bureaucrat);
    ~Bureaucrat();

    std::string const &getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(AForm &form);
    void executeForm(AForm const &form);

    class GradeTooHighException : public std::exception {
        public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &b);

#endif