#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Hoang_Le_HashTable.h"
using namespace std;

int main() {

HashTable ht(23);
cout << "Hash Table Initial Capacity: "
     << ht.getCapacity() << endl << endl;

ifstream file("data.txt");
if (!file) {
    cout << "Error opening file." << endl;
    return 1;
}
int key;
string value;

// read file
while (file >> key >> value) {
    ht.insert(key,value);
}

file.close()
 //Rehash until load factor <= 0.7
 while(ht.getLoadFactor() > 0.7){
    int newSize = ht.getCapacity() * 2 + 1;
    cout << "Load factor exceeded 0.7. Rehashing to capacity "
        << newSize << "..." << endl;
        ht.rehash(newSize);
 }
// find location with most collisions
int maxIndex = 0;
int maxSize = 0;

for (int i = 0; i < ht.getCapacity(); i++){
    int size = ht.getLocationSize(i);
    if (size > maxSize){
        maxSize = size;
        maxIndex = i;
    }
}
cout << endl;
cout << "Location with the most collisions: Index "
     << maxIndex << endl;
cout << "Number of items at this locaiton: "
     << maxSize << endl;
     
 return 0;   
}