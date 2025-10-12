// FractionDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//g++ tester.cpp Fraction.cpp -o tester // run build programmer g++ 
// ./tester
#include <iostream>
#include "Fraction.h"
using std::cout;
using std::cin;
using std::endl;
using namespace std;

int main()
{
  Fraction f1(1, 2);
  Fraction g1(2, 3);

  //test += operator with gcd()
  cout << "f1: "; f1.printValue(); 
  cout << "g1: "; g1.printValue();
  f1 += g1;
  cout << "result f1 + g1 = "; f1.printValue();
  //cout << "g1: "; g1.printValue();
  // test -= operator with gcd()
  Fraction f2(2, 3);
  Fraction g2(5, 6);
  cout << "f2: "; f2.printValue();
  cout << "g2: "; g2.printValue();
  f2 -= g2;
  cout << "result f2 - g2 = "; f2.printValue();
  //cout << "g2: "; g2.printValue();
  
  // test /= operator with gcd()
  Fraction f3(4,7);
  Fraction g3(4,8);
  cout << "f3: ";f3.printValue();
  cout << "g3: ";g3.printValue();
  f3 /= g3;
  cout << "The total of f3/g3 = "; f3.printValue();
  //cout << "The value of g3: "; g3.printValue();
  //test *= operator with gcd()
  Fraction f4(2,3);
  Fraction g4(2,6);
  cout << "f4: ";f4.printValue();
  cout << "g4: ";g4.printValue();
  f4 *= g4;
  cout << "The result f4*g4 = "; f4.printValue();
  //cout << "The value of g4: "; g4.printValue();
  // test operation+
  Fraction f4testPlus = f4 + g4;
  cout << "The total of f4 + g4 = "; f4testPlus.printValue();
  // test oepration-
  Fraction f4testMinus = f4 - g4;
  cout << "The result of f4 - g4 = "; f4testMinus.printValue(); 
  // test operator *
  Fraction f4TestMultiply = f4 * g4;
  cout << "The result of f4 * g4 = "; f4TestMultiply.printValue();
  //test operator /
  Fraction f4TestDevide = f4/g4;
  cout << "The result of f4/g4 = "; f4TestDevide.printValue();
  //test unary -
  Fraction fUnary = -f4;
  cout << "Flip the sign of fraction Numerator f4: "; fUnary.printValue();
  Fraction fFlipTest  = (-f4) - g4;
  cout << "(-f4) - g4 = "; fFlipTest.printValue();
  // test pre-increment
  Fraction f5(4,6);
  cout << "f5: "; f5.printValue();
  ++f5;
  cout << "++f5 = "; f5.printValue();
 //test post-increment
   //Fraction f5(3,5);
   Fraction post = f4++;
   cout << "f4: "; post.printValue();
   cout << "f4++ = "; f4.printValue();
// test pre-decrement
   Fraction f6(3,7);
   cout << "f6: "; f6.printValue();
   --f6;
   cout << "--f6 = ";f6.printValue();
// test post-decrement
   Fraction postDe = f6--;
   cout << "f6(old value) = ";postDe.printValue();
   cout << "f6: " ;f6.printValue();
// test < operator
   bool result = f5 < f6;
// test bool value 
  cout << std::boolalpha;
  cout << "f5 < f6 " << (f5 < f6) << endl;
  cout << "f5 <= f6 " << (f5 <= f6) << endl;
  cout << "f5 > f6 " << (f5 > f6) << endl;
  cout << "f5 > f6 " << (f5 >= f6) << endl;
  cout << "f5 == f6 " << (f5 == f6) << endl;
  cout << "f5 != f6 " << (f5 != f6) << endl;
// test power 
  Fraction powerP(4,3);
  Fraction p6 = powerP ^ 6; 
  cout << "PowerP ^ 6: "; p6.printValue();
  cout << "PowerP: "; powerP.printValue();
  Fraction p2 = powerP ^ 2;
  cout << "PowerP ^ 2: "; p2.printValue();
  cout << "Fraction PowerP "; powerP.printValue();

Fraction powerF(2,5);
cout << " powerF: "; powerF.printValue();
Fraction powerNF = powerF ^ -1;
cout << "powerF ^ -1 : "; powerNF.printValue();
powerF^= 3;
cout << "PowerF ^ 3 "; powerF.printValue();

//general test 
Fraction pp3(3,7);
cout << "Fration pp3: "; pp3.printValue();
Fraction pp4(1,5);
cout << "pp4: "; pp4.printValue();
Fraction ppS = pp3 - pp4;
cout << "pp3 - pp4 = "; ppS.printValue();
Fraction ppSPow = ppS ^ -1;
cout << "ppS ^ 1 = "; ppSPow.printValue();
Fraction testPP = ppSPow - Fraction(31,8);
testPP.printValue();
//Calculate user input sample output
Fraction fftest;
Fraction fftest2;
cout << "Enter a fraction 1: " << endl;
cin >> fftest;
cout << "You enter: " << fftest << endl;
cout << "Enter a fraction 2: " << endl;
cin >> fftest2;
cout << "You enter: " << fftest2 << endl;
cout << "Fraction1 + fraction 2 = " << (fftest + fftest2) << endl; 
cout << "Fraction1 - fraction 2 = " << (fftest - fftest2) << endl; 
cout << "Fraction1 * fraction 2 = " << (fftest * fftest2) << endl; 
cout << "Fraction1 / fraction 2 = " << (fftest / fftest2) << endl; 
cout << "Fraction1 > fraction 2:  " << (fftest > fftest2) << endl; 
cout << "Fraction1 < fraction 2:  " << (fftest < fftest2) << endl; 
cout << "Fraction1 = fraction 2:  " << (fftest == fftest2) << endl; 
cout << "Fraction1 != fraction 2:  " << (fftest != fftest2) << endl; 
}