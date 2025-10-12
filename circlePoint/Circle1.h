
#ifndef CIRCLE1_H
#define CIRCLE1_H
#include "Point.h"
// Circle via inheritance
class Circle1 : public Point {
private:
double radius; // must be positive
public:
Circle1(double x = 0.0, double y = 0.0, double radius = 1.0) ;
void setLocation(const Point& location);
void setRadius(double radius);
Point getLocation() const;
double getRadius() const;
double getArea() const;
double getCircumference() const;
};
#endif
