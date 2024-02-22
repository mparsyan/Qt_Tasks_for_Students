/* Create a program that demonstrates the use of function pointers by implementing a sorting algorithm selector. This program should allow the user to choose between at least two sorting algorithms (e.g., Bubble Sort and Selection Sort) to sort an array of integers. The selection of the sorting algorithm will be done through function pointers, showcasing how they can be used to invoke different functions dynamically based on user input. */

#include <iostream>
#include <map>

void bubble_sort (int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        bool flag = true;
        for (int j = 0; j < size - 1 - i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                flag = false;
            }
        }
        if (flag)
        {
            break;
        }
    }
}

void selection_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int min_index = i;

        for (int j = i + 1; j < size; ++j)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            std::swap(arr[i], arr[min_index]);
        }
    }
}

int main()
{
    int option;
    std::cout << "1 - Bubble Sort\n" << "2 - Selection Sort\n";
    std::cin >> option;
    while (option != 1 && option != 2)
    {
        std::cin >> option;
    } 

    std::map<int, void(*)(int[], int)> mp;
    mp[1] = bubble_sort;
    mp[2] = selection_sort;

    int arr[]{2, 5, 27, 0, 3, 24, 1};
    int size = sizeof(arr) / sizeof(int);

    std::cout << "The original array is: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    mp[option](arr,size);

    std::cout << "The sorting array is: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}