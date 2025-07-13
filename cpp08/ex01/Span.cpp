#include "Span.hpp"

Span::Span() : _maxSize(0), _numbers(0) {}

Span::Span(unsigned int N) {
    _maxSize = N;
}

Span::Span(const Span &other) {
    _maxSize = other._maxSize;
    _numbers = other._numbers;
}

Span &Span::operator=(const Span &other) {
    if(this != &other) {
    _maxSize = other._maxSize;
    _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n) {
    if (_numbers.size() >= _maxSize)
        throw std::runtime_error("Span is already full");
    _numbers.push_back(n);
}

unsigned int Span::shortestSpan() {
    if (_numbers.size() < 2)
        throw std::runtime_error("Fewer elements in the container");
    std::sort(_numbers.begin(), _numbers.end());
    unsigned int minDif = INT_MAX;
    for (size_t i = 0; i < _numbers.size() - 1; i++) {
        unsigned int diff = _numbers[i + 1] - _numbers[i];
        minDif = std::min(minDif, diff);
    }
    return minDif;
}

unsigned int Span::longestSpan() {
    if (_numbers.size() < 2)
        throw std::runtime_error("Fewer elements in the container");
    int minVal = *std::min_element(_numbers.begin(), _numbers.end());
    int maxVal = *std::max_element(_numbers.begin(), _numbers.end());
    return static_cast<unsigned int>(maxVal - minVal);
}