#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {
    std::cout << "Default Zombie created." << std::endl;
}

Zombie::Zombie(std::string name) {
    this->name = name;
    std::cout << "Zombie " << this->name << " is created." << std::endl;
}

void Zombie::announce(void) const {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
    std::cout << "Zombie " << this->name << " is destroyed." << std::endl;
}

