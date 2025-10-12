#include "Square.h"
using namespace std;

// Constructor
Square::Square(int side)
    : Rectangle(side, side) {}  // both width and height = side

// setWidth: must keep square property
void Square::setWidth(int w) {
    Rectangle::setWidth(w);      // set width normally
    Rectangle::setHeight(getWidth());  // force height to match width
}

// setHeight: just call setWidth(h)
void Square::setHeight(int h) {
    setWidth(h);
}

// getType: append "/Square"
string Square::getType() const {
    return Rectangle::getType() + "/Square";
}
