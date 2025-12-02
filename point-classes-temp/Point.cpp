#include "Point.h"
#include <iostream>
#include <cmath>
using namespace std;
// Implement a class called Point with private members x and y of type int along with public static const member MAX_X and MAX_Y initialized to 2000 and 1000 respectively.

// x and y should always have legal values meaning x >= 0, y >= 0, x <= MAX_X and y <= MAX_Y. 

// An attempt to set x or y to an illegal value means they will get nearest legal value.

// Of course, provide appropriate getters and setters (both public).

// Constructor should take two parameters to initialize x and y.  Parameters will both have default values 0.

// Also, implement the public member functions below.   

// double distance(const Point & other) const;  that returns the distance between the current object and other.

// bool operator<(const Point & other) const;   that returns true if... the current object's distance from the origin ( x=y = 0) is less than other's distance from the origin, and returns false otherwise.

// bool operator==(const Point & other) const;   that returns true if... the current object's x and y are equal to other's x and y, respectively (and returns false otherwise).

// bool operator>(const Point & other) const;   that returns true if other < *this and false otherwise.

// bool operator<=(const Point & other) const;   that returns false if other < *this and returns true otherwise.

// bool operator>=(const Point & other) const   that returns false if *this < other and returns true otherwise.

int Point::clampX(int value) const {
    if (value < 0) return 0;
    if (value > MAX_X) return MAX_X;
    return value;
}

int Point::clampY(int value) const {
    if (value < 0) return 0;
    if (value > MAX_Y) return MAX_Y;
    return value;
}

Point::Point(int xVal, int yVal){
    x = clampX(xVal);
    y = clampY(yVal);
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

void Point::setX(int xVal) {
    x = clampX(xVal);
}

void Point::setY(int yVal){
    y = clampY(yVal);
}

void::Point::setPoint(int xVal,int yVal){
    setX(xVal);
    setY(yVal);
}

void Point::print() const {
    cout <<  "(" << x << ", " << y << ")";
}

double Point::distance(const Point &other) const {
    int dx = x - other.x;
    int dy = y - other.y;
    return sqrt(dx*dx + dy*dy);
}

bool Point::operator<(const Point &other) const{
    double d1 = sqrt(x*x + y*y);
    double d2 = sqrt(other.x*other.x + other.y*other.y);
    return d1<d2;
}

bool Point::operator==(const Point &other) const {
    return (x == other.x && y == other.y);
}

bool Point::operator> (const Point &other)const {
    return other < *this;
}

bool Point::operator<=(const Point &other) const {
    return !(other < *this);
}

bool Point::operator>=(const Point &other) const {
    return !(*this < other);
}













// Point::Point(int x = 0,int y = 0);

//   void getPoint();
//   void setPoint(int point);
//   double distance(const Point & other) {

//   };
//   bool operator<(const Point & other) {

//   };
//   bool Point::operator==(const Point & other) const; 
//   bool operator>(const Point & other) const;
//   bool Point::operator<=(const Point & other) const;
//   bool Point::operator>=(const Point & other) const ;