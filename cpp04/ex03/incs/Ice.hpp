#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include <string>

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
public :
    Ice();
    Ice(const Ice &other);
    Ice &operator=(const Ice &rhs);
    virtual ~Ice();

    virtual AMateria *clone() const;
    virtual void use(ICharacter &target);
};

#endif