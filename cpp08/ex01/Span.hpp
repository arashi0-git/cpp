#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <climits>
#include <iostream>

class Span {
    private:
        unsigned int _maxSize;
        std::vector<int> _numbers;

    public:
        Span();
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();


        void addNumber(int n);

        unsigned int shortestSpan();
        unsigned int longestSpan();

        template <typename InputIterator>
        void addNumbers(InputIterator begin, InputIterator end) {
            for (InputIterator num = begin; num != end; ++num) {
                this->addNumber(*num);
            }
        }
};

#endif