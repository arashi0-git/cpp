#include "Span.hpp"

int main() {
    try {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << "------------------------------------" << std::endl;

    std::vector<int> values;
    for (int i = 0; i < 10000; ++i) {
        values.push_back(i * 3);
    }
    Span bigSpan(10000);
    bigSpan.addNumbers(values.begin(), values.end());
    std::cout << *values.begin() << std::endl;
    std::cout << *(values.end() - 1) << std::endl;
    std::cout << bigSpan.shortestSpan() << std::endl;
    std::cout << bigSpan.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}