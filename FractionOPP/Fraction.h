#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
    friend std::ostream& operator<<(std::ostream& out, const Fraction& frac);

    friend std::istream& operator>>(std::istream& in, Fraction& frac);

private:
    int n, d;

    static int getGCD(int b, int c); // return gcd of b and c
public:
    Fraction(int n1 = 0, int d1 = 1); // constructor

    Fraction& operator+=(const Fraction& other); // done

    Fraction operator+(const Fraction& other) const; //done

    Fraction& operator-=(const Fraction& other); //done

    Fraction operator-(const Fraction& other) const; //done

    Fraction operator-() const;  // unary - //done

    Fraction& operator*=(const Fraction& other); //done

    Fraction operator*(const Fraction& other) const; //done

    Fraction& operator/=(const Fraction& other); //done

    Fraction operator/(const Fraction& other) const; //done

    Fraction& operator++();   // pre increment //done

    Fraction operator++(int);  // post increment //done

    Fraction& operator--();   // pre decrement //done

    Fraction operator--(int);  // post decrement //done

    bool operator<(const Fraction& other) const; //done

    bool operator<=(const Fraction& other) const; //done 
 
   bool operator>(const Fraction& other) const; //done

    bool operator>=(const Fraction& other) const; //done

    bool operator==(const Fraction& other) const;     //done

    bool operator!=(const Fraction& other) const;   //done

    Fraction operator^ (int p) const;  // p > 0: take n^p/(d^p), // done  
    // p<0 take d^p/(n^p), 
    // p==0  gives back result = 1/1

    Fraction& operator^=(int p); // done 

    void printValue() const;

};


#endif