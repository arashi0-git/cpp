#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "=== Creating ClapTrap ===" << std::endl;
    ClapTrap clap("Taro");

    std::cout << "=== Creating ScavTrap ===" << std::endl;
    ScavTrap scav("Jiro");

    std::cout << "=== ClapTrap Actions ===" << std::endl;
    clap.attack("enemy1");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << "=== ScavTrap Actions ===" << std::endl;
    scav.attack("enemy2");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();

    return 0;
}