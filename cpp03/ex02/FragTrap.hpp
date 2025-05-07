#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTeap.hpp"
#include <iostream>

class FragTrap : public clapTrap {
    public:
        FragTrap(std::string name);
        ~FragTrap();

        void attack(const std::string &target);
        void highFivesGuys(void);
};

#endif