
// CircleExample.cpp : This file contains the 'main' function. Program execution
//begins and ends there
// General version of the class
// Class hirrachie is more specific version of that class 

#include <iostream>
#include "Point.h"
#include "Circle.h"
#include "Circle1.h"
using namespace std;
int main()
{
Circle c(100, 100, 1);
const Circle UNIT(0, 0, 1);
cout << c.getArea() << endl;
cout << c.getCircumference() << endl;
cout << c.getLocation().getX() << endl;
cout << c.getLocation().getY() << endl;
cout << c.getDistance(UNIT) << endl;
c.moveBy(20.0, 10.0);
cout << c.getLocation().getX() << endl;
cout << c.getLocation().getY() << endl;
cout << c.getDistance(UNIT) << endl;
cout << endl << endl;
cout << "----------------------" << endl;
Circle1 c1(100, 100, 1);
const Circle1 UNIT1(0, 0, 1);
cout << c1.getArea() << endl;
cout << c1.getCircumference() << endl;
cout << c1.getLocation().getX() << endl;
cout << c1.getLocation().getY() << endl;
cout << c1.getDistance(UNIT1) << endl;
c1.moveBy(20.0, 10.0);
cout << c1.getLocation().getX() << endl;
cout << c1.getLocation().getY() << endl;
cout << c1.getDistance(UNIT1) << endl;
cout << endl << endl;
// return 0;
}
