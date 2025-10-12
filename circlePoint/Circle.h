
#ifndef CIRCLE_H
#define CIRCLE_H
#include "Point.h"
// Circle via aggregation
class Circle {
private:
Point location;
double radius; // must be positive
public:
Circle(double x = 0.0, double y = 0.0, double radius = 1.0);
void setLocation(const Point& location);
void setRadius(double radius);
Point getLocation() const;
double getX() const;
double getY() const;
double getRadius() const;
double getArea() const;
double getCircumference() const;
void moveBy(double dx, double dy);
double getDistance(const Circle& c) const;
};
#endif
