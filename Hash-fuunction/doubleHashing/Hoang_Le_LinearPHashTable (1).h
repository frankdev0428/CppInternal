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
        int totalInsertProbeCount;
        int totalSearchProbeCount;
        std::vector<Item*> hashT;

        int a, b;   // Coefficients

        void generateCoeffs() {
            // Simplified
            a = rand() % (capacity - 1) + 1;   // [1, capacity)
            b = rand() % capacity;             // [0, capacity)
        }

        int hashFunction(int key) {
            return (a * key + b) % capacity;
        }

    public:
        // Constructor
        LinearPHashTable(int capacity = 101){
            this->capacity = capacity;
            numOfItems = 0;
            totalInsertProbeCount = 0;
            totalSearchProbeCount = 0;
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

        // new helper  member function 
        double getLoadFactor() const {
    return (double)numOfItems / capacity;
    }

   long getInsertProbeCount() const {
    return totalInsertProbeCount;
   }

   long getSearchProbeCount() const {
    return totalSearchProbeCount;
}
};

#endif


