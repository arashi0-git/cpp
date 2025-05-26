#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
    protected:
        std::string type;
    public:
        Animal();
        virtual ~Animal();
        Animal(const Animal &other);
        Animal &operator=(const Animal &rhs);

        std::string getType() const;
        virtual void makeSound() const = 0;
};

#endif