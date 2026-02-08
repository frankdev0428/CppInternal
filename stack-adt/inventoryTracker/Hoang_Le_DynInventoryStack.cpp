#include <iostream>
#include "Hoang_Le_DynInventoryStack.h"
using namespace std;

      //constructor 
      DynInventoryStack::DynInventoryStack(){
        top = nullptr;
      }
      // Destructor
      DynInventoryStack::~DynInventoryStack(){
        StackNode* nodePtr = nullptr;
        StackNode* nextNode = nullptr;

        nodePtr = top;

        while(nodePtr != nullptr) {
           nextNode = nodePtr->next;
           delete nodePtr;
           nodePtr = nextNode;
        }
      };
      // Stack operations
      void DynInventoryStack::push(const Inventory& item){
       //Allocate new node 
    StackNode* newNode = new StackNode;
       //copy inventory into node
    newNode->item = item;
      // link the node 
    newNode->next = top;
       //Move the top
      top = newNode;
      };

      bool DynInventoryStack::pop(Inventory& item){
        // if false do nothing
        if (!isEmpty())
          return false;
        //temp pointer to store the top node
       StackNode* temp = top;

       item = top->item;
       top = top->next;
       delete temp;
       return true;
      };

      bool DynInventoryStack::isEmpty() const{
        // true if empty fasle otherwise
         return top == nullptr;
      };