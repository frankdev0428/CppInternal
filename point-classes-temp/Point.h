#ifndef POINT_H
#define POINT_H

#include <string>

class Point {
private:
   static const int MAX_X = 2000;
   static const int MAX_Y = 1000;
   int x;
   int y; 
   int clampX(int value) const;
   int clampY(int value) const;
public: 
  Point(int x = 0,int y = 0);
  
  int getX() const;
  int getY() const;
  void setX(int x);
  void setY(int y);
  void setPoint(int x, int y);
  void print() const;
  double distance(const Point &other) const;
  
  bool operator<(const Point &other) const;
  bool operator==(const Point &other) const; 
  bool operator>(const Point &other) const;
  bool operator<=(const Point &other) const;
  bool operator>=(const Point &other) const ;
};

#endif // PERSON_H