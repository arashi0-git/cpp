#include "easyfind.hpp"

int main() {
    std::vector<int> vec = {3, 5, 6, 8, 4, 6};
    if (easyfind(vec, 5)) {
        std::cout << "Find integer!" << std::endl;
    } else {
        std::cout << "Not find integer!" << std::endl;
    }

    std::cout << "--------------------------------" << std::endl;
    if (easyfind(vec, 20)) {
        std::cout << "Find integer!" << std::endl;
    } else {
        std::cout << "Not find integer!" << std::endl;
    }

    return 0;
}