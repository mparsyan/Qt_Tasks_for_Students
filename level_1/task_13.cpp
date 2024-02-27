/* Create a base class Shape with a method to calculate the area and derive two classes from it: Circle and Rectangle. Implement the area calculation method for each derived class. This task introduces the concept of inheritance and polymorphism. */

#include <cmath>
#include <iostream>

class Shape
{
public:
    double calculate_area() const
    {
        return 0.0;
    }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double calculate_area() const
    {
        return M_PI * radius * radius;
    }
};

class Rectangle : public Shape
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double calculate_area() const
    {
        return length * width;
    }
};

int main()
{
    Circle myCircle(5.0);
    Rectangle myRectangle(4.0, 6.0);

    std::cout << "Area of Circle: " << myCircle.calculate_area() << std::endl;
    std::cout << "Area of Rectangle: " << myRectangle.calculate_area() << std::endl;

    return 0;
}