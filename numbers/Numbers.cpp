#include <iostream>
using namespace std;
#include "Numbers.h"

Numbers::Numbers(int num){
    number = num;
}
     void Numbers::print(){
       cout << number << endl;
     }
     int Numbers::getNum(){
       return number;
     }
     void Numbers::setNum(int n){
        number = n;
     }
    Numbers Numbers::operator+(const Numbers &other) {
        return Numbers(number + other.number);
    }
