#pragma once

#include "rectangle.hpp"

template <class T>
class Square : public Rectangle<T>
{
public:
    Square(const Point<T> &center, T l) : Rectangle<T>(center, l, l)
    {
    }

    template <class U>
    friend std::ostream &operator<<(std::ostream &os, const Square<U> &square);
};

template <class T>
std::ostream &operator<<(std::ostream &os, const Square<T> &square)
{
    os << "Square: L = " << square.a_ << ", Center = " << square.center_ << ", Area = " << square.area() << ", Perimeter = " << square.perimeter();
    return os;
}