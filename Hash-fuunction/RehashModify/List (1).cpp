// Implementation file for the NumberList class
#include <iostream>
#include <string>
#include "List.h"

// insertNode member function:
void List::insertNode(int key, std::string value){

    // Allocate a new node and store key and value there.
    ListNode* newNode = new ListNode;
    newNode->key = key;
    newNode->value = value;
    newNode->next = nullptr;

    // Insert the newNode at the beginning of the list
    newNode->next = head;
    head = newNode;
}

// deleteNode member function
// It returns true if deletion is successful,
// false otherwise.
bool List::deleteNode(int key){
    ListNode* nodePtr;          // To traverse the list
    ListNode* previousNode;     // To point to the previous node 

    // If the list is empty, do nothing.
    if (!head){
        return false;
    }
    // Determine if the first node is the one.
    if (head->key == key){
        nodePtr = head->next;
        delete head;
        head = nodePtr;
        return true;
    }
    else{
        // Initialize nodePtr to head of list
        nodePtr = head;
        // Skip all nodes whose key member is 
        // not equal to key.
        while (nodePtr != nullptr && nodePtr->key != key){
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        // If nodePtr is not at the end of the list,
        // link the previous node to the node after
        // nodePtr, then delete nodePtr.
        if (nodePtr){
            previousNode->next = nodePtr->next;
            delete nodePtr;
            return true;
        }
    }
    return false;
}

// search member function
// It returns the item's string value if found.
// Returns an empty string otherwise.
std::string List::search(int key){
    ListNode* nodePtr = head;

    while (nodePtr){
        // Item with the matching key found
        if (nodePtr->key == key){
            return nodePtr->value;
        }
        nodePtr = nodePtr->next;
    }

    // Item not found
    return "";
}

// The destructor
List::~List(){
    ListNode* nodePtr;      // To traverse the list
    ListNode* nextNode;     // To point to the next node

    // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr is not at the end of the list...
    while (nodePtr != nullptr){
        // Save a pointer to the next node.
        nextNode = nodePtr->next;

        // Delete the current node.
        delete nodePtr;

        // Position nodePtr at the next node.
        nodePtr = nextNode;
    }
}

int List::getSize() const {
    int count = 0;
    ListNode* nodePtr = head;

    while(nodePtr){
        count++;
        nodePtr = nodeptr->next;
    }
    return count;
}
