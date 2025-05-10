#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain default constructor called" << std::endl;
    for(int i = 0; i < 100; i++)
    ideas[i] = "No idea";
}

Brain::Brain(const Brain &other) {
    std::cout << "[Brain] copy constructor called" << std::endl;
    for(int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain &rhs) {
    std::cout << "[Brain] assignment operator called" << std::endl;
    if(this != &rhs) {
        for(int i =0; i < 100; i++)
            ideas[i] = rhs.ideas[i];
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int index, const std::string &idea) {
    if(index >= 0 && index < 100)
        ideas[index] = idea;
    else
        std::cout << "[Brain] index out of range" << std::endl;
}

std::string Brain::getIdea(int index) const {
    if(index >= 0 && index < 100)
        return ideas[index];
    std::cout << "[Brain] invalid index in getIdea" << std::endl;
    return "";
}
