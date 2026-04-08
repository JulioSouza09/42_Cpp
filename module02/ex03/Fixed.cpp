#include "Fixed.hpp"
#include <stdexcept>

Fixed::Fixed()
{
    this->_fixed = 0;
}

Fixed::Fixed(int const n)
{
    this->_fixed = n * (1 << fractionalBits);
}

Fixed::Fixed(float const n)
{
    this->_fixed = roundf(n * (1 << fractionalBits));
}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &object)
{
    *this = object;
}

Fixed& Fixed::operator=(const Fixed &number)
{
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

bool Fixed::operator>(const Fixed &number) const
{
    return this->_fixed > number.getRawBits();
}

bool Fixed::operator<(const Fixed &number) const
{
    return this->_fixed < number.getRawBits();
}

bool Fixed::operator>=(const Fixed &number) const
{
    return this->_fixed >= number.getRawBits();
}

bool Fixed::operator<=(const Fixed &number) const
{
    return this->_fixed <= number.getRawBits();
}

bool Fixed::operator==(const Fixed &number) const
{
    return this->_fixed == number.getRawBits();
}

bool Fixed::operator!=(const Fixed &number) const
{
    return this->_fixed != number.getRawBits();
}

Fixed Fixed::operator+(const Fixed &number) const
{
    Fixed result;

    result.setRawBits(this->_fixed + number.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed &number) const
{
    Fixed result;

    result.setRawBits(this->_fixed - number.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed &number) const
{
    Fixed result;
    long long rawProduct;

    rawProduct = (long long)this->_fixed * (long long)number.getRawBits();
    result.setRawBits((int)(rawProduct >> fractionalBits));
    return result;
}

Fixed Fixed::operator/(const Fixed &number) const
{
    Fixed result;
    long long scaled;

    scaled = (long long)(this->_fixed << fractionalBits);
    result.setRawBits((int)(scaled / number.getRawBits()));
    return result;
}

Fixed& Fixed::operator++(void)
{
    this->_fixed += 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);

    this->_fixed += 1;
    return temp;
}

Fixed& Fixed::operator--(void)
{
    this->_fixed -= 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);

    this->_fixed -= 1;
    return temp;
}

Fixed& Fixed::min(Fixed& n1, Fixed& n2)
{
    return (n1 < n2) ? n1 : n2;
}

const Fixed& Fixed::min(const Fixed& n1, const Fixed& n2)
{
    return (n1 < n2) ? n1 : n2;
}

Fixed& Fixed::max(Fixed& n1, Fixed& n2)
{
    return (n1 > n2) ? n1 : n2;
}

const Fixed& Fixed::max(const Fixed& n1, const Fixed& n2)
{
    return (n1 > n2) ? n1 : n2;
}
