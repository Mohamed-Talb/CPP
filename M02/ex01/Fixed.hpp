#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
class Fixed
{
    int fixedPoint;
    static const int Fraction = 13;
    public:
        Fixed();
        Fixed(int Arg);
        Fixed(float Arg);
        Fixed(const Fixed &F);
        Fixed& operator=(const Fixed &other);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &F);
#endif