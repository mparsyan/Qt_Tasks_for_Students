/* Write a program that creates a text file and writes a list of names into it. Then, open the same file for reading and print its contents to the console. This task aims to teach basic file input and output operations, including opening, reading, writing, and closing files. */

#include <vector>
#include <fstream>
#include <iostream>

int main()
{
    std::vector<std::string> names = {"Alice", "Bob", "Charlie", "David", "Eva"};

    std::ofstream output_file("names.txt");
    if (output_file.is_open())
    {
        for (const std::string& name : names)
        {
            output_file << name << std::endl;
        }

        output_file.close();
        std::cout << "File created and names written successfully." << std::endl;
    } 
    else 
    {
        std::cerr << "Error opening the file for writing." << std::endl;
        return 1;  
    }

    std::ifstream input_file("names.txt");
    if(input_file.is_open())
    {
        std::string line;
        while (std::getline(input_file, line))
        {
            std::cout << line << std::endl;
        }
        input_file.close();
    } 
    else 
    {
        std::cerr << "Error opening the file for reading." << std::endl;
        return 1;  
    }

    return 0;
}