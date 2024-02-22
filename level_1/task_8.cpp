/* Define an enum for days of the week and a struct representing a Date with day, month, and year as fields. Write a function that prints the day of the week and the date in a readable format. This task introduces structured data types and enumerations for more organized code. */

#include <iostream>

enum Week
{
    Monday, 
    Tuesday, 
    Wednesday, 
    Thursday, 
    Friday, 
    Saturday,
    Sunday
};

struct Date
{
    int day;
    std::string month;
    int year;
};

void print_date(const Date& date, int day_of_week)
{
    std::cout << "Date: ";
    switch (day_of_week)
    {
        case Week::Monday:
        std::cout << "Monday, ";
        break;

        case Week::Tuesday:
        std::cout << "Tuesday, ";
        break;

        case Week::Wednesday:
        std::cout << "Wednesday, ";
        break;

        case Week::Thursday:
        std::cout << "Thursday, ";
        break;

        case Week::Friday:
        std::cout << "Friday, ";
        break;

        case Week::Saturday:
        std::cout << "Saturday, ";
        break;

        case Week::Sunday:
        std::cout << "Sunday, ";
        break;
    }

    std::cout << date.day << " " << date.month << " " << date.year << std::endl;
}

int main()
{
    Date date;

    std::cout << "Enter the day of the week (0-6): ";
    int day_of_week;
    std::cin >> day_of_week;

    std::cout << "Enter the day: ";
    std::cin >> date.day;

    std::cout << "Enter the month: ";
    std::cin >> date.month;

    std::cout << "Enter the year: ";
    std::cin >> date.year;

    print_date(date, day_of_week);
    
    return 0;
}