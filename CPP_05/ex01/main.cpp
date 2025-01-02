#include "Form.hpp"

int main() {

    try {
    Bureaucrat hulya("Hulya", 2);
    Form form1("Form1", 3, 4);
    std::cout << form1 << std::endl;
        
    hulya.signForm(form1);
    std::cout << form1 << std::endl;

    Bureaucrat kizrak("Kizrak", 150);
    Form form2("Form2", 2, 3);
    std::cout << form2 << std::endl;

    kizrak.signForm(form2);
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "---------------------" << std::endl;

    Bureaucrat* assistant = new Bureaucrat("Assistant", 145);
    Bureaucrat* ceo = new Bureaucrat("CEO", 1);
    Bureaucrat* manager = new Bureaucrat("Manager", 50);

    Form* formA = new Form("Rent Contract", 140, 100);
    Form* formB = new Form("Employment Contract", 120, 80);
    Form* formC = new Form("Confidential Document", 60, 50);
    
    std::cout << *assistant;
    std::cout << *ceo;
    std::cout << *manager << std::endl;
    
    std::cout << *formA << std::endl;
    std::cout << *formB << std::endl;
    std::cout << *formC << std::endl;

    try {
        assistant->signForm(*formA);
    }
    catch (std::exception& e) {
        std::cerr << assistant->getName() << " cannot sign " << formA->getName() << ": " << e.what() << std::endl;
    }
    
    std::cout << *formA << std::endl;

    try {
        ceo->signForm(*formA);
    }
    catch (std::exception& e) {
        std::cerr << ceo->getName() << " was not able to sign " << formA->getName() << ": " << e.what() << std::endl;
    }
    
    std::cout << *formA << std::endl;

    try {
        manager->signForm(*formB);
    }
    catch (std::exception& e) {
        std::cerr << manager->getName() << " was not able to sign " << formB->getName() << ": " << e.what() << std::endl;
    }

    std::cout << *formB << std::endl;

    try {
        assistant->signForm(*formC);
    }
    catch (std::exception& e) {
        std::cerr << assistant->getName() << " was not able to sign " << formC->getName() << ": " << e.what() << std::endl;
    }

    std::cout << *formC << std::endl;

    try {
        ceo->signForm(*formB);
    }
    catch (std::exception& e) {
        std::cerr << ceo->getName() << " was not able to sign " << formB->getName() << ": " << e.what() << std::endl;
    }

    std::cout << *formB << std::endl;

    try {
        ceo->signForm(*formC);
    }
    catch (std::exception& e) {
        std::cerr << ceo->getName() << " was not able to sign " << formC->getName() << ": " << e.what() << std::endl;
    }

    std::cout << *formC << std::endl;

    delete assistant;
    delete ceo;
    delete manager;
    delete formA;
    delete formB;
    delete formC;
    return 0;
}