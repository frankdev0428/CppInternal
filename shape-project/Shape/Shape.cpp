#include "Shape.h"
using namespace std;
#include <iostream>

// Initialize static variable
int Shape::shapeCount = 0;

Shape::Shape(int w, int h): ID(++shapeCount) {
// Set width and height via setters.
    setWidth(w);
    setHeight(h);
}

void Shape::printInformation() const{
    cout << "ID=" << ID
         << "\twidth=" << width
         << "\theight=" << height
         << "\tarea=" << getArea()
         << "\tperim=" << getPerimeter()
         << "\ttype= Shape/" << getType()
         << endl;
// See the sample output as a guide.
}

int Shape::getWidth() const {
return width;
// Just return width.
}
int Shape::getHeight() const{
   return height;
// Just return height.
}

 void Shape::draw() const {
// This is a pure virtual method.
}

 void Shape::setWidth(int w) {
   width = (w >= 2) ? w : 2;
}
// The width must be at least 2.
 void Shape::setHeight(int h){
   height = (h >= 2) ? h : 2;
}
// The height must be at least 2.
 double Shape::getArea() const{
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

