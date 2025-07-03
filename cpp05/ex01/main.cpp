#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat high("Alice", 10);
        Bureaucrat low("Bob", 140);

        Form formA("Form-A", 50, 30);
        Form formB("Form-B", 140, 120);

        std::cout << "Before signing:" << std::endl;
        std::cout << formA << std::endl;
        std::cout << formB << std::endl;

        std::cout << "\n[Trying to sign Form-A with Alice (grade 10)]" << std::endl;
        high.signForm(formA);

        std::cout << "\n[Trying to sign Form-B with Bob (grade 10)]" << std::endl;
        low.signForm(formB);

        std::cout << "\n[Trying to sign Form-A with Bob (grade 140)]" << std::endl;
        low.signForm(formA);

        std::cout << "\nAfter signing: " << std::endl;
        std::cout << formA << std::endl;
        std::cout << formB << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "[EXCEPTION CAUGHT] " << e.what() << std::endl;
        return 1;
    }

    return 0;
}