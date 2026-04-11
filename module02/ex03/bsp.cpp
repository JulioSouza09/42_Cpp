#include "Point.hpp"

static
Fixed triangleArea(const Point& a, const Point& b, const Point& c)
{
    return Fixed(0.5f) * (b - a).cross(c - a);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed abcArea = triangleArea(a, b, c);

    Point pb = b - point;
    Point pc = c - point;
    Point pa = a - point;
    Fixed aP = Fixed(0.5f) * (pb.cross(pc)) / abcArea;
    Fixed bP = Fixed(0.5f) * (pc.cross(pa)) / abcArea;
    Fixed cP = Fixed(0.5f) * (pa.cross(pb)) / abcArea;

    return aP > 0 && aP < 1 && bP > 0 && bP < 1 && cP > 0 && cP < 1;
}