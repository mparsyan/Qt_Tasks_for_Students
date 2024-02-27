/* Design a Book class with attributes such as title, author, and ISBN. Include methods that allow setting and getting these attributes. In the main function, create an instance of the Book class and demonstrate setting and retrieving its attributes. This task is designed to introduce the principles of OOP, encapsulation, and the use of classes and objects. */

#include <iostream>

class Book
{
private:
    std::string title;
    std::string author;
    std::string ISBN;

public:
    std::string get_title() const
    {
        return title;
    }

    void set_title(const std::string& t)
    {
        title = t;
    }

    std::string get_author() const
    {
        return author;
    }

    void set_author(const std::string& a)
    {
        author = a;
    }

    std::string get_ISBN() const
    {
        return ISBN;
    }

    void set_ISBN(const std::string& I)
    {
        ISBN = I;
    }
};

int main()
{
    Book myBook;

    myBook.set_title("Effective Modern C++");
    myBook.set_author("Scott Meyers");
    myBook.set_ISBN("978-0-316-76948-0");

    std::cout << "Title: " << myBook.get_title() << std::endl;
    std::cout << "Author: " << myBook.get_author() << std::endl;
    std::cout << "ISBN: " << myBook.get_ISBN() << std::endl;

    return 0;
}

