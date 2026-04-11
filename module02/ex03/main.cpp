#include <iostream>
#include "bsp.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

void run_test(std::string name, Point const a, Point const b, Point const c, Point const p, bool expected)
{
    bool result = bsp(a, b, c, p);
    
    std::cout << "Test: " << name << " | Point(" << p.getX() << ", " << p.getY() << ")";
    if (result == expected)
    {
        std::cout << GREEN << " [PASS]" << RESET << std::endl;
    }
    else
    {
        std::cout << RED << " [FAIL]" << RESET << " (Expected " 
                  << (expected ? "true" : "false") << " but got " 
                  << (result ? "true" : "false") << ")" << std::endl;
    }
}

int main()
{
    Point a(0, 0);
    Point b(1, 2.2f);
    Point c(2.4f, 1);

    run_test("Outside  with y = min fixed", a, b, c, Point(0, 0.00390625f), false);
    run_test("Inside with y = min fixed", a, b, c, Point(0.5f, 1.00390625f), true);
    run_test("Outsidee with x = min fixed", a, b, c, Point(0.00390625f, 0), false);
    run_test("Clearly inside", a, b, c, Point(1.2f, 1), true);
    run_test("Clearly outside", a, b, c, Point(1.2f, -1), false);
    run_test("On top of the vertice", a, b, c, Point(1, 2.2f), false);

    return 0;
}