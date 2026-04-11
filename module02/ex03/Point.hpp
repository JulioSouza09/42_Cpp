#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;
	
	public:
		Point();
		Point(float const x, float const y);
		Point(const Point& object);
		~Point();

		const Fixed& getX() const;
		const Fixed& getY() const;
		Fixed cross(const Point& number) const;

		Point& operator=(const Point& point);
		Point operator-(const Point& point) const;
};

std::ostream& operator<<(std::ostream& os, const Point& point);

#endif
