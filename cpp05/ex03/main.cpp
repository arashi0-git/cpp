#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

int main() {
    std::srand(std::time(NULL));

    try {
        Bureaucrat boss("Boss", 151);
    
        Intern intern;

        std::cout << "\n--- [1] Robotomy Request ---" << std::endl;
        AForm* form1 = intern.makeForm("robotomy request", "Marvin");
        if (form1) {
            boss.signForm(*form1);
            boss.executeForm(*form1);
            delete form1;
        }

        std::cout << "\n--- [2] Shrubbery Request ---" << std::endl;
    AForm* form2 = intern.makeForm("shrubbery request", "Taro");
    if (form2) {
            boss.signForm(*form2);
            boss.executeForm(*form2);
            delete form2;
        }

    std::cout << "\n--- [3] Presidential Request ---" << std::endl;
    AForm* form3 = intern.makeForm("presidential request", "Hanako");
    if (form3) {
        boss.signForm(*form3);
            boss.executeForm(*form3);
        delete form3;
    }

        std::cout << "\n--- [4] Unknown Form ---" << std::endl;
        AForm* form4 = intern.makeForm("wrong request", "Michel");
        if (form4) {
            boss.signForm(*form4);
            boss.executeForm(*form4);
            delete form4;
        }
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
