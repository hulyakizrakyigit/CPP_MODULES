#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

    public:
    Form();
    Form(int gradeToSign, int gradeToExecute);
    Form(std::string const name, int gradeToSign, int gradeToExecute);
    Form(Form const &form);
    Form &operator=(Form const &form);
    ~Form();

    const std::string &getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(const Bureaucrat &bureaucrat);
    
    class GradeTooHighException : public std::exception {
        public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, Form const &f);

#endif