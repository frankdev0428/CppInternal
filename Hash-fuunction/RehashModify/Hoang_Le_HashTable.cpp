// Implementation file for the HashTable class
#include <iostream>
#include <string>
#include "Hoang_Le_HashTable.h"

// insert member function: O(1)
void HashTable::insert(int key, std::string value){
    // Find the key's location using the hash function
    int location = hashFunction(key);

    hashT[location].insertNode(key, value);

    numOfItems++;
}

void getNumberRehash tv 
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

// rehash function implement
void HashTable::rehash(int newSize){
//save the old table -> move the content to another vector
   std::vector<List> oldTable = std::move(hashT);
// double table size
   capacity = newSize;
// resize new table
   hashT.clear();
   hashT.resize(capacity);
  
//reset the variables numOfItems to 0
   numOfItems = 0;
// Update Hash function generate random coefficient a an b to create  new hash function .
   a = rand() % (capacity - 1) + 1; // a != 0
   b = rand() % capacity;
//Migtate data , iterate through every loation of ld vector then use insert operation to hash them into the new loations.
  for (int i = 0;i < olTable.size(); i++){
     List::ListNode* nodePtr = oldTable[i].getHead();

     while  (nodePtr){
      insert(nodePtr->key, nodePtr->value);
      nodePtr = nodePtr->next;
     }
  }
}