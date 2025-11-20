#ifndef LINKEDLIST_H

#define LINKEDLIST_H

#include <stdexcept>

// This will be a linked list of int's.

// Later we will code a generalized version of

// a linked list that can store other types of data.




template <class T>

class Node {

public:

 T value; // the data

 Node<T>* next; // pointer to the next node




 Node(T v = 0, Node<T>* n = nullptr) {

 value = v;

 next = n;

 }

};




template <class T>

class LinkedList {

private:

 Node<T>* headPtr;

 int length;




public:

 LinkedList() {

 length = 0;

 headPtr = nullptr;

 }




 //LinkedList(LinkedList& other);

 ~LinkedList() {

 //std::cout << "In destructor" << std::endl;




 while (headPtr != nullptr) {

 Node<T>* toDelete = headPtr;

 headPtr = headPtr->next;

 delete toDelete;

 }




 }




 void insertFirst(T v) {

 Node<T>* toInsert = new Node<T>(v, headPtr);

 headPtr = toInsert;

 length++;

 }

 void removeFirst() {

 if (headPtr == nullptr)

 return;

 Node<T>* toDelete = headPtr;

 headPtr = headPtr->next;

 delete toDelete;

 length--;

 }

 bool contains(T target) {

 Node<T>* temp = headPtr;

 while (temp != nullptr) {

 if (temp->value == target) return true;

 temp = temp->next;

 }

 return false;

 }




 T getFirst() const {

 if (length == 0)

 throw std::logic_error("Can't get first value in an empty list!");

 return headPtr->value;




 }

 void printList() const {

 std::cout << "< ";

 Node<T>* current = headPtr;

 while (current != nullptr) {

 std::cout << current->value << ' ';

 current = current->next;




 }

 std::cout << ">" << std::endl;

 }




 int getLength() const {

 return length;

 }

 Node<T>* getNode(int index) {

 if (index < 0 || index >= length)

 return nullptr;

 Node<T>* n = headPtr;

 while (n->next != nullptr)

 n = n->next;

 return n;

 }







 T& operator[] (int index) {

 Node<T>* n = getNode(index); // Save result. DO NOT call function twice.

 if (n == nullptr)

 throw std::logic_error("Index out of bounds");

 return n->value;

 }

 /**********************************************/




 //void removeAValue(int v); // find and remove the first occurrence of v

 //void removeAtIndex(int index);  // remove the value at the given index

 //void insertAtIndex(int value, int index); // insert a value at the given index




};










#endif




/*

#include "LinkedList.h"

#include <stdexcept>

#include <iostream>




Node::Node(int v, Node* n) {

 value = v;

 next = n;

}










LinkedList::LinkedList() {

 length = 0;

 headPtr = nullptr;

}




LinkedList::~LinkedList() {

 std::cout << "In destructor" << std::endl;




 while (headPtr != nullptr) {

 Node* toDelete = headPtr;

 headPtr = headPtr->next;

 delete toDelete;

 }

}







void LinkedList::insertFirst(int v) {

 Node* toInsert = new Node(v, headPtr);

 headPtr = toInsert;




 //headPtr = new Node(v, headPtr);







 length++;

}







void LinkedList::removeFirst() {

 if (headPtr == nullptr)

 return;

 Node* toDelete = headPtr;

 headPtr = headPtr->next;

 delete toDelete;

 length--;

}

int LinkedList::getFirst() const {

 if (length == 0)

 throw std::logic_error("Can't get first value in an empty list!");

 return headPtr->value;

}

void LinkedList::printList() const {

 std::cout << "< ";

 Node* current = headPtr;

 while (current != nullptr) {

 std::cout << current->value << ' ';

 current = current->next;




 }

 std::cout << ">" << std::endl;

}




int LinkedList::getLength() const {

 return length;

}

*/


// DRIVER