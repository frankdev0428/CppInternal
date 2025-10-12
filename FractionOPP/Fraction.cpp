 #include "Fraction.h"


    std::ostream& operator<<(std::ostream& out, const Fraction& frac) {
       // print fration value to the output 
       out << frac.n << "/" << frac.d;
        return out;
    }

    std::istream& operator>>(std::istream& in, Fraction& frac) {
      in >> frac.n >> frac.d;
      // check if denominator = 0
      if(frac.d == 0){
        frac.d = 1;
       }
       //flip sign if denominator negative
      if (frac.d < 0){
        frac.n = -frac.n;
        frac.d = -frac.d;
      }
        return in;
    }

    int Fraction::Fraction::getGCD(int b, int c) {
       b = (b < 0) ? -b : b;
       c = (c < 0) ? -c : c;
       while(c != 0){
        int temp = c;
        c = b % c;
        b = temp;
       }
        return b;
    }

    Fraction::Fraction(int n1, int d1) {
        n = n1;
        d = d1 != 0 ? d1 : 1; 
        if (d < 0) {
            n = -n;
            d = -d;
        }
    }

    Fraction& Fraction::operator+=(const Fraction& other) {
     // add current fraction to other fraction 
     // available n ,d 
     int newNume = n*other.d + d*other.n;
     int newDeno = d*other.d;
     int g = getGCD(abs(newNume),abs(newDeno));
     newNume /= g;
     newDeno /= g;
     if(newDeno < 0){
        newNume = -newNume;
        newDeno = -newDeno;
     }
     // assign new value to n,d after calculation process 
     n = newNume;
     d = newDeno;
        return *this;
    }

    Fraction Fraction::operator+(const Fraction& other) const {
        Fraction temp = *this;
        temp += other;
        return temp;
    }

    Fraction& Fraction::operator-=(const Fraction& other) {
     int newNume = n * other.d - d * other.n;
     int newDeno = d * other.d;
     int g = getGCD(abs(newNume),abs(newDeno));
     newNume /= g;
     newDeno /= g;
     if(newDeno < 0){
        newNume = -newNume;
        newDeno = -newDeno;
     }
     // assign new value to n,d after calculation process 
     n = newNume;
     d = newDeno;
        return *this;
    }

    Fraction Fraction::operator-(const Fraction& other) const {
        Fraction temp = *this;
        temp -= other;
        return temp;
    }

    Fraction Fraction::operator-() const {
        Fraction temp = *this;
        temp.n = -temp.n;
        return temp;
    }

    Fraction& Fraction::operator*=(const Fraction& other) {
        int newNum = n*other.n;
        int newDen = d*other.d;
        int g = getGCD(abs(newNum),abs(newDen));
        newNum /= g;
        newDen /= g;
        if (newDen < 0){
            newNum = -newNum;
            newDen = -newDen;
        }
        n = newNum;
        d = newDen;
        return *this;
    }

    Fraction Fraction::operator*(const Fraction& other) const {
        Fraction temp = *this;
        temp *= other;
        return temp;
    }

    Fraction& Fraction::operator/=(const Fraction& other) {
        int newNum = n*other.d;
        int newDen = d*other.n;
        int g = getGCD(abs(newNum),abs(newDen));
        newNum /= g;
        newDen /= g;
        if(newDen < 0){
            newNum  = -newNum;
            newDen = -newDen;
        }
        n = newNum;
        d = newDen;
        return *this;
    }

    Fraction Fraction::operator/(const Fraction& other) const {
        Fraction temp = *this;
        temp /= other;
        return temp;
    }

    Fraction& Fraction::operator++() {
       int newNum = n + d;
       int newDen = d;
       int g = getGCD(abs(newNum),abs(newDen));
       if(g != 0){
        newNum /= g;
        newDen /= g;
       }
       if(d < 0){
        newNum = -newNum;
        newDen = -newDen;
       }
       n = newNum;
       d = newDen;
       return *this;
    }

    Fraction Fraction::operator++(int) {
       Fraction temp = *this; // save old value

       // increment current object
        n = n + d;
        int g = getGCD(abs(n), abs(d));
    if (g != 0) {
        n /= g;
        d /= g;
    }

    if (d < 0) {
        n = -n;
        d = -d;
    }

    return temp; // return old value
    }

    Fraction& Fraction::operator--() {
      int newNum = n - d;
      int newDe = d;
      int g = getGCD(abs(newNum),abs(newDe));
      if (g != 0){
        newNum /= g;
        newDe /= g;
      }
      if (newDe < 0){
        newNum = -newNum;
        newDe = -newDe;
      }
      n = newNum;
      d = newDe;
        return *this;
    }

    Fraction Fraction::operator--(int) {
        Fraction temp = *this;
      n = n - d;
      int g = getGCD(abs(n),abs(d));
      if (g != 0){
        n /= g;
        d /= g; 
      }
      if(d < 0){
        n = -n;
        d = -d;
      }
        return temp;
    }

    bool Fraction::operator<(const Fraction& other) const {
        return (n * other.d) < (other.n * d);
    }

    bool Fraction::operator<=(const Fraction& other) const {

        return  (n * other.d) <= (other.n * d);
    }

    bool Fraction::operator>(const Fraction& other) const {
         return (n * other.d) > (other.n * d);
    }

    bool Fraction::operator>=(const Fraction& other) const {
         
        return (n * other.d) >= (other.n * d);
    }

    bool Fraction::operator==(const Fraction& other) const {

        return (n * other.d) == (other.n * d);
    }

    bool Fraction::operator!=(const Fraction& other) const {

        return (n * other.d) != (other.n * d);
    }

    Fraction Fraction::operator^ (int p) const {
      // if p = o
      if (p == 0){
        return Fraction(1,1); 
       }
      // return fracntion(1,1)
      long long newNum = 1;
      long long newDe = 1;
      // new num , newde
      int exp = (p > 0) ? p : -p;
      // loop to raise power
       for (int i = 0; i < exp;i++){
        newNum *= n;
        newDe *= d;
       }

      //if p < 0 swap n,d
      if (p < 0){
        std::swap(newNum,newDe);

      }
      //getgcd
       int g = getGCD(abs(newNum),abs(newDe));
       if(g != 0){
        newNum /= g;
        newDe /= g;
       }
      //check deno <0
     if(newDe < 0){
        newNum = -newNum;
        newDe = -newDe;
     }
      //return fraction
        return Fraction(newNum,newDe);
    }

    Fraction& Fraction::operator^=(int p) {
     Fraction newFrac = Fraction(n,d) ^ p;
      n = newFrac.n;
      d = newFrac.d;
        return *this;
    }

    void Fraction::printValue() const {
         std::cout << n << "/" << d << std::endl;
    }
