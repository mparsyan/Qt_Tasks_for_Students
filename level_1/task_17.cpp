/* Introduce the concept of exception handling within an inheritance hierarchy. Create a base class Shape with an area calculation method that might throw an exception (e.g., if the shape's dimensions are not set). Then, derive two classes from it: Circle and Rectangle. Implement the area calculation method for each derived class to handle or throw exceptions as appropriate. */

#include <cmath>
#include <iostream>

class Shape
{
public:
    virtual double calculate_area() const
    {
        throw std::runtime_error("Dimensions not set for the shape!");
    }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) 
    {
        if (r < 0)
        {
            throw std::invalid_argument("Radius cannot be negative!");
        }
    }

    double calculate_area() const override
    {
        if (radius <= 0)
        {
            throw std::invalid_argument("Radius not set or invalid!");
        }

        return M_PI * radius * radius;
    }
};

class Rectangle : public Shape
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) 
    {
        if (length < 0 || width < 0)
        {
            throw std::invalid_argument("Length or width cannot be negative!");
        }
    }

    double calculate_area() const override
    {
        if (length <= 0 || width <= 0)
        {
            throw std::invalid_argument("Length or width not set or invalid!");
        }

        return length * width;
    }
};

int main()
{
    try
    {
        Circle myCircle(5.0);
        std::cout << "Area of Circle: " << myCircle.calculate_area() << std::endl;

        Rectangle invalidRectangle(-3.0, 8.0);
    }
    catch (std::exception& ex)
    {
        std::cerr << "Exception caught: " << ex.what() << std::endl;
    }

    return 0;
}