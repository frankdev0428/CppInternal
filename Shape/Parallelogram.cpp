#include "Parallelogram.h"
#include <iostream>
#include <cmath>
using namespace std;

// Constructor
Parallelogram::Parallelogram(int w, int h, int top)
    : Shape(w, h) {
    setTopShift(top);
}

// Draw the parallelogram using ASCII
void Parallelogram::draw() const {
    int h = getHeight();
    int w = getWidth();
    int shift = topShift;

    for (int i = 0; i < h; i++) {
        // spaces for slant
        int spaces = (h - i - 1) * shift / h;
        cout << string(spaces, ' ') << string(w, '*') << endl;
    }
}

// Compute perimeter using Pythagorean theorem
double Parallelogram::getPerimeter() const {
    double side = sqrt(pow(topShift, 2) + pow(getHeight(), 2));
    return 2 * side + 2 * getWidth();
}

// Setter for topShift (must be nonnegative)
void Parallelogram::setTopShift(int t) {
    topShift = (t >= 0) ? t : 0;
}

// Return type string
string Parallelogram::getType() const {
    return Shape::getType() + "/Parallelogram";
}
