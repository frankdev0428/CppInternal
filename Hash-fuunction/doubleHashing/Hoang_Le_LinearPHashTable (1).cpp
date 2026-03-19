// Implementation file for the HashTable class
#include <iostream>
#include <string>
#include "Hoang_Le_LinearPHashTable.h"

// insert member function
void LinearPHashTable::insert(int key, std::string value){
    int location = hashFunction(key);
    int probeCount = 1;

    while(hashT[location] != NULL &&
          hashT[location]->key != -1 &&
          hashT[location]->key != key)
    {
        totalInsertProbeCount++;
        location = (location + 1) % capacity;
        probeCount++;
    }

    totalInsertProbeCount++;

    if (hashT[location] == NULL || hashT[location]->key == -1)
        numOfItems++;

    hashT[location] = new Item(key, value);
}

// delete member function
// It returns the value of the deleted item if found
std::string LinearPHashTable::deleteKey(int key){
    // Find the key's location using the hash function
    int location = hashFunction(key);

    int counter = 0;

    // Linear probing to find the key
    while(hashT[location] != NULL){

        // Key not found
        if (counter++ >= capacity)
            return "";

        if (hashT[location]->key == key){
            std::string data = hashT[location]->value;

            // Mark the location empty
            hashT[location]->key = -1;
            hashT[location]->value = "";

            numOfItems--;
            return data;
        }

        // Linear probing
        location = (location + 1) % capacity;
    }
    
    return "";
}

// lookup member function
std::string LinearPHashTable::lookup(int key){
    // Find the key's location using the hash function
    int location = hashFunction(key);

    int counter = 0;

    // Linear probing to find the key
    while(hashT[location] != NULL){

        // Key not found
        if (counter++ >= capacity)
            return "";  

        if (hashT[location]->key == key)
            return hashT[location]->value;

        // Linear probing
        location = (location + 1) % capacity;
    }

    return "";
}

// Display all items in the hash table
void LinearPHashTable::display(){
    for (int i = 0; i < capacity; i++){
        if (hashT[i] != NULL && hashT[i]->key != -1)
            std::cout << "[" << hashT[i]->key << ": " 
            << hashT[i]->value << "]" << std::endl;
    }
}