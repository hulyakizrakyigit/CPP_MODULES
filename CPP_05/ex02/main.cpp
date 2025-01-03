#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try {
        Bureaucrat Hulya("Hulya", 60);
        Bureaucrat Fatih("Fatih", 150);
        Bureaucrat Humeyra("Humeyra", 5);

        ShrubberyCreationForm shrubberyForm("home");
        RobotomyRequestForm robotomyForm("target");
        PresidentialPardonForm pardonForm("criminal");

        std::cout << std::endl;
        std::cout << shrubberyForm << std::endl;
        std::cout << robotomyForm << std::endl;
        std::cout << pardonForm << std::endl;
        std::cout << std::endl;

        try {
            Fatih.signForm(shrubberyForm);
            Fatih.executeForm(shrubberyForm);
            Fatih.signForm(robotomyForm);
            Fatih.executeForm(robotomyForm);
            Fatih.signForm(pardonForm);
            Fatih.executeForm(pardonForm);
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;

        std::cout << shrubberyForm << std::endl;
        std::cout << robotomyForm << std::endl;
        std::cout << pardonForm << std::endl;

        std::cout << std::endl;

        try {
            Hulya.signForm(shrubberyForm);
            Hulya.executeForm(shrubberyForm);
            Hulya.signForm(robotomyForm);
            Hulya.executeForm(robotomyForm);
            Hulya.signForm(pardonForm);
            Hulya.executeForm(pardonForm);
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }

        std::cout << std::endl;

        std::cout << shrubberyForm << std::endl;
        std::cout << robotomyForm << std::endl;
        std::cout << pardonForm << std::endl;

        std::cout << std::endl;

        try {
            Humeyra.signForm(shrubberyForm);
            Humeyra.executeForm(shrubberyForm);
            Humeyra.signForm(robotomyForm);
            Humeyra.executeForm(robotomyForm);
            Humeyra.signForm(pardonForm);
            Humeyra.executeForm(pardonForm);
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }

        std::cout << std::endl;

        std::cout << shrubberyForm << std::endl;
        std::cout << robotomyForm << std::endl;
        std::cout << pardonForm << std::endl;

        std::cout << std::endl;

        std::cout << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Unhandled exception: " << e.what() << std::endl;
    }

    return 0;
}
