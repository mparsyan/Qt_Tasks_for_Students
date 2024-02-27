/* Modify the sorting algorithm selector program to read an array of integers from a file, sort the array using a selected algorithm, and then save the sorted array back to a file. This variation integrates file I/O with enums, structs, and function pointers, showcasing how to manipulate data read from and written to files in C++. */

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

void bubble_sort (std::vector<int>& vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        bool flag = true;
        for (int j = 0; j < vec.size() - 1 - i; ++j)
        {
            if (vec[j] > vec[j + 1])
            {
                std::swap(vec[j], vec[j + 1]);
                flag = false;
            }
        }
        if (flag)
        {
            break;
        }
    }
}

void selection_sort(std::vector<int>& vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        int min_index = i;

        for (int j = i + 1; j < vec.size(); ++j)
        {
            if (vec[j] < vec[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            std::swap(vec[i], vec[min_index]);
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
    void (*sort_func)(std::vector<int>&);
};

void read_from_file(const std::string& input_file, std::vector<int>& vec)
{
    std::ifstream file(input_file);
    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open file " << input_file << std::endl;
        exit(EXIT_FAILURE);
    }

    int num;
    while (file >> num)
    {
        vec.push_back(num);
    }

    file.close();
}

void save_to_file(const std::string& output_file, const std::vector<int>& vec)
{
    std::ofstream file(output_file);
    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open file " << output_file << std::endl;
        exit(EXIT_FAILURE);
    }

    for (int num : vec)
    {
        file << num << " ";
    }

    file.close();
}

int main()
{
    std::vector<int> vec;
    std::string input_file, output_file;
    int sorting_choice;

    std::cout << "Enter the name of the input file: ";
    std::cin >> input_file;

    read_from_file(input_file, vec);

    SortingOption options[] =
    {
        {BUBBLE_SORT, bubble_sort},
        {SELECTION_SORT, selection_sort}
    };

    std::cout << "Select a sorting algorithm:\n"
              << "1. Bubble Sort\n"
              << "2. Selection Sort\n"
              << "Enter your choice: ";
    std::cin >> sorting_choice;

    if (sorting_choice < 1 || sorting_choice > 2)
    {
        std::cerr << "Invalid sorting choice. Exiting.\n";
        exit(EXIT_FAILURE);
    }

    options[sorting_choice - 1].sort_func(vec);

    std::cout << "Enter the name of the output file: ";
    std::cin >> output_file;

    save_to_file(output_file, vec);

    std::cout << "Sorting and saving complete.\n";

    return 0;
}