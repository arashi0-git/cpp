#include "Identify.hpp"
#include <ctime>

int main() {
    std::srand(std::time(0));
    Base *p = generate();
    identify(p);
    identify(*p);
    delete p;
    return 0;
}