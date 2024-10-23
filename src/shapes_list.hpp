#pragma once

#include <memory>
#include <vector>

#include "shape.hpp"
#include "square.hpp"

template <class T>
class ShapesList
{
public:
    // ShapesList() {};

    void Push(std::shared_ptr<Shape<T>> shape)
    {
        _storage.push_back(shape);
    }

    T TotalArea()
    {
        T result = 0;

        for (auto &el : _storage)
        {
            result += el->area();
        }

        return result;
    }

    T TotalPerimeter()
    {
        T result = 0;

        for (auto &el : _storage)
        {
            result += el->perimeter();
        }

        return result;
    }

    Rectangle<float> BoundingBox()
    {
        float tlX, tlY, brX, brY; // tl = Top Left, br = bottom Right

        for (auto &el : _storage)
        {
            if (el->center_.GetX() < tlX)
                tlX = el->center_.GetX();
            if (el->center_.GetY() < tlY)
                tlY = el->center_.GetY();

            if (el->center_.GetX() > brX)
                brX = el->center_.GetX();
            if (el->center_.GetY() > brY)
                brY = el->center_.GetY();
        }

        return Rectangle<float>(Point((brX + tlX) / 2, (brY + tlY) / 2), brX + tlX, brY + tlY);
    }

private:
    std::vector<std::shared_ptr<Shape<T>>> _storage;
};
