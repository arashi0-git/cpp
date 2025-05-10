#include "../incs/Dog.hpp"


Dog::Dog() {
    std::cout << "Dog default constructor called" << std::endl;
    type = "Dog";
    brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other) {
    std::cout << "[Dog] Copy constructor called" << std::endl;
    brain = new Brain(*other.brain);
    type = other.type;
}

Dog &Dog::operator=(const Dog &rhs) {
    std::cout << "[Dog] Copy assignment operator called" << std::endl;
    if(this != &rhs){
        type = rhs.type;
        if(brain) 
            delete brain;
        brain = new Brain(*rhs.brain);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}

void Dog::makeSound() const {
    std::cout << "[Dog] Woof! 🐶" << std::endl;
}

void Dog::setIdea(int Index, const std::string &idea) {
    brain->setIdea(Index, idea);
}

std::string Dog::getIdea(int Index) const {
    return brain->getIdea(Index);
}
