#include "RPN.hpp"
#include <limits.h>

RPN::RPN() {}

RPN::RPN(const RPN &other) {
    (void) other;
}

RPN &RPN::operator=(const RPN &other) {
    (void) other;
    return *this;
}

RPN::~RPN() {}

bool RPN::calculate(std::stack<int> &s, char token) {
    
    int num2 = s.top();
    s.pop();
    int num1 = s.top();
    s.pop();
    
    switch (token) {
        case '+': {
            s.push(num1 + num2);
            break;
        }
        case '-': {
            s.push(num1 - num2);
            break;
        }
        case '*': {
            long long product = static_cast<long long>(num1) * static_cast<long long>(num2);
            if (product > INT_MAX || product < INT_MIN) {
                std::cerr << "Error" << std::endl;
                return false;
            }
            s.push(num1 * num2);
            break;
        }
        case '/': {
            if (num2 == 0) {
                std::cerr << "Error" << std::endl;
                return false;
            }
            s.push(num1 / num2);
            break;
        }
        default: {
            std::cerr << "Error" << std::endl;
            return false;
        }
    }
    return true;
}