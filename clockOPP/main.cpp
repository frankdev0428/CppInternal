#include <iostream>
#include "clock.h"
#include <chrono>
#include <thread>
using namespace std;


int main() {
   Clock c1(5 ,23 ,56);
   c1.print();
   Clock c2(26, -4, 88);
   c2.print();
   c2.setHour(-5);
   cout << c2.getHour() << endl;
   c2.setHour(12);
   c2.print();
   c2.setMinute(59);
   c1.setSecond(23);
   c1.print();
   for(int i = 0; i < 120; i++){
    c1.print();
    this_thread::
    sleep_for(chrono::milliseconds(1000));
    c1.tick();
   }
  return 0;
}