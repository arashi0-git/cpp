#include "Fixed.hpp"

const int Fixed::_fractionalBits;

Fixed::Fixed() : _fixedPoint(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intval) {
    std::cout << "Int constructor called" << std::endl;
    _fixedPoint = intval << _fractionalBits;
}

Fixed::Fixed(const float floatval) {
    std::cout << "Float constructor called" << std::endl;
    _fixedPoint = static_cast<int>(roundf(floatval * (1 << _fractionalBits)));
}

Fixed::Fixed(const Fixed &other) : _fixedPoint(other._fixedPoint) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &other) {
        _fixedPoint = other._fixedPoint;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return _fixedPoint;
}

void Fixed::setRawBits(int const raw) {
    _fixedPoint = raw;
}

float Fixed::toFloat() const {
    return static_cast<float>(_fixedPoint) / (1 << _fractionalBits);
}

int Fixed::toInt() const {
    return _fixedPoint >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}
