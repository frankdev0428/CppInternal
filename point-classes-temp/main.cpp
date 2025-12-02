#include <iostream>
#include "Point.h"
using namespace std;

int main() {

    Point p1; 
    cout<<"p1: "; p1.print(); cout<<"\n";

    Point p2(10,20);
    cout << "p2-->";
    p2.print();
    cout << endl;

    // try negative values
    Point p3(-5, 20000);
    cout << "p3??? ";
    p3.print();
    cout << "\n";

    // random setters
    p1.setX(5000);  
    p1.setY(-99);
    cout<<"after setting p1: ";
    p1.print();
    cout<<"\n";

    // try distance
    cout << "dist: " << p1.distance(p2) << endl;

    // try comparisons
    if(p1 < p2){
        cout<<"p1<p2\n";
    }
    if(p2 > p1){
        cout<<"p2>p1\n";
    }

    // equals?
    Point t1(5,5), t2(5,5), t3(7,5);
    if(t1==t2) cout<<"t1==t2\n";
    if(t1==t3) cout<<"t1==t3??? no\n";

    // more weird testing
    Point z(100,100);
    Point zz(200,200);
    cout<<"z<=zz: " << (z<=zz) << "\n";
    cout<<"zz<=z: " << (zz<=z) << "\n";

    // random prints
    cout<<"zz>=z: "<<(zz>=z)<<"\n";
    cout<<"z>=zz: "<<(z>=zz)<<"\n";

    // testing setPoint
    p2.setPoint(1234,99999);
    cout<<"p2 setPoint test: ";
    p2.print();
    cout<<"\n";

    // some repeated nonsense tests
    cout<<"origin dist tests:\n";
    Point q1(3,4);
    Point q2(6,8);
    cout<<q1.distance(Point())<<"\n";  // distance from origin
    cout<<q2.distance(Point())<<"\n";

    // more random
    cout<<"Compare q1 and q2: ";
    cout<<(q1<q2)<<","<<(q2<q1)<<endl;

    // uncomment to try different things
    // Point abc(9999, -8888);
    // abc.print();

    cout<<"done???\n";

    return 0;
}
