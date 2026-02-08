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
}

void LinkedList::interleave(const LinkedList & other){
    Node* source = nullptr;
    Node* sourceTail = nullptr;
    bool madeCopy = false;

    if (&other == this) {
        Node* cur = headPtr;
        while (cur != nullptr) {
            Node* n = new Node(cur->value, nullptr);
            if (source == nullptr) source = n;
            else sourceTail->next = n;
            sourceTail = n;
            cur = cur->next;
        }
        madeCopy = true;
    } else {
        source = other.headPtr;
    }

    if (source == nullptr) {
        return;
    }

    if (headPtr == nullptr) {
        Node* src = source;
        Node* tail = nullptr;
        while (src != nullptr) {
            Node* n = new Node(src->value, nullptr);
            if (headPtr == nullptr) {
                headPtr = n;
                tail = n;
            } else {
                tail->next = n;
                tail = n;
            }
            length++;
            src = src->next;
        }
        if (madeCopy) {
            Node* cur = source;
            while (cur != nullptr) {
                Node* toDelete = cur;
                cur = cur->next;
                delete toDelete;
            }
        }
        return;
    }

    Node* cur = headPtr;
    Node* srcPtr = source;
    while (cur != nullptr && srcPtr != nullptr) {
        Node* nextCur = cur->next;
        Node* newNode = new Node(srcPtr->value, nextCur);
        cur->next = newNode;
        length++;
        srcPtr = srcPtr->next;
        cur = nextCur;
    }
    if (srcPtr != nullptr) {
        Node* tail = headPtr;
        while (tail->next != nullptr) tail = tail->next;
        while (srcPtr != nullptr) {
            tail->next = new Node(srcPtr->value, nullptr);
            tail = tail->next;
            length++;
            srcPtr = srcPtr->next;
        }
    }

    if (madeCopy) {
        Node* cur2 = source;
        while (cur2 != nullptr) {
            Node* toDelete = cur2;
            cur2 = cur2->next;
            delete toDelete;
        }
    }
}