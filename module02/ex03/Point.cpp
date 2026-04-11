#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(float const x, float const y) : _x(x), _y(y) {}

Point::Point(const Point& object) : _x(object.getX()), _y(object.getY()) {}

Point::~Point() {}

Point& Point::operator=(const Point& point)
{
    (void)point;
    return *this;
}

Point Point::operator-(const Point& point) const
{
    return Point(
        (this->_x - point.getX()).toFloat(),
        (this->_y - point.getY()).toFloat()
    );
}

const Fixed& Point::getX() const
{
    return this->_x;
}

const Fixed& Point::getY() const
{
    return this->_y;
}

Fixed Point::cross(const Point& number) const
{
    return this->_x * number.getY() - this->_y * number.getX();
}

std::ostream& operator<<(std::ostream& os, const Point& point)
{
    os << "Point(" << point.getX() << ", " << point.getY() << ")";
    return os;
}