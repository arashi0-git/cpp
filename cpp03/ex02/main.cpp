#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "=== Creating ClapTrap ===" << std::endl;
    ClapTrap clap("Taro");

    std::cout << "=== Creating ScavTrap ===" << std::endl;
    ScavTrap scav("Jiro");

    std::cout << "=== Creating FragTrap ===" << std::endl;
    FragTrap frag("Saburo");

    std::cout << "=== ClapTrap Actions ===" << std::endl;
    clap.attack("enemy1");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << "=== ScavTrap Actions ===" << std::endl;
    scav.attack("enemy2");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();

    std::cout << "=== FragTrap Actions ===" << std::endl;
    frag.attack("enemy3");
    frag.takeDamage(30);
    frag.beRepaired(20);
    frag.highFivesGuys();
    
    std::cout << "=== End of Program ===" << std::endl;

    return 0;
}