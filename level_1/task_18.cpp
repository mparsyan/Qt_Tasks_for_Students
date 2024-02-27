/* Explore C++ templates in the context of class inheritance. Create a template base class Shape that allows for different numeric types (e.g., int, float, double) for dimensions. Derive specialized classes Circle and Rectangle from this template class, implementing area calculations specific to the numeric type. */

#include <cmath>
#include <iostream>

template <typename T>
class Shape
{
public:
    virtual T calculate_area() const
    {
        return 0.0;
    }
};

template <typename T>
class Circle : public Shape<T>
{
private:
    T radius;

public:
    Circle(T r) : radius(r) {}

    T calculate_area() const override
    {
        return M_PI * radius * radius;
    }
};

template <typename T>
class Rectangle : public Shape<T>
{
private:
    T length;
    T width;

public:
    Rectangle(T l, T w) : length(l), width(w) {}

    T calculate_area() const override
    {
        return length * width;
    }
};

int main()
{
    Circle<int> intCircle(5);
    Rectangle<int> intRectangle(4, 6);

    std::cout << "Area of Circle: " << intCircle.calculate_area() << std::endl;
    std::cout << "Area of Rectangle: " << intRectangle.calculate_area() << std::endl;

    Circle<double> doubleCircle(5.5);
    Rectangle<double> doubleRectangle(4.5, 6.5);

    std::cout << "Area of Circle: " << doubleCircle.calculate_area() << std::endl;
    std::cout << "Area of Rectangle: " << doubleRectangle.calculate_area() << std::endl;

    return 0;
}