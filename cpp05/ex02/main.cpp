#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat b("ash", 2);
        ShrubberyCreationForm f1("home");
        RobotomyRequestForm f2("Bender");
        PresidentialPardonForm f3("Ford");

        std::cout << b << std::endl;
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
        std::cout << f3 << std::endl;

        b.signForm(f1);
        b.signForm(f2);
        b.signForm(f3);

        b.executeForm(f1);
        b.executeForm(f2);
        b.executeForm(f3);

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
