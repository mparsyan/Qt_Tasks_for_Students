/* Enhance the sorting algorithm selector program by incorporating enums to represent different sorting strategies and structs to bundle sorting functions with their names. This variation introduces a more structured approach to selecting and invoking sorting algorithms, demonstrating how enums, structs, and function pointers can work together to create a flexible and user-friendly program. */

#include <iostream>

void bubble_sort (int* arr, int size)
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

void selection_sort(int* arr, int size)
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

enum SortingStrategy
{
    BUBBLE_SORT = 1,
    SELECTION_SORT
};

struct SortingOption
{
    SortingStrategy strategy;
    void (*sort_func)(int*, int);
};

int main()
{
    const int size = 5;
    int arr[size];
    std::cout << "Enter the array: " << std::endl;
    for(int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }
    
    int choice;
    std::cout << "Choose the algorithm: 1 - bubble sort, 2 - selection sort: ";
    std::cin >> choice;

    SortingOption options[] = 
    {
        {BUBBLE_SORT, bubble_sort}, 
        {SELECTION_SORT, selection_sort}
    };


    bool validChoice = false;
    for (const auto& option : options) 
    {
        if (static_cast<int>(option.strategy) == choice) 
        {
            validChoice = true;
            option.sort_func(arr, size);
            break;
        }
    }

    if (!validChoice) 
    {
        std::cout << "Invalid choice!" << std::endl;
        return 1;
    }

    std::cout << "Sorted array: ";
    for(int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}