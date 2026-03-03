// Specification file for the HashTable class
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <vector>
#include <string>
#include "List.h"

class HashTable{
    private:
        int numOfItems, capacity;
        std::vector<List> hashT;
        int a,b; // universal hash coefficient

        // Private universal hash function
        int hashFunction(int key){
          
            return (a*key + b) % capacity;
        }

    public:
        // Constructor
        HashTable(int capacity = 101){
            this->capacity = capacity;
            numOfItems = 0;
            a = rand() % (capacity - 1) + 1;
            b = rand() % capacity;
            hashT.resize(capacity);
        }

        // Getter
        int getNumofItems() const{
            return numOfItems;
        }

        // Hash Table operations
        void insert(int, std::string);
        void deleteKey(int);
        std::string lookup(int);
        void rehash(int newSize);
        // Load factor helper function
double getLoadFactor() const {
    return (double)numOfItems / capacity;
}

int getCapacity() const {
    return capacity;
}

int getLocationSize(int index) const {
    return hashT[index].getSize();
}
};

#endif

