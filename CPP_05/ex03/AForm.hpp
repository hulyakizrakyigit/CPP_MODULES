#ifndef AForm_HPP
#define AForm_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    protected:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

    public:
    AForm();
    AForm(int gradeToSign, int gradeToExecute);
    AForm(std::string const name, int gradeToSign, int gradeToExecute);
    AForm(AForm const &form);
    AForm &operator=(AForm const &form);
    virtual ~AForm();

    const std::string &getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const &executor) const = 0;
    
    class GradeTooHighException : public std::exception {
        public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public:
        virtual const char *what() const throw();
    };

    class FormNotSignedException : public std::exception {
        public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, AForm const &f);

#endif