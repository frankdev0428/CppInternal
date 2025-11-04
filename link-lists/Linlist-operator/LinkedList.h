#ifndef LINKEDLIST_H

#define LINKEDLIST_H

#include <stdexcept>

// This will be a linked list of int's.

// Later we will code a generalized version of

// a linked list that can store other types of data.


class Node {

public:

 int value; // the data

 Node* next; // pointer to the next node


 Node(int v = 0, Node* n = nullptr);

};


class LinkedList {

private:

 Node* headPtr;

 int length;




public:

 LinkedList();    // constructor

 LinkedList(LinkedList& other);

 ~LinkedList();   // destructor




 void insertFirst(int v);

 void removeFirst();

 int getFirst() const;

 void printList() const;




 int getLength() const;

 /*

 Node* getNode(int index) {

 if (index < 0 || index >= length)

 return nullptr;

 Node* n = headPtr;

 while (n->next != nullptr)

 n = n->next;

 return n;

 }




 int& operator[] (int index) {

 Node* n = getNode(index); // Save result. DO NOT call function twice.

 if (n == nullptr)

 throw std::logic_error("Index out of bounds");

 return n->value;

 }

 */






  void removeAValue(int v); // find and remove the first occurrence of v

  void removeAtIndex(int index);  // remove the value at the given index

  void insertAtIndex(int v, int index); // insert value v at the given index

  int count(int v) const; // count number of occurrences of v

 

};



#endif