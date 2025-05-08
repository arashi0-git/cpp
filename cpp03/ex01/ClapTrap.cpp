#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(2) {
    std::cout << "ClapTrap " << _name << " created." << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _name << " destroyed." << std::endl;
}

void ClapTrap::attack(const std::string &target) {
    if(_energyPoints <= 0) {
        std::cout << "ClapTrap " << _name << " has no energy left to attack!" << std::endl;
        return;
    }
    if(_hitPoints <= 0) {
        std::cout << "ClapTrap " << _name << " is out of hit points and cannot attack!" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    _hitPoints -= amount;
    if(_hitPoints < 0) {
        _hitPoints = 0;
    }
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! Hit points left: " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if(_energyPoints <= 0){
        std::cout << "ClapTrap " << _name << " has no energy left to repair!" << std::endl;
        return;
    }
    _energyPoints--;
    _hitPoints += amount;
    if(_hitPoints > 10) {
        _hitPoints = 10;
    }
    std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " points! Hit points now: " << _hitPoints << std::endl;
}
