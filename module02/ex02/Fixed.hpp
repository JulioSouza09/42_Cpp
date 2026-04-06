#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    private:
        static const int fractionalBits = 8;
        int _fixed;
    
    public:
        Fixed(void);
        Fixed(int const n);
        Fixed(float const n);
        Fixed(const Fixed &object);
        ~Fixed(void);
        Fixed& operator=(const Fixed &number);
        bool operator>(const Fixed &number) const;
        bool operator<(const Fixed &number) const;
        bool operator>=(const Fixed &number) const;
        bool operator<=(const Fixed &number) const;
        bool operator==(const Fixed &number) const;
        bool operator!=(const Fixed &number) const;
        Fixed operator+(const Fixed &number) const;
        Fixed operator-(const Fixed &number) const;
        Fixed operator*(const Fixed &number) const;
        Fixed operator/(const Fixed &number) const;
        Fixed& operator++(void);
        Fixed operator++(int);
        Fixed& operator--(void);
        Fixed operator--(int);
        static Fixed& min(Fixed& n1, Fixed& n2);
        static const Fixed& min(const Fixed& n1, const Fixed& n2);
        static Fixed& max(Fixed& n1, Fixed& n2);
        static const Fixed& max(const Fixed& n1, const Fixed& n2);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& n);

#endif