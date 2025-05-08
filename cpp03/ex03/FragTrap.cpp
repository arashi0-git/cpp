#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " created!" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << _name << " destroyed!" << std::endl;
}

void FragTrap::attack(const std::string &target) {
    if(_energyPoints <= 0) {
        std::cout << "FragTrap " << _name << " has no energy left to attack!" << std::endl;
        return;
    }
    if(_hitPoints <= 0) {
        std::cout << "FragTrap " << _name << " is out of hit points and cannot attack!" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _name << " is requesting a high five!" << std::endl;
}
