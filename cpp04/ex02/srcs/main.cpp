#include "Animal.hpp"
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "Creating a Dog and a Cat..." << std::endl;

    const AAnimal *dog = new Dog();
    const AAnimal *cat = new Cat();

    std::cout << "\n=== makeSound ===" << std::endl;
    dog->makeSound();
    cat->makeSound();

    std::cout << "\n=== destructor ===" << std::endl;
    delete dog;
    delete cat;

    return 0;
}

// const AAnimal *meta = new AAnimal(); //this cannot compile