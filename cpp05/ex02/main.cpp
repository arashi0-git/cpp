#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>

int main() {
    try {
        std::srand(std::time(NULL));

        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 50);
        Bureaucrat charlie("Charlie", 140);

        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Form Prefect");

        std::cout << "\n--- Signing forms ---" << std::endl;

        charlie.signForm(shrub);
        bob.signForm(robot);
        alice.signForm(pardon);

        std::cout << "\n--- Excuting forms ---" << std::endl;

        charlie.signForm(shrub);
        bob.executeForm(robot);
        alice.executeForm(robot);
        alice.executeForm(pardon);

        std::cout << "\n--- Failure cases ---" << std::endl;

        Bureaucrat toolow("LowRank", 150);
        ShrubberyCreationForm notSigned("unapproved");
        toolow.signForm(pardon);
        toolow.executeForm(shrub);
        toolow.executeForm(notSigned);
    } catch {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
