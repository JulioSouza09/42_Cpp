#include <iostream>
#include <sstream>
#include "Fixed.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

#define EXPECT_EQ(actual, expected) do { \
    if ((actual) == (expected)) { \
        std::cout << GREEN << "[ OK ] " << #actual << " == " << #expected << std::endl; \
    } else { \
        std::cout << RED << "[ FAIL ] " << std::endl; \
        std::cout << "  Expected: " << expected << std::endl; \
        std::cout << "  Actual:   " << actual << std::endl; \
    } \
    std::cout << RESET; \
} while (0)

#define EXPECT_STDOUT(codeToRun, expectedStr) do { \
    std::stringstream _buf; \
    std::streambuf* _old = std::cout.rdbuf(_buf.rdbuf()); \
    codeToRun; \
    std::cout.rdbuf(_old); \
    std::string _out = _buf.str(); \
    if (!_out.empty() && _out[_out.length() - 1] == '\n') \
        _out.erase(_out.length() - 1); \
    if (_out == (expectedStr)) { \
        std::cout << GREEN << "[ OK ] " << "Output matches expected string" << std::endl; \
    } else { \
        std::cout << RED << "[ FAIL ] " << "Output mismatch" << std::endl; \
        std::cout << "  Expected: \"" << expectedStr << "\"" << std::endl; \
        std::cout << "  Actual:   \"" << _out << "\"" << std::endl; \
    } \
    std::cout << RESET; \
} while (0)

#define SILENT(code) do { \
    std::stringstream _s; \
    std::streambuf* _o = std::cout.rdbuf(_s.rdbuf()); \
    code; \
    std::cout.rdbuf(_o); \
} while (0)

#define RUN_TEST(testFunc) do { \
    print_title(#testFunc); \
    testFunc(); \
    std::cout << std::endl; \
} while (0)

void print_title(std::string title)
{
    std::cout << "========== Testing " << title << " ==========" << std::endl;
}

void testGetRawBits()
{
    Fixed *f;
    int raw;

    SILENT( f = new Fixed() );
    EXPECT_STDOUT( f->getRawBits(), "getRawBits member function called" );
    SILENT( raw = f->getRawBits() );
    EXPECT_EQ(raw, 0);
    SILENT( delete f );
}

void testSetRawBits()
{
    Fixed *x;
    int raw;
    
    SILENT( x = new Fixed() );
    EXPECT_STDOUT( x->setRawBits(345), "setRawBits member function called" );
    SILENT( raw = x->getRawBits() );
    EXPECT_EQ(raw, 345);
    SILENT( delete x );
}

void testDefaultConstructor()
{
    Fixed *x;
    
    EXPECT_STDOUT( x = new Fixed(), "Default constructor called" );
    SILENT( delete x );
}

void testDestructor()
{
    Fixed *x;

    SILENT( x = new Fixed() );
    EXPECT_STDOUT( delete x, "Destructor called" );
}

int main()
{
    /* Fixed a;
    Fixed b( a );
    Fixed c;
    
    c = b;
    
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl; */

    RUN_TEST(testGetRawBits);
    RUN_TEST(testSetRawBits);
    RUN_TEST(testDefaultConstructor);
    RUN_TEST(testDestructor);
    return 0;
}