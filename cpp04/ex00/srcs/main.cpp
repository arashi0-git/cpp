#include "../incs/Animal.hpp"
#include "../incs/Dog.hpp"
#include "../incs/Cat.hpp"
#include "../incs/WrongAnimal.hpp"
#include "../incs/WrongCat.hpp"

int main() {
    const Animal *meta = new Animal();
    std::cout << "-------------------Dog--------------------" << std::endl;
    const Animal *dog = new Dog();
    std::cout << "-------------------Cat--------------------" << std::endl;
    const Animal *cat = new Cat();

    std::cout << "-------------------GetType--------------------" << std::endl;
    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;

    std::cout << "-------------------MakeSound--------------------" << std::endl;
    dog->makeSound();
    cat->makeSound();
    meta->makeSound();

    std::cout << "-------------------Destructor--------------------" << std::endl;
    delete meta;
    delete dog;
    delete cat;

    std::cout << "-------------------Wrong Animal--------------------" << std::endl;

    const WrongAnimal *Wrongmeta = new WrongAnimal();
    const WrongAnimal *wrongcat = new WrongCat();

    std::cout << "-------------------MakeSound--------------------" << std::endl;
    Wrongmeta->makeSound();
    wrongcat->makeSound();

    std::cout << "-------------------Delete--------------------" << std::endl;
    delete Wrongmeta;
    delete wrongcat;

    return 0;
}
