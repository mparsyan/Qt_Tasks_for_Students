/* Write a program that contains functions for basic arithmetic operations (add, subtract, multiply, divide). Each function should accept two parameters and return the result of the operation. Test these functions by invoking them from the main function. This task introduces the concept of functions, parameter passing, and return types. */

#include <iostream>

double add(double a, double b)
{
    return a + b;
}

double sub(double a, double b)
{
    return a - b;
}

double mul(double a, double b)
{
    return a * b;
}

double div(double a, double b)
{
    return a / b;
}

int main()
{
    double a, b;
    std::cout << "Enter the a: ";
    std::cin >> a;
    std::cout << "Enter the b: ";
    std::cin >> b;

    std::cout << "a + b = " << add(a, b) << std::endl;
    std::cout << "a - b = " << sub(a, b) << std::endl;
    std::cout << "a * b = " << mul(a, b) << std::endl;
    std::cout << "a / b = " << div(a, b) << std::endl;

    return 0;
}