#include "Triangle.h"
#include <iostream>
#include <cmath>
using namespace std;

// Constructor
Triangle::Triangle(int w, int h)
    : Shape(w, h) {
    // make sure width >= 3
    setWidth(w);
}

// Ensure width >= 3
void Triangle::setWidth(int w) {
    Shape::setWidth((w >= 3) ? w : 3);
}

// Draw an ASCII triangle
void Triangle::draw() const {
    int h = getHeight();
    int w = getWidth();

    // simple isosceles triangle
    for (int i = 1; i <= h; ++i) {
        int stars = (i * w) / h;       // number of stars per row
        int spaces = (w - stars) / 2;  // center it
        cout << string(spaces, ' ') << string(stars, '*') << endl;
    }
}

// Compute area (1/2 * base * height)
double Triangle::getArea() const {
    return Shape::getArea() / 2.0;
}

// Compute perimeter using Pythagorean theorem
double Triangle::getPerimeter() const {
    double halfBase = getWidth() / 2.0;
    double side = sqrt(pow(halfBase, 2) + pow(getHeight(), 2));
    return getWidth() + 2 * side;
}

// Return type name
string Triangle::getType() const {
    return Shape::getType() + "/Triangle";
}
