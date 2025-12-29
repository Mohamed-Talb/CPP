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
    // fixedPoint = roundf(Arg * (1 << Fraction));
    fixedPoint = Arg * (1 << Fraction);
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