#include "Zombie.hpp"
#include <iostream>

int main() {
    int n = 5;
    std::string name = "Zombie";

    std::cout << "===createing horde of " << n << " zombies===" << std::endl;
    Zombie *horde = zombieHorde(n, name);
    if(!horde) {
        std::cerr << "Failed to create horde of zombies." << std::endl;
        return 1;
    }
    for (int i = 0; i < n; i++){
        horde[i].announce();
    }
    std::cout << "=== Deleting horde of zombies ===" << std::endl;
    delete[] horde;

    return 0;
}

