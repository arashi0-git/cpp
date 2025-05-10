#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat default constructor called" << std::endl;
    type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "[Cat] Copy constructor called" << std::endl;
    brain = new Brain(*other.brain);
    type = other.type;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "[Cat] Meow! 🐱" << std::endl;
}
