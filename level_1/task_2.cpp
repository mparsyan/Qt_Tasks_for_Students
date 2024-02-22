/* Create a C++ program that demonstrates the use of different C++ data types (int, float, double, char, bool). Declare variables for each type, assign them values, and output their values to the console. This task helps understand the basic data types and variable declaration in C++. */

#include <iostream>

int main()
{
    int a;
    int b = 10;
    float c = 5.7;
    double d = 4;
    char e = 'e';
    bool f = true;

    std::cout << "a = " << a << std::endl
              << "b = " << b << std::endl
              << "c = " << c << std::endl
              << "d = " << d << std::endl
              << "e = " << e << std::endl;

    return 0;
}