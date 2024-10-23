#pragma once

#include "shape.hpp"

template <class T>
class Rectangle : public Shape<T>
{
public:
    Rectangle(const Point<T> &center, T a, T b) : Shape<T>(center), a_(a), b_(b)
    {
    }

    T area() const override
    {
        return a_ * b_;
    }

    T perimeter() const override
    {
        return (a_ + b_) * 2;
    }

    template <class U>
    friend std::ostream &operator<<(std::ostream &os, const Rectangle<U> &rectangle);

protected:
    T a_, b_; // Sides length
};

template <class T>
std::ostream &operator<<(std::ostream &os, const Rectangle<T> &rectangle)
{
    os << "Rectangle: A = " << rectangle.a_ << ", B = " << rectangle.b_ << ", Center = " << rectangle.center_ << ", Area = " << rectangle.area() << ", Perimeter = " << rectangle.perimeter();
    return os;
}