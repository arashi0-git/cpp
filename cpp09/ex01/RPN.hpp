#ifndef RNP_HPP
#define RNP_HPP

#include <iostream>
#include <string.h>
#include <stack>
#include <sstream>

class RPN {
    public:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        static bool calculate(std::stack<int> &s,char token);
};

#endif