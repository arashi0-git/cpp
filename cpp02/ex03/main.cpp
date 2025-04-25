#include "Point.hpp"
#include "Fixed.hpp"

int main() {
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(0.0f, 5.0f);

    Point p_in(1.0f, 1.0f);
    Point p_on(0.0f, 0.0f);
    Point p_out(6.0f, 6.0f);

    std::cout << "Inside: " << bsp(a, b, c, p_in) << std::endl;
    std::cout << "On edge: " << bsp(a, b, c, p_on) << std::endl;
    std::cout << "Outside: " << bsp(a, b, c, p_out) << std::endl;

    return 0;
}
