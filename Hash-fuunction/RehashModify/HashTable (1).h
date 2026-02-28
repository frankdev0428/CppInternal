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

        // Private universal hash function
        int hashFunction(int key){
            // a and b can be changed.
            int a = 7;
            int b = 4;

            return (a*key + b) % capacity;
        }

    public:
        // Constructor
        HashTable(int capacity = 101){
            this->capacity = capacity;
            numOfItems = 0;
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
};

#endif

