#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {
    protected:
        std::string type;
    public:
        AAnimal();
        virtual ~AAnimal();
        AAnimal(const AAnimal &other);
        AAnimal &operator=(const AAnimal &rhs);

        std::string getType() const;
        virtual void makeSound() const = 0;
};

// line 15 is  pure virtual destructor
// it called an abstract class that contains at least one pure virtual function 

#endif