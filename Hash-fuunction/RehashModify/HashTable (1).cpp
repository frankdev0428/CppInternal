// Implementation file for the HashTable class
#include <iostream>
#include <string>
#include "HashTable.h"

// insert member function: O(1)
void HashTable::insert(int key, std::string value){
    // Find the key's location using the hash function
    int location = hashFunction(key);

    hashT[location].insertNode(key, value);

    numOfItems++;
}

// delete member function: O(1 + L(x))
void HashTable::deleteKey(int key){
    // Find the key's location using the hash function
    int location = hashFunction(key);

    if (hashT[location].deleteNode(key)){
        numOfItems--;
    }
}

// lookup member function: O(1 + L(x))
std::string HashTable::lookup(int key){
    // Find the key's location using the hash function
    int location = hashFunction(key);

    std::string result = hashT[location].search(key);

    // result will be an empty string if item not found.
    return result;
}

