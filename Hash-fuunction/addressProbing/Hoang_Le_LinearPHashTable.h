// Specification file for the HashTable class
// with Linear Probing
#ifndef LINEARPHASHTABLE_H
#define LINEARPHASHTABLE_H

#include <vector>
#include <string>
#include <cstdlib>
#include "Item.h"



class LinearPHashTable{
    private:
        int numOfItems, capacity;
        std::vector<Item*> hashT;
        long totalProbeCount;
        int maxProbeCount;
        int a, b;   // Coefficients
// void HashTable::generateCoeffs(){
//     srand(time(0)); //ensure different random each run

//     a = rand() % (capacity - 1) + 1; //[1, capacity]
//     b = rand() % capacity;           // [0, capacity]
//  }
        void generateCoeffs() {
           srand(time(0)); // ensure different random each run;
            a = rand() % (capacity - 1) + 1; // [1,capacity]
            b = rand() % capacity;  // [0,capacity];
        }

        int hashFunction(int key) {
            return (a * key + b) % capacity;
        }

    public:
        // Constructor
        LinearPHashTable(int capacity = 101){
            this->capacity = capacity;
            numOfItems = 0;
           totalProbeCount = 0;
           maxProbeCount = 0;
            hashT.resize(capacity);
            generateCoeffs();
        }

        // Getters
        int getNumofItems() const{
            return numOfItems;
        }
        int getCapacity() const{
            return capacity;
        }

        // Hash Table operations
        void insert(int, std::string);
        std::string deleteKey(int);
        std::string lookup(int);

        // Display all items in the hash table
        void display();
        // get load factor from the input table numbers 
        double getLoadFactor() const {
         return (double)numOfItems / capacity;
         }
         long getTotalProbeCount() const {
         return totalProbeCount;
     }

       int getMaxProbeCount() const {
         return maxProbeCount;
}

};

#endif


