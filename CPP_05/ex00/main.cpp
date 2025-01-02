#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat hulya("Hulya", 2);
        std::cout << hulya << std::endl;

        hulya.incrementGrade();
        std::cout << hulya << std::endl;

        hulya.incrementGrade();
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

std::cout << "---------------------" << std::endl;

    try {
        Bureaucrat kizrak("Kizrak", 151);
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

std::cout << "---------------------" << std::endl;

    Bureaucrat *yigit = NULL;
    try {
        yigit = new Bureaucrat(170);
        yigit->decrementGrade();
    }
    catch (Bureaucrat::GradeTooHighException &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    if (yigit)
        delete yigit;

    return 0;
}