#include "ICharacter.hpp"
#include "Character.hpp"

Character::Character() : name("default") {
    std::cout << "[Character] default constructor called" << std::endl;
    for (int i = 0; i < 4; ++i) {
        inventory[i] = NULL;
    }
}

Character::Character(std::string const &name) : name(name) {
    std::cout << "[Character] parameterized constructor called" << std::endl;
    for (int i = 0; i < 4; ++i) {
        inventory[i] = NULL;
    }
}

Character::Character(const Character &other) : name(other.name) {
    std::cout << "[Character] parameterized constructor called" << std::endl;
    for (int i = 0; i < 4; ++i) {
        if(other.inventory[i]) {
            inventory[i] = other.inventory[i]->clone();
        }
        else {
            inventory[i] = NULL;
        }
    }
}

Character &Character::operator=(const Character &rhs) {
    std::cout << "[Character] assignment operator called" << std::endl;
    if(this != &rhs) {
        this->name = rhs.name;
        for (int i = 0; i < 4; ++i) {
            if (inventory[i]) {
                delete inventory[i]; 
            }
            inventory[i] = rhs.inventory[i] ? rhs.inventory[i]->clone() : NULL;
        }
    }
    return *this;
}

Character::~Character() {
    std::cout << "[Character] destructor called" << std::endl;
    for (int i = 0; i < 4; ++i) {
        delete inventory[i];
    }
    std::cout << "Character " << name << " destroyed" << std::endl;
}

std::string const &Character::getName() const {
    return name;
}

void Character::equip(AMateria *m) {
    for (int i = 0; i < 4; ++i) {
        if(inventory[i] == NULL) {
            inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4) {
        inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target) {
    if (idx >= 0 && idx < 4 && inventory[idx]) {
        inventory[idx]->use(target);
    }
}
