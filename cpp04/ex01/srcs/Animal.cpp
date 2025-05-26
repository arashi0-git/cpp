#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Animal default constructor called" << std::endl;
    type = "Animal";
}

Animal::Animal(const Animal &other) {
    std::cout << "[Animal] Copy constructor called" << std::endl;
    type = other.type;
}

Animal &Animal::operator=(const Animal &rhs) {
    std::cout << "[Animal] Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        type = rhs.type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const {
    return type;
}

void Animal::makeSound() const {
    std::cout << "[Animal] makes a generic sound" << std::endl;
}
