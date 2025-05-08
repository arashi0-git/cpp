#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

class DiamondTrap : public FragTrap, public ScavTrap {
    private:
        std::string _name;
    
    public:
        DiamondTrap(std::string name);
        ~DiamondTrap();

        void whoAmI(void);
        using ScavTrap::attack;
};

#endif