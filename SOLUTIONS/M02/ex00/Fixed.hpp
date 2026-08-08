#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
class Fixed
{
    int fixedPoint;
    static const int Fraction;
    public:
        Fixed();
        Fixed(const Fixed &F);
        Fixed &operator=(const Fixed &other);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif