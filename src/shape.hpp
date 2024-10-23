#pragma once

#include "point.hpp"

template <class T>
class ShapesList;

template <class T>
class Shape
{
public:
    Shape(const Point<T> &center) : center_(center)
    {
    }

    virtual T area() const = 0;
    virtual T perimeter() const = 0;

    template <class U>
    friend std::ostream &operator<<(std::ostream &os, const Shape<U> &shape);

    friend class ShapesList<T>;

protected:
    Point<T> center_;
};

template <class T>
std::ostream &operator<<(std::ostream &os, const Shape<T> &shape)
{
    os << "Center " << shape.center_;
    return os;
}