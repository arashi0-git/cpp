#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main() {
    std::cout << "=== newZombie===" <<std::endl;
    Zombie *newzombie = newZombie("Heap Zombie");
    newzombie->announce();
    delete newzombie;

    std::cout << std::endl;
    
    std::cout << "=== randomChump===" <<std::endl;
    randomChump("Stack Zombie");
    std::cout << std::endl;

    return 0;
}
