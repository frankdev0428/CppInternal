#include "Rectangle.h"
//Constructor: call Parallelogram constructor with topShift:
Rectangle::Rectangle(int width , int height): Parallelogram(width, height, 0){}
std::string Rectangle::getType() const{
    return "Rectangle";
};
