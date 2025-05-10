#include "WrongCat.hpp"

WrongCat::WrongCat() {
    std::cout << "[WrongCat] default constructor called" << std::endl;
    type = "WrongCat";
}

WrongCat::~WrongCat() {
    std::cout << "[WrongCat] destructor called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "[WrongCat] Meow..? (it won't be called)" << std::endl;
}
