#include <iostream>
#include "Fixed.hpp"


int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed c;
    Fixed d(10.5f);
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << std::endl;
    std::cout << a + b << std::endl;
    std::cout << a - b << std::endl;
    std::cout << a * b << std::endl;
    std::cout << a / b << std::endl;
    std::cout << b / a << std::endl;
    std::cout << a / c << std::endl;
    std::cout << d / b << std::endl;
    std::cout << d / a << std::endl;
    std::cout << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}