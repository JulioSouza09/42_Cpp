#include "Point.hpp"

static
Fixed triangleArea(const Point& a, const Point& b, const Point& c)
{
    Point ab = b - a;
    Point ac = c - a;
    Fixed cross = ab.cross(ac);
    return Fixed(0.5f) * cross;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed abcArea = triangleArea(a, b, c);

    std::cout << "===== " << point << " =====" << std::endl;
    std::cout << "abcArea = " << abcArea << std::endl;
    Point pb = b - point;
    Point pc = c - point;
    Point pa = a - point;
    std::cout << "pa = " << pa << std::endl;
    std::cout << "pb = " << pb << std::endl;
    std::cout << "pc = " << pc << std::endl;
    Fixed aP = Fixed(0.5f) * (pb.cross(pc)) / abcArea;
    Fixed bP = Fixed(0.5f) * (pc.cross(pa)) / abcArea;
    Fixed cP = Fixed(0.5f) * (pa.cross(pb)) / abcArea;
    std::cout << "aP = " << aP << std::endl;
    std::cout << "bP = " << bP << std::endl;
    std::cout << "cP = " << cP << std::endl;

    return aP > 0 && aP < 1 && bP > 0 && bP < 1 && cP > 0 && cP < 1;
}