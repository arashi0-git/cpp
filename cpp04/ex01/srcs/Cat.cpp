#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat default constructor called" << std::endl;
    type = "Cat";
    brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "[Cat] Copy constructor called" << std::endl;
    brain = new Brain(*other.brain);
    type = other.type;
}

Cat &Cat::operator=(const Cat &rhs){
    std::cout << "[Cat] Copy assignment operator called" << std::endl;
    if(this != &rhs) {
        type = rhs.type;
        if(brain) 
            delete brain;
        brain = new Brain(*rhs.brain);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete brain;
}

void Cat::makeSound() const {
    std::cout << "[Cat] Meow! 🐱" << std::endl;
}

void Cat::setIdea(int index, const std::string &idea) {
    brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
    return brain->getIdea(index);
}
