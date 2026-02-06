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
 //this function job is to add a new node into an existing list.

 void insertFirst(int v);

 //this function job is to remove a node from a existing list
 void removeFirst();

 // this function is to get a value of the first node on the list.
 int getFirst() const;

 // this function job is output the value of the whole list to the terminal 
 void printList() const;

 // this function job is return the length of current list 
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
// this function accept one parameter value and remove the node link with that value from the list
  void removeAValue(int v); // find and remove the first occurrence of v
// this function take on one parameter index and remove the node at those specific value.
  void removeAtIndex(int index);  // remove the value at the given index
// this is add a new Node at those index;
  void insertAtIndex(int v, int index); // insert value v at the given index

// this function actually loop thru array 
  int count(int v) const; // count number of occurrences of v
  Node* sortHelper(Node* first);
};

#endif