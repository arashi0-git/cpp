#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) { (void)other; }

Intern &Intern::operator=(const Intern &other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

static AForm *createShrub(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

static AForm *createRobot(const std::string &target) {
    return new RobotomyRequestForm(target);
}

static AForm *createPres(const std::string &target) {
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &FormName, const std::string &formTarget) const {
    const std::string names[3] = {
        "shrubbery request",
        "robotomy request",
        "presidential request"
    };
    AForm *(*creators[3])(const std::string&) = {
        &createShrub,
        &createRobot,
        &createPres
    };

    for (int i = 0; i < 3; i++) {
        if (names[i] == FormName) {
            std::cout << "Intern creats " << FormName << std::endl;
            return creators[i](formTarget);
        }
    }

    std::cerr << "Intern: form name \"" << FormName << "\" is unknown!" << std::endl;
    return NULL;
}
