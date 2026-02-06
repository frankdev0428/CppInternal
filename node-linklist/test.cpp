
#include <iostream>

using namespace std;


//problem 1


void interleave(char s[], char t[], char buffer[]);




int main() {

    char s[40], t[40], b[80];

    for (int i = 0; i < 10; i++) {

       cout << "Enter s: ";

       cin >> s;

       cout << "Enter t: ";

       cin >> t;

       interleave(s, t, b);

       cout << "Here is the interleave of s and t: ";

       cout << b << endl;
    }

    return 0;

}


/*

void interleave(char s[], char t[], char buffer[]) {

    while (*s != '\0' && *t != '\0')

    {
        *buffer++ = *s++ ;

        *buffer++ = *t++ ;

    }

    while (*s != '\0')

         *buffer++ = *s++;

    while (*t != '\0')

         *buffer++ = *t++; 

    *buffer = '\0';

    

}

*/








/*

void interleave(char s[], char t[], char buffer[]) {
    int i = 0, k = 0;
    while (s[i] != '\0' && t[i] != '\0')
    {
        buffer[k++] = s[i];
        buffer[k++] = t[i];
        i++;
    }
    // Why do we need the if-else ? (THINK)
    if (s[i] != '\0')
        while (s[i] != '\0')
            buffer[k++] = s[i++];
    else       
        while (t[i] != '\0')
            buffer[k++] = t[i++];
    buffer[k] = '\0';
    
}



*/




/*

void interleave(char s[], char t[], char buffer[]) {

    int i = 0, j = 0,  k = 0;

    while (s[i] != '\0' || t[j] != '\0')

    {

        if (s[i] != '\0')

            buffer[k++] = s[i++];

        if (t[j] != '\0')

            buffer[k++] = t[j++];   

    }

    buffer[k] = '\0';

    

}

*/





/*

void interleave(char s[], char t[], char buffer[]) {

    while (*s && *t)

    {

        *buffer++ = *s++ ;

        *buffer++ = *t++ ;

    }

    while (*s)

         *buffer++ = *s++;

    while (*t)

         *buffer++ = *t++; 

    *buffer = '\0';

    

}

*/

void interleave(char s[], char t[], char buffer[]) {
    while (*s || *t)
    {
        if (*s)
            *buffer++ = *s++;
        if (*t)
            *buffer++ =  *t++;
    }
    *buffer = '\0';
}

int main() {

    char s[40], t[40], b[80];

    for (int i = 0; i < 10; i++) {

             cout << "Enter s: ";

             cin >> s;

             cout << "Enter t: ";     

             cin >> t;  

             interleave(s, t, b);

             cout << "Here is the interleave of s and t: ";

             cout << b << endl;
     }


     return 0;

}
/// problem 2
POINT.H//////

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


#endif // PERSON_H
/////// POINT.CPP
#include "Point.h"
#include <iostream>
#include <cmath>
using namespace std;

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
cout << "(" << x << ", " << y << ")";
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


// problem 3 - 3 problem using recursion 
bool canMakeInRange(int nums[], int length, int min, int max) {
    if (length == 0)
        return (min <= 0 && max >= 0);
    if (canMakeInRange(nums, length - 1, min, max))
        return true;

    int last = nums[length - 1];
    return canMakeInRange(nums, length - 1, min - last, max - last);
}

bool canMakeInRange(int nums[], int length, int min, int max){
    if (length == 0)
        return (min <= 0 && max >= 0);
    if (canMakeInRange(nums,length - 1, min,max))
        return true;
    int last = nums(length - 1);
    return canMakeInRange(nums, length - 1, min - last, int max);
}



bool canMakeTotal(int n , int total){

	 if (total == 0) return true;
    if (n == 0) return false;
    if (total < 0) return false;

    if (n < 0) n = -n;
    int digit = n % 10;
    return canMakeTotal(n / 10, total - digit) || canMakeTotal(n / 10, total);
	}


int fastIntegerRoot(int n) {
   
    if (n == 0)
        return 0;

 
    int t = fastIntegerRoot(n / 4);

    if ((2 * t + 1) * (2 * t + 1) <= n)
        return 2 * t + 1;
    else
        return 2 * t;
}



// problem 4 
Shape& Shape::operator*= (int k){
if (k <= 0)
return *this;
// multiply both width and height of the current object by k
width *= k;
height *= k;
return *this;
}

Shape& Shape::operator*= (int k){
    //check if the k input > 0
    if (k <= 0)
    //do nothing
    return *this;
    // if k valid then execute below code
    // mutiply all the value inner public class to a k value 
    width *= k;
    height *= k;
    return *this;
}

cout << ++((*r) *= 5) << endl;
  
Shape Shape::operator* (int k) const {
Shape temp = *this;
temp *= k;
return temp;
}

Shape Shape::operator+ (const Shape& rhs) const {
Shape temp = *this;
temp += rhs;
return temp;
}

// problem 5 
void printBackwards(Node* first)
{
    if (first == nullptr)      
        return;
    printBackwards(first->next);   
    cout << first->value << " ";   
}



// problem 6 merge function 
#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node(int v = 0, Node *n = nullptr) {
        value = v;
        next = n;
    }
};


Node * merge(Node *n1, Node * n2) {
    if (n1 == nullptr) return n2;
    if (n2 == nullptr) return n1;
   if (n1->value > n2->value) swap(n1, n2);
    Node* first = n1;
    Node* last = first;
    n1 = n1->next;
   while (n1 != nullptr && n2 != nullptr) {
        if (n1->value <= n2->value) {
            last->next = n1;
            last = n1;
            n1 = n1->next;
        }
        else {
            last->next = n2;
            last = n2;
            n2 = n2->next;
        }
    }
    if (n1 == nullptr) last->next = n2;
    else last->next = n1;
    return first;
}



void print(Node* first) {
    while (first != nullptr) {
        cout << first->value << " ";
        first = first->next;
    }
    cout << endl;
}

int main()
{
    Node* n1 = nullptr, * n2 = nullptr;
    n1 = new Node(13, n1);
    n1 = new Node(10, n1);
    n1 = new Node(6, n1);
    n1 = new Node(3, n1);
    n1 = new Node(1, n1);
    n2 = new Node(12, n2);
    n2 = new Node(11, n2);
    n2 = new Node(9, n2);
    n2 = new Node(8, n2);
    n2 = new Node(7, n2);
    n2 = new Node(5, n2);
    n2 = new Node(4, n2);
    n2 = new Node(2, n2);
    print(n1);
    print(n2);
    print(merge(n1, n2));
    return 0;

}