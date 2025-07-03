#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("Shrubbery", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery", 145,137) {
        _target  = target;
    }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other) {
        _target = other._target;
    }

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
    if(!isSigned()) {
        throw AFormNotSignedException();
    }
    if(executor.getGrade() > getExecGrade()) {
        throw AForm::GradeTooLowException();
    }

    std::ofstream file((_target + "_shrubbery").c_str());
    if(!file) {
        std::cerr << "Failed to open file." << std::endl;
        return;
    }

    file << "       🌳\n"
        << "      🌳🌳\n"
        << "     🌳🌳🌳\n"
        << "    🌳🌳🌳🌳\n"
        << "        |  \n";
    file.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}