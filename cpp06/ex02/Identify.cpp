#include "Identify.hpp"
#include <typeinfo>

Base::~Base() {
    std::cout << "default destructor called" << std::endl;
}

Base *generate(void) {
    int i = std::rand() % 3;
    switch (i) {
        case 0: return new A;
        case 1: return new B;
        case 2: return new C;
        default: return NULL;
    }
}

void identify(Base *p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Error" << std::endl;
}

void identify(Base &p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    std::cout << "Error" << std::endl;
}
