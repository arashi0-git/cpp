#include "iter.hpp"

void Incrementnum(int a) {
    std::cout << "increment: " << a + 1 << std::endl;
}

void Comparenum(const int a) {
    if (a > 3) {
        std::cout << a << " lager than '3'." << std::endl;
    } else {
        std::cout << a << " smaller than '3'." << std::endl;
    }
}

void Upperstring(std::string &arg) {
    std::transform(arg.begin(), arg.end(), arg.begin(), ::toupper);
    std::cout << "変換後の文字列 (元の文字列): " << arg << std::endl;
}

void PrintString(const std::string &arg) {
    std::cout << "String: " << arg << std::endl;
}

int main() {
    int array[5] = {1, 2, 3, 4, 5};
    iter(array, 5, Incrementnum);
    iter(array, 5, Comparenum);

    std::string strings[] = {"hello", "world", "hello World"};
    iter(strings, 3, Upperstring);
    iter(strings, 3, PrintString);
}