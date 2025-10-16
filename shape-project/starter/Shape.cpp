#include "Shape.h"
using namespace std;
#include <iostream>

// Initialize static variable
int Shape::shapeCount = 0;

Shape::Shape(int w, int h): ID(++shapeCount) {
// Set width and height via setters.
 
}

void Shape::printInformation() const{
   
}

int Shape::getWidth() const {


// Just return width.
}
int Shape::getHeight() const{
   
// Just return height.
}

 void Shape::draw() const {
// This is a pure virtual method.
}

 void Shape::setWidth(int w) {
   
}
// The width must be at least 2.
 void Shape::setHeight(int h){
   
}
// The height must be at least 2.
 double Shape::getArea() const{
   //using static_cast to convert interger to double
   return static_cast<double>(width * height);
}
// Approximated by bounding rectangle = width* height.
 double Shape::getPerimeter() const {
   return 0.0;
}
// Another pure virtual method.
 string Shape::getType() const{
   return "Shape";
}

