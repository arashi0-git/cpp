#include "Conversion.hpp"

int main(int ac, char **av) {
    if (ac != 2){
        std::cerr << "Invalid argument You must ./convert arg1" << std::endl;
        return 1;
    }
    std::string input = av[1];
    static int Type = Conversion::CheckArg(input);

    return 0;

}