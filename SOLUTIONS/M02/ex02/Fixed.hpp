#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
class Fixed
{
    int fixedPoint;
    static const int Fraction;
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
        
        // operators 
        bool operator>(const Fixed &F) const;
        bool operator<(const Fixed &F) const;
        bool operator>=(const Fixed &F);
        bool operator<=(const Fixed &F);
        bool operator==(const Fixed &F);
        bool operator!=(const Fixed &F);

        Fixed operator+(const Fixed &F);
        Fixed operator-(const Fixed &F);
        Fixed operator*(const Fixed &F);
        Fixed operator/(const Fixed &F);

        Fixed &operator--();
        Fixed operator--(int);
        Fixed &operator++();
        Fixed operator++(int);

        static Fixed &min(Fixed &A, Fixed &B);
        static const Fixed &min(const Fixed &A, const Fixed &B);
        static Fixed &max(Fixed &A, Fixed &B);
        static const Fixed &max(const Fixed &A, const Fixed &B);

};

std::ostream &operator<<(std::ostream &out, const Fixed &F);

#endif