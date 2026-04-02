#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
    private:
        static const int fractionalBits = 8;
        int _fixed;
    
    public:
        Fixed(void);
        Fixed(Fixed &object);
        ~Fixed(void);
        Fixed& operator=(Fixed &number);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif