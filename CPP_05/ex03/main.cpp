#include <iostream>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Intern someIntern;
        Bureaucrat hulya("Hulya", 5);
        Bureaucrat fatih("Fatih", 150);

        AForm* form1 = someIntern.makeForm("ShrubberyCreationForm", "garden");
        if (form1)
        {
            std::cout << "Form created: " << form1->getName() << std::endl;
            hulya.signForm(*form1);
            hulya.executeForm(*form1);
        }

    std::cout << "----------------------------------------" << std::endl;

        AForm* form2 = someIntern.makeForm("RobotomyRequestForm", "Bender");
        if (form2)
        {
            std::cout << "Form created: " << form2->getName() << std::endl;
            fatih.signForm(*form2);
            fatih.executeForm(*form2);
            hulya.signForm(*form2);
            hulya.executeForm(*form2);
        }

    std::cout << "----------------------------------------" << std::endl;

        AForm* form3 = someIntern.makeForm("PresidentialPardonForm", "John Doe");
        if (form3)
        {
            std::cout << "Form created: " << form3->getName() << std::endl;
            hulya.signForm(*form3);
            hulya.executeForm(*form3);
        }

    std::cout << "----------------------------------------" << std::endl;

        AForm* form4 = someIntern.makeForm("NonExistentForm", "target");
        if (form4 == NULL)
        {
            std::cout << "Form creation failed for NonExistentForm." << std::endl;
        }
        
    std::cout << "----------------------------------------" << std::endl;

        if (form4)
            delete form4;

        delete form1;
        delete form2;
        delete form3;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
