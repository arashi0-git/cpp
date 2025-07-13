#include "Array.hpp"

int main() {
    try {
        Array<unsigned int> arr(5);
        for (int i = 0; i < arr.size(); i++)
            arr[i] = i + 1;
        for (int i = 0; i < arr.size(); i++) {
            std::cout << "Array" << i << ": " << arr[i] << std::endl;
        }
        arr[3] = 5;

        std::cout << std::endl;
        std::cout << "--- After changed ---" << std::endl;
        for (int i = 0; i < arr.size(); i++) {
            std::cout << "Array" << i << ": " << arr[i] << std::endl;
        }

        std::cout << "\n--- Error pattern ---" << std::endl;
        Array<unsigned int> other_arr(3);
        std::cout << arr[5] << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "Error happened: " << e.what() << std::endl;
    }
}