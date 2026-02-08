#ifndef DYNINVENTORY_H
#define DYNINVENTORY_H
#include "Hoang_Le_Inventory.h"


class DynInventoryStack {
 private:
    struct StackNode{
        Inventory item;
        StackNode* next;
    };
    StackNode* top;
    public: 
      //constructor
      DynInventoryStack();
      // Destructor
      ~DynInventoryStack();
      // Stack operations
      void push(const Inventory& item );
      bool pop(Inventory& item);
      bool isEmpty() const;

};

#endif