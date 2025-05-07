#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " has been constructed!" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << _name << " has been destructed!" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
    if (_energyPoints <= 0) {
        std::cout << "ScavTrap " << _name << " has no energy to attack!" << std::endl;
        return;
    }
    if (_hitPoints <= 0) {
        std::cout << "ScavTrap " << _name << " is out of HP and can't attack." << std::endl;
        return;
    }

    _energyPoints--;
    std::cout << "ScavTrap " << _name << " fiercely attacks " << target << ", dealing " << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}
