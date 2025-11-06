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

 while (headPtr != nullptr)     {

 Node* toDelete = headPtr;

 headPtr = headPtr->next;

 delete toDelete;

 }

}







void LinkedList::insertFirst(int v) {

 Node* toInsert = new Node(v, headPtr);

    headPtr = toInsert;




 /*

 headPtr = new Node(v, headPtr);

 */

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
void LinkedList::reverse(){
    if (headPtr == nullptr || headPtr->next == nullptr) return;
    Node* prev = nullptr;
    Node* current = headPtr;
    while (current != nullptr) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    headPtr = prev;
};