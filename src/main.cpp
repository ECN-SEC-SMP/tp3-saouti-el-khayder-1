#include <iostream>

#include "point.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "shapes_list.hpp"

int main()
{
    Point<int> pInt(1, 2);
    Point<float> pFloat(1.01f, 2.02f);
    Point<double> pDouble(1.01, 2.02);

    auto rect = std::make_shared<Rectangle<int>>(pInt, 1, 2);
    auto square = std::make_shared<Square<int>>(pInt, 1);

    ShapesList<int> l;
    l.Push(rect);
    l.Push(square);

    std::cout << l.TotalArea() << std::endl;
    std::cout << l.TotalPerimeter() << std::endl;
    std::cout << l.BoundingBox() << std::endl;
}