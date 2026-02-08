#include <iostream>
#include "DynInventoryStack.h"
using namespace std;

 
      // Destructor
      DynInventoryStack::~DynInventoryStack(){
        StackNode* nodePtr = nullptr;
        StackNode* nextNode = nullptr;

        nodePtr = top;

        while(nodePtr != nullptr) {
           nexNode = nodePtr->next;
           delete nodePtr;
           nodePtr = nextNode;
        }
      };
      // Stack operations
      void DynInventoryStack::push(int);
      void DynInventoryStack::pop(int&);
      bool DynInventoryStack::isEmplty();