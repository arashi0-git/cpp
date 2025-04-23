#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int _fixedPoint;
    static const int _fractionalBits = 8;
public:
    Fixed();
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();

    Fixed(int const intval);
    Fixed(float const floatval);

    int getRawBits() const;
    void setRawBits(int const raw);

    float toFloat() const;
    int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, Fixed const &fixed);

#endif