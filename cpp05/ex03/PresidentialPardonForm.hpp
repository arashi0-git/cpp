#ifndef PRESIDENTIALPARDONTORM_HPP
#define PRESIDENTIALPARDONTORM_HPP

#include "AForm.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>

class PresidentialPardonForm : public AForm {
    private:
        std::string _target;
        
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
        virtual ~PresidentialPardonForm();

        virtual void execute(Bureaucrat const &executor) const;
};

#endif