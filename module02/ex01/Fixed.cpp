#include "Fixed.hpp"

Fixed::Fixed()
{
    this->_fixed = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const n)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixed = n * (1 << fractionalBits);
}

Fixed::Fixed(float const n)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixed = roundf(n * (1 << fractionalBits));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &object)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = object;
}

Fixed& Fixed::operator=(const Fixed &number)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_fixed = number.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    return this->_fixed;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixed = raw;
}

int Fixed::toInt(void) const
{
    return this->_fixed / (1 << fractionalBits);
}

float Fixed::toFloat(void) const
{
    return (float)this->_fixed / (1 << fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& n)
{
    out << n.toFloat();
    return out;
}