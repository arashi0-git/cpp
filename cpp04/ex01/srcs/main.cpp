#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    const int size = 4;
    Animal *animals[size];

    std::cout << "\n=== Creating Animals ===" << std::endl;
    for(int i = 0; i < size; ++i) {
        if(i < size / 2) 
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n=== Making Sounds ===" << std::endl;
    for(int i = 0; i < size; ++i) {
        animals[i]->makeSound();
    }

    std::cout << "\n=== Deleting Animals ===" << std::endl;
    for(int i = 0; i < size; ++i) {
        delete animals[i];
    }

    std::cout << "\n=== Deep Copy Test ===" << std::endl;
    {
        Dog original;
        original.setIdea(0, "Fetch the ball");
        Dog copy = original;

        std::cout << "Original Dog Idea: " << original.getIdea(0) << std::endl;
        std::cout << "Copied Dog Idea: " << copy.getIdea(0) << std::endl;

        copy.setIdea(0, "Chase the cat");
        std::cout << "After modifying copy:" << std::endl;
        std::cout << "Original Dog Idea: " << original.getIdea(0) << std::endl;
        std::cout << "Copied Dog Idea: " << copy.getIdea(0) << std::endl;
    }
    return 0;
}

// deep copy start at line 33 
// original and copy are two different instances of the Dog class.
// on memory they are different
// but they have the same idea at the beginning
