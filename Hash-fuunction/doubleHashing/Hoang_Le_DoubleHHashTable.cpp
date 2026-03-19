// Implementation file for the HashTable class
#include <iostream>
#include <string>
#include "Hoang_Le_DoubleHHashTable.h"

// insert member function
void DoubleHHashTable::insert(int key, std::string value){
    // Find the key's location using hash function #1
    int base = hash1(key);
    int location = base;

    // Find the probing distance using hash function #2
    int step = hash2(key);

    Item* temp = new Item(key, value);
    int counter = 0;

    // Double hashing to find an empty or deleted slot
    // Continue to probe when the slot is not empty or deleted,
    // and the key at the slot is NOT our key.
    while(hashT[location] != NULL &&
          hashT[location]->key != -1 && 
          hashT[location]->key != key){
        
        // Have already searched the entire hash table, stop.
        if (counter++ >= capacity)
            return;

        // Double hashing
        location = (base + counter * step) % capacity;
    }
   //count the final successful probe attemp
   totalInsertProbeCount++;
    // if inserting into empty or deleted slot, increase numOfItems.
    if (hashT[location] == NULL || hashT[location]->key == -1)
        numOfItems++;

    hashT[location] = temp;
}

// delete member function
// It returns the value of the deleted item if found
std::string DoubleHHashTable::deleteKey(int key){
    // Find the key's location using hash function #1
    int base = hash1(key);
    int location = base;

    // Find the probing distance using hash function #2
    int step = hash2(key);

    int counter = 0;

    // Double hashing to find the key
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

        // Double hashing
        location = (base + counter * step) % capacity;
    }
    return "";
}

// lookup member function
std::string DoubleHHashTable::lookup(int key){
    // Find the key's location using hash function #1
    int base = hash1(key);
    int location = base;

    // Find the probing distance using hash function #2
    int step = hash2(key);

    int counter = 0;

    // Double hashing to find the key
    while(hashT[location] != NULL){
   totalSearchProbeCount++;
        // Key not found
        if (counter++ >= capacity)
            return "";  

        if (hashT[location]->key == key)
            return hashT[location]->value;

        // continue probing using Double hashing
        location = (base + counter * step) % capacity;
    }

    return "";
}

// Display all items in the hash table
void DoubleHHashTable::display(){
    for (int i = 0; i < capacity; i++){
        if (hashT[i] != NULL && hashT[i]->key != -1)
            std::cout << "[" << hashT[i]->key << ": " 
            << hashT[i]->value << "]" << std::endl;
    }
}

