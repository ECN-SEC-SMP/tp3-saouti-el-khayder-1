#pragma once

#include <iostream>

template <class T>
class Point
{
public:
    Point(T x, T y) : _x(x), _y(y) {}
    Point(const Point<T> &other) : _x(other._x), _y(other._y) {}

    void Translate(T x, T y)
    {
        _x += x;
        _y += y;
    }

    T GetX() { return _x; }
    void SetX(T value) { _x = value; }

    T GetY() { return _y; }
    void SetY(T value) { _y = value; }

    template <class U>
    friend std::ostream &operator<<(std::ostream &os, const Point<U> &point);

private:
    T _x, _y;
};

template <class T>
std::ostream &operator<<(std::ostream &os, const Point<T> &point)
{
    os << '(' << point._x << ", " << point._y << ')';
    return os;
}