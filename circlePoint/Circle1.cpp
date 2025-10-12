
#include "Circle1.h"
#include <cmath>
// Circle via inheritance
Circle1::Circle1(double x, double y, double radius) : Point(x,y)
{
setRadius(radius);
}
void Circle1::setLocation(const Point& location) {
x = location.getX();
y = location.getY();
}
Point Circle1::getLocation() const {
return (Point) (*this); // coerce the current object to a Point
}
void Circle1::setRadius(double radius) {
if (radius <= 0.0) // radius mus be positive
radius = 1.0;
this->radius = radius;
}
double Circle1::getRadius() const {
return radius;
}
double Circle1::getArea() const {
return acos(-1) * radius * radius; // acos(-1) evaluates to pi
}
double Circle1::getCircumference() const {
return 2 * acos(-1) * radius;
}
