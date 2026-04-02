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
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& n);

#endif