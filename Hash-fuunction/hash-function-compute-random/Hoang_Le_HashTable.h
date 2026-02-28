// Specification file for the HashTable class
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <string>
#include "Hoang_Le_List.h"
#include <ctime>
#include <cstdlib>


class HashTable{
    private:
        int numOfItems, capacity;
        std::vector<List> hashT;
        int a;           //coefficient a
        int b;           //coefficient b

        //generate random coefficienets
        void generateCoeffs();

       // Universal hash function
       int hashFunction(int key);


        // Private universal hash function
        // int hashFunction(int key){
        //     // a and b can be changed.
        //     int a = 7;
        //     int b = 4;

        //     return (a*key + b) % capacity;
        // }


    public:
        // Constructor
        HashTable(int capacity = 101);

        // Getter
        int getNumofItems() const;

        // Hash Table operations
        void insert(int, std::string);
        void deleteKey(int);
        std::string lookup(int);

        // New member function 
        int getLocationSize(int index);
        void displayLocation(int index);

};

#endif

