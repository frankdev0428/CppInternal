#include "Square.h"
using namespace std;

// Constructor
Square::Square(int side)
    : Rectangle(side, side) {}  // both width and height = side

// setWidth: must keep square property
void Square::setWidth(int w) {
        // set width normally
     // force height to match width
}

// setHeight: just call setWidth(h)
void Square::setHeight(int h) {
  
}

// getType: append "/Square"
string Square::getType() const {
    
}
