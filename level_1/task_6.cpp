/* Create a program that declares an integer variable, a pointer variable, and a reference variable. Assign the address of the integer to the pointer and manipulate the data using both the pointer and the reference. Output the results to ensure an understanding of how pointers and references are used to access and modify data. */

#include <iostream>

int main()
{
    int a = 5;
    int* ptr = &a;
    int& ref = a;

    std::cout << "a = " << a << std::endl;
    std::cout << "a + 1 = " << *ptr + 1 << " (with using pointer)" << std::endl;
    std::cout << "a = " << ref << " (with using reference)" << std::endl;

    return 0;
}