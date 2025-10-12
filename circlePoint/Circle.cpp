
#include "Circle.h"
#include <cmath>
Circle::Circle(double x, double y, double radius) {
location.setX(x);
location.setY(y);
setRadius(radius);
}
void Circle::setLocation(const Point& location) {
this->location = location;
}
void Circle::setRadius(double radius) {
if (radius <= 0.0) // radius must be positive
radius = 1.0;
this->radius = radius;
}
Point Circle::getLocation() const {
return location;
}
double Circle::getDistance(const Circle & c) const {
return this->location.getDistance(c.location);
}
double Circle::getX() const {
location.getX();
}
double Circle::getY() const {
location.getY();
}
double Circle::getRadius() const {
return radius;
}
double Circle::getArea() const {
return acos(-1)* radius * radius;
}
double Circle::getCircumference() const {
return 2 * acos(-1) * radius;
}
void Circle::moveBy(double dx, double dy) {
location.moveBy(dx, dy);
}
