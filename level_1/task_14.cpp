/* Modify the Shape class to make the area calculation method virtual. Create a function that takes a pointer to a Shape and prints its area, demonstrating polymorphic behavior. This task explores dynamic polymorphism and the use of virtual functions. */

#include <cmath>
#include <iostream>

class Shape
{
public:
    virtual double calculate_area() const
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

    double calculate_area() const override
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

    double calculate_area() const override
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