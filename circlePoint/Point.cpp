
#include "Point.h"
#include <cmath>
Point::Point(double x, double y) {
setX(x);
setY(y);
}
double Point::getDistance(const Point& p) const {
double dx = this->x - p.x, dy = this->y - p.y;
return sqrt(dx * dx + dy * dy);
}
void Point::setX(double x) {
this->x = x;
}
void Point::setY(double y) {
this->y = y;
}
double Point::getX() const {
return x;
}
double Point::getY() const {
return y;
}
void Point::moveBy(double dx, double dy) {
x += dx;
y += dy;
}
