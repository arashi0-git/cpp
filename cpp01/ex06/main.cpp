#include "Harl.hpp"
#include <iostream>

int main(int ac, char **av) {
    if(ac != 2) {
        std::cerr << "Usage: ./harlFilter <level>" << std::endl;
        return 1;
    }

    std::string level = av[1];
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int levelIndex = -1;

    for(int i =0; i < 4; i++) {
        if(level == levels[i]) {
            levelIndex = i;
            break;
        }
    }

    Harl harl;

    switch (levelIndex) {
        case 0:
            harl.complain("DEBUG");
        case 1:
            harl.complain("INFO");
        case 2:
            harl.complain("WARNING");
        case 3:
            harl.complain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
    return 0;
}
