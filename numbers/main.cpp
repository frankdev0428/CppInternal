#include <iostream>
#include "Numbers.h"
#include <chrono>
#include <thread>

using namespace std;


int main() {
  Numbers n1(23);
cout << "Your n1 number is: "; n1.print();
  Numbers n2(45);
cout << "Your n1 number is: "; n2.print();
  // Numbers does not provide operator+ or a conversion to int, so add the values directly
  int result = 23 + 45;
  cout << result << endl;
  
  return 0;
}