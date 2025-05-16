#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : type("default") {
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type) {
    std::cout << "AMateria parameterized constructor called" << std::endl;
}

AMateria::~AMateria() {
    std::cout << "AMateria destructor called" << std::endl;
}

std::string const &AMateria::getType() const {
    return type;
}

void AMateria::use(ICharacter &target) {
    (void)target;
}
