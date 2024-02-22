/* Develop a program that asks the user for a number and then, using if-else statements, checks whether the number is positive, negative, or zero. Extend the program with a switch-case to assign a grade (A, B, C, D, F) based on a number range (e.g., 90-100 for A). Lastly, implement a loop that prints numbers from 1 to 10. This task teaches the fundamental control structures for program flow. */

#include <iostream>

int main()
{
    int num;
    std::cout << "Enter the number: ";
    std::cin >> num;
    if (num > 0)
    {
        std::cout << "Number is positive\n";
    }
    else if (num < 0)
    {
        std::cout << "Number is negative\n";
    }
    else
    {
        std::cout << "Number is zero\n";
    }

    char grade;
    switch (num)
    {
    case 90 ... 100 :
        grade = 'A';
        break;

    case 80 ... 89:
        grade = 'B';
        break;

    case 70 ... 79:
        grade = 'C';
        break;

    case 60 ... 69:
        grade = 'D';
        break;

    case 50 ... 59:
        grade = 'F';
        break;

    default:
        break;
    }
    std::cout << "Grade is " << grade << std::endl;

    std::cout << "Numbers 1 to 10: ";
    for (int i = 1; i <= 10; ++i)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    return 0;
}