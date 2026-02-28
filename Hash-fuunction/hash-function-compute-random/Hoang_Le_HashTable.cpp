// Implementation file for the HashTable class
#include "Hoang_Le_HashTable.h"


//Constructor
 HashTable::HashTable(int capacity){
    this->capacity = capacity;
    numOfItems = 0;
    hashT.resize(capacity);

    generateCoeffs();    // generate random a and b;
 }

 // Generat random coefficients
 void HashTable::generateCoeffs(){
    srand(time(0)); //ensure different random each run

    a = rand() % (capacity - 1) + 1; //[1, capacity]
    b = rand() % capacity;           // [0, capacity]
 }

 // Universal hash function 
 int HashTable::hashFunction(int key) {
    return (a * key + b) % capacity;
 }

int HashTable::getNumofItems() const {
    return numOfItems;
}

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


// NEW: get location size

int HashTable::getLocationSize(int index) {
    return hashT[index].getSize();
}

// NEW: display the location 
void HashTable::displayLocation(int index){
    hashT[index].displayList();
}

