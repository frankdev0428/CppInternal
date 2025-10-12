
#ifndef POINT_H
#define POINT_H
class Point {
// a) overload the stream insertion operator as a friend function.
// Output the Point object in the format (x,y) e.g. (3.4,5.6)
protected:
double x, y; // no restrictions on these
public:
// b) overload preincrement (add 1 to x and add 1 to y)
// c) overload postincrement (add 1 to x and add 1 to y)
Point(double x = 0.0, double y = 0.0);
void setX(double x);
void setY(double y);
void moveBy(double dx, double dy); // add dx to x, dy to y
double getDistance(const Point& p) const; // use the distance formula
double getX() const;
double getY() const;
};
#endif
