// Specification file for the HashTable class
// with Double Hashing
#ifndef DOUBLEHASH_H
#define DOUBLEHASH_H

#include <vector>
#include <string>
#include <cstdlib>
#include "Item.h"

class DoubleHHashTable{
    private:
        int numOfItems, capacity;
        long totalInsertProbeCount;
        long totalSearchProbeCount;
        std::vector<Item*> hashT;

        int a, b;   // Coefficients
        int R;

        void generateCoeffs() {
             a = rand() % (capacity - 1) + 1;   // [1, capacity)
             b = rand() % capacity;             // [0, capacity)
        }

        // First (original) hash function
        int hash1(int key) {
            return (a * key + b) % capacity;
        }

        // Second hash function
        int hash2(int key){
            return R - (key % R);
        }

        // A function to check if a number is prime
        bool isPrime(int n){
            // 0 and 1 are not prime.
            // Negative numbers are not considered.
            if (n <= 1) return false;
            // 2 is the only even prime number.
            if (n == 2) return true;
            // Any other even number is not prime.
            if (n % 2 == 0) return false;

            // Check for divisors from 3 up to the sqrt of n,
            // incrementing by 2 to check only odd numbers.
            for (int i = 3; i * i <= n; i += 2){
                if (n % i == 0){
                    return false;    // Found a divisor, not prime.
                }
            }

            // If no divisors were found in the loop, it is prime.
            return true;
        }

    public:
        // Constructor
        DoubleHHashTable(int capacity = 101){
            this->capacity = capacity;
            numOfItems = 0;
            hashT.resize(capacity);
            generateCoeffs();   // For hash function #1

            // For hash function #2
            // Find the largest prime number smaller than capacity.
            R = capacity - 1;
            while(isPrime(R) == false){
                R--;
            }
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

        // new member helper function 

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


