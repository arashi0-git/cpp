#include "AAnimal.hpp"

AAnimal::AAnimal() {
    std::cout << "Abstract Animal default constructor called" << std::endl;
}

AAnimal::~AAnimal() {
    std::cout << "Abstract Animal destructor called" << std::endl;
}

std::string AAnimal::getType() const {
    return type;
}
