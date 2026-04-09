#include <iostream>
#include "BinaryHeap.h"
using namespace std;

int main() {
  BinaryHeap bh;
// Insertions
bh.insert(42);
bh.insert(15);
bh.insert(23);
bh.insert(8);
bh.insert(16);
bh.insert(4);
bh.insert(30);
std::cout << "Heap after insertions:\n";
bh.display();
std::cout << "Current heap size: " << bh.getCurrentSize();
// First deleteMin
int num;
bh.deleteMin(num);
std::cout << "\n\nElement deleted: " << num << std::endl;
std::cout << "Heap after first deleteMin:\n";
bh.display();
std::cout << "Current heap size: " << bh.getCurrentSize();
// Second deleteMin
bh.deleteMin(num);
std::cout << "\n\nElement deleted: " << num << std::endl;
std::cout << "Heap after second deleteMin:\n";
bh.display();
std::cout << "Current heap size: " << bh.getCurrentSize();
// decreaseKey
bh.decreaseKey(3, 30);
std::cout << "\n\nHeap after decreaseKey on the 4th element by 30:\n";
bh.display();
std::cout << "Current heap size: " << bh.getCurrentSize();
// increaseKey
bh.increaseKey(1, 20);
std::cout << "\n\nHeap after increaseKey on the 2nd element by 20:\n";
bh.display();
std::cout << "Current heap size: " << bh.getCurrentSize();
// remove
bh.remove(2);
std::cout << "\n\nHeap after removing the 3rd element:\n";
bh.display();
std::cout << "Current heap size: " << bh.getCurrentSize();
cout << endl;


    return 0;
}