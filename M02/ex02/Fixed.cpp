#include "Fixed.hpp"

static const int Fraction = 2; /// ???

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    fixedPoint = 0;
}

Fixed::Fixed(int Arg)
{
    std::cout << "Int constructor called" << std::endl;
    fixedPoint = Arg << Fraction;
}
Fixed::Fixed(float Arg)
{
    std::cout << "float constructor called" << std::endl;
    fixedPoint = roundf(Arg * (1 << Fraction));
}

Fixed::Fixed(const Fixed &F)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = F;
}
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        fixedPoint = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (fixedPoint);
}
void Fixed::setRawBits(int const raw)
{
    fixedPoint = raw;
}

float Fixed::toFloat( void ) const
{
    return (fixedPoint / (float)(1 << Fraction));
}

int Fixed::toInt( void ) const
{
    return (fixedPoint >> Fraction);
}

std::ostream &operator<<(std::ostream &out, const Fixed &F)
{
    out << F.toFloat();
    return out;
}

bool Fixed::operator<(const Fixed &F) const 
{
    return this->fixedPoint < F.fixedPoint;
}

bool Fixed::operator>(const Fixed &F) const
{
    return this->fixedPoint > F.fixedPoint;
}

bool Fixed::operator>=(const Fixed &F)
{
    return this->fixedPoint >= F.fixedPoint;
}

bool Fixed::operator<=(const Fixed &F)
{
    return this->fixedPoint <= F.fixedPoint;
}

bool Fixed::operator==(const Fixed &F)
{
    return this->fixedPoint == F.fixedPoint;
}

bool Fixed::operator!=(const Fixed &F)
{
    return this->fixedPoint != F.fixedPoint;
}


Fixed &Fixed::operator+(const Fixed &F)
{
    Fixed result;
    result.setRawBits (this->fixedPoint + F.fixedPoint);
    return result;
}

Fixed &Fixed::operator-(const Fixed &F)
{
    Fixed result;
    result.setRawBits(this->fixedPoint - F.fixedPoint);
    return result;
}

Fixed &Fixed::operator*(const Fixed &F)
{
    Fixed result;
    result.setRawBits((this->fixedPoint * F.fixedPoint) >> Fraction);
    return result;
}

Fixed &Fixed::operator/(const Fixed &F)
{
    Fixed result(roundf((this->fixedPoint /(float)F.fixedPoint) * (1 << Fraction)));
    return result;
}

Fixed &Fixed::operator--()
{
    --fixedPoint;
    return *this;
}
Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    --fixedPoint;
    return tmp;
}
Fixed &Fixed::operator++()
{
    ++fixedPoint;
    return *this;
}
Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    ++fixedPoint;
    return tmp;
}

Fixed &Fixed::min(Fixed &A, Fixed &B)
{
    return (A < B) ? A : B;
}

Fixed &Fixed::max(Fixed &A, Fixed &B)
{
    return (A > B) ? A : B;
}

const Fixed &Fixed::min(const Fixed &A, const Fixed &B)
{
    return (A < B) ? A : B;
}

const Fixed &Fixed::max(const Fixed &A, const Fixed &B)
{
    return (A > B) ? A : B;
}

