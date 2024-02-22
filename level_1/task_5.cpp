/* Implement a program where you define an array of integers and populate it with some values. Write functions to find the maximum, minimum, and average values in the array. Additionally, create a string variable and demonstrate basic string operations like concatenation and length calculation. This task focuses on data collection management using arrays and strings. */

#include <iostream>

int main()
{
    int arr[]{12, 24, 5, 9, 1, -7, 14};
    int min = arr[0];
    int max = arr[0];
    double sum = 0;

    int size = sizeof(arr) / sizeof(int);
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }

        if (arr[i] > max)
        {
            max = arr[i];
        }

        sum += arr[i];
    }

    double average = sum / size;

    std::cout << "Minimum element is: " << min << std::endl;
    std::cout << "Maximum element is: " << max << std::endl;
    std::cout << "The average is: " << average << std::endl;

    return 0;
} 