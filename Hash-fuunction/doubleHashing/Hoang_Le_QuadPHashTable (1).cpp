// Implementation file for the HashTable class
#include <iostream>
#include <string>
#include "Hoang_Le_QuadPHashTable.h"

// insert member function
  void QuadPHashTable::insert(int key, std::string value){
     int base = hashFunction(key);
int location = base;
int i = 0;

  while(hashT[location] != NULL &&
      hashT[location]->key != -1 &&
      hashT[location]->key != key)
   {
    totalInsertProbeCount++;
    i++;
    location = (base + i*i) % capacity;
  }

    totalInsertProbeCount++;
    }

    // if inserting into empty or deleted slot, increase numOfItems.
    if (hashT[location] == NULL || hashT[location]->key == -1)
        numOfItems++;

    hashT[location] = temp;
    totalProbeCount++;
    if(probeCountForThisInsert > maxProbeCount)
        maxProbeCount = probeCountForThisInsert;
}

// delete member function
// It returns the value of the deleted item if found
std::string QuadPHashTable::deleteKey(int key){
    // Find the key's location using the hash function
    int base = hashFunction(key);
    int location = base;

    int counter = 0;

    // Quadratic probing to find the key
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

        // Quadratic probing
        location = (base + counter * counter) % capacity;
    }
    
    return "";
}

// lookup member function
std::string QuadPHashTable::lookup(int key){
    // Find the key's location using the hash function
    int base = hashFunction(key);
    int location = base;

    int counter = 0;

    // Quadratic probing to find the key
    while(hashT[location] != NULL){

        // Key not found
        if (counter++ >= capacity)
            return "";  

        if (hashT[location]->key == key)
            return hashT[location]->value;

        // Quadratic probing
        location = (base + counter * counter) % capacity;
    }

    return "";
}

// Display all items in the hash table
void QuadPHashTable::display(){
    for (int i = 0; i < capacity; i++){
        if (hashT[i] != NULL && hashT[i]->key != -1)
            std::cout << "[" << hashT[i]->key << ": " 
            << hashT[i]->value << "]" << std::endl;
    }
}