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

#define EXPECT_FLOAT_EQ(actual, expected) do { \
    float _a = (actual); \
    float _e = (expected); \
    float _diff = (_a > _e) ? (_a - _e) : (_e - _a); \
    if (_diff < (1.0f) / (256)) { /* 1/256 precision */ \
        std::cout << GREEN << "[ OK ] " << #actual << " approx " << #expected << std::endl; \
    } else { \
        std::cout << RED << "[ FAIL ] " << std::endl; \
        std::cout << "    Exp: " << _e << " | Act: " << _a << " | Diff: " << _diff << std::endl; \
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

#define TEST_CONSTRUCTOR(type, value, varName, assertions) do \
{ \
    type *varName; \
    SILENT( varName = new type(value) ); \
    assertions; \
    SILENT( delete varName ); \
} while (0);

#define CHECK_INT(value, raw, func) do \
{ \
    TEST_CONSTRUCTOR(Fixed, value, f, { \
        EXPECT_EQ(func, raw); \
    }); \
} while (0);

#define CHECK_FLOAT(value, expected, func) do \
{ \
    TEST_CONSTRUCTOR(Fixed, value, f, { \
        EXPECT_FLOAT_EQ(func, expected); \
    }); \
} while (0);


void print_title(std::string title)
{
    std::cout << "========== Testing " << title << " ==========" << std::endl;
}

/* 
Default constructor called
Int constructor called
Float constructor called
Copy constructor called
Copy assignment operator called
Float constructor called
Copy assignment operator called
Destructor called */

void testDefaultConstructor()
{
    Fixed *x;
    
    EXPECT_STDOUT( x = new Fixed(), "Default constructor called" );
    SILENT( delete x );
}

void testIntConstructor()
{
    Fixed *x;

    EXPECT_STDOUT( x = new Fixed(10), "Int constructor called" );
    SILENT( delete x );

    CHECK_INT(0, 0, x->getRawBits());
    CHECK_INT(10, 2560, x->getRawBits());
    CHECK_INT(-5, -1280, x->getRawBits());
}

void testFloatConstructor()
{
    Fixed *x;
    
    EXPECT_STDOUT( x = new Fixed(42.42f), "Float constructor called" );
    SILENT( delete x );

    CHECK_INT(0.0f, 0, x->getRawBits());
    CHECK_INT(0.1f, 26, x->getRawBits());
    CHECK_INT(-1.5f, -384, x->getRawBits());
}

void testInsertOperator()
{
    Fixed *x;

    SILENT( x = new Fixed(1.5f) );
    EXPECT_STDOUT( std::cout << *x, "1.5" );
    SILENT( delete x );
}

void testToFloat()
{
    CHECK_FLOAT(0.0f, 0.0f, f->toFloat());
    CHECK_FLOAT(-1.5f, -1.5f, f->toFloat());
    CHECK_FLOAT(42.42f, 42.42f, f->toFloat());
}

void testToInt()
{
    CHECK_INT(0.0f, 0, f->toInt());
    CHECK_INT(-1.5f, -1, f->toInt());
    CHECK_INT(42.42f, 42, f->toInt());
    CHECK_INT(1.0f, 1, f->toInt());
}

void testDestructor()
{
    Fixed *x;

    SILENT( x = new Fixed() );
    EXPECT_STDOUT( delete x, "Destructor called" );
}

int main()
{
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );
    a = Fixed( 1234.4321f );
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    RUN_TEST(testDefaultConstructor);
    RUN_TEST(testIntConstructor);
    RUN_TEST(testFloatConstructor);
    RUN_TEST(testInsertOperator);
    RUN_TEST(testToFloat);
    RUN_TEST(testToInt);
    RUN_TEST(testDestructor);
    return 0;
}