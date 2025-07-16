#include "RPN.hpp"

int main(int ac, char **av) {
    if (ac != 2){
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::stack<int> s;
    std::istringstream iss(av[1]);
    std::string token;
    while(iss >> token) {
        if (token.length() == 1 && isdigit(token[0])) {
            s.push(token[0] - '0');
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (s.size() < 2) {
                std::cerr << "Error" << std::endl;
                return 1;
            }
            if (!RPN::calculate(s, token[0]))
                return 1;
        }
        else {
            std::cerr << "Error" << std::endl;
            return 1;
        }
    }
    if (s.size() != 1){
        std::cerr << "Error" << std::endl;
        return 1;
    }
    std::cout << s.top() << std::endl;
    return 0;
}