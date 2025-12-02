#include "LinkedList.h"
#include <stdexcept>
#include <iostream>
using namespace std;
Node::Node(int v, Node* n) {
    value = v;
    next = n;
}

LinkedList::LinkedList() {
    length = 0;
    headPtr = nullptr;
}

LinkedList::LinkedList(LinkedList& other) {
    headPtr = nullptr;
    length = 0;
    Node* cur = other.headPtr;
    while (cur != nullptr) {
        insertAtIndex(cur->value, length);
        cur = cur->next;
    }
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

void LinkedList::removeAValue(int v) {
    if (headPtr == nullptr)
        return;
    if (headPtr->value == v) {
        Node* toDelete = headPtr;
        headPtr = headPtr->next;
        delete toDelete;
        length--;
        return;
    }
    Node* pre = headPtr;
    while (pre->next != nullptr && pre->next->value != v) {
        pre = pre->next;
    }
    if (pre->next != nullptr) {
        Node* toDelete = pre->next;
        pre->next = toDelete->next;
        delete toDelete;
        length--;
    } 
}



void LinkedList::removeAtIndex(int index) {
    if (index < 0 || index >= length)
        throw std::out_of_range("Index out of range");

    if (index == 0) {
        Node* toDelete = headPtr;
        headPtr = headPtr->next;
        delete toDelete;
    } else {
        Node* prev = headPtr;
        for (int i = 0; i < index - 1; ++i) {
            prev = prev->next;
        }
        Node* toDelete = prev->next;
        prev->next = toDelete->next;
        delete toDelete;
    }
    length--;
}


void LinkedList::insertAtIndex(int v, int index) {
    if (index < 0 || index > length)
        throw std::out_of_range("Index out of range");

    if (index == 0) {
        headPtr = new Node(v, headPtr);
    } else {
        Node* prev = headPtr;
        for (int i = 0; i < index - 1; ++i) {
            prev = prev->next;
        }
        prev->next = new Node(v, prev->next);
    }
    length++;
}

int LinkedList::count(int v) const {
    int count = 0;
    Node* current = headPtr;
    while (current != nullptr) {
        if (current->value == v)
            ++count;
        current = current->next;
    }
    return count;
}

Node* LinkedList::sortHelper(Node* first) {
    //validate expression 
    if (first == nullptr || first->next == nullptr)
        return first;

     // split list into two halves using slow/fast pointers
    Node* slow = first;
    Node* fast = first->next;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* mid = slow->next;
    slow->next = nullptr;

    // sort each half recursively
    Node* left = sortHelper(first);
    Node* right = sortHelper(mid);

      // merge the two sorted halves
    Node dummy(0, nullptr);
    Node* tail = &dummy;
    while (left != nullptr && right != nullptr) {
        if (left->value <= right->value) {
          tail->next = left;
          left = left->next;
        } else {
            tail->next = right;
            right = right->next;

        }
         tail = tail->next;
    }
    
    tail->next = (left != nullptr) ? left : right;

    return dummy.next;
}