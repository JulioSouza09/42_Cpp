#include <iostream>
#include "bsp.hpp"

// Colors for output
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
    /* // Define a triangle: A(0,0), B(10,0), C(0,10)
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    std::cout << "--- Starting BSP Tests ---" << std::endl;

    // 1. Points clearly inside
    run_test("Inside Center", a, b, c, Point(2, 2), true);
    run_test("Inside Near Corner", a, b, c, Point(0.1f, 0.1f), true);

    // 2. Points clearly outside
    run_test("Outside Far", a, b, c, Point(10, 10), false);
    run_test("Outside Negative", a, b, c, Point(-1, -1), false);
    run_test("Outside Near Edge", a, b, c, Point(5, -0.1f), false);

    // 3. Edge cases (Should be false per your logic)
    run_test("On Vertex A", a, b, c, Point(0, 0), false);
    run_test("On Edge AB", a, b, c, Point(5, 0), false);
    run_test("On Edge BC", a, b, c, Point(5, 5), false);

    std::cout << "--- Tests Complete ---" << std::endl; */

    Point a(0, 0);
    Point b(1, 2.2f);
    Point c(2.4f, 1);

    run_test("Outside  with y = min fixed", a, b, c, Point(0, 0.00390625f), false);
    run_test("Inside with y and x = min fixed", a, b, c, Point(0.00390625f, 0.00390625f), true);
    run_test("Outsidee with x = min fixed", a, b, c, Point(0.00390625f, 0), false);
    run_test("Clearly inside", a, b, c, Point(1.2f, 1), true);
    run_test("Clearly outside", a, b, c, Point(1.2f, -1), false);

    return 0;
}