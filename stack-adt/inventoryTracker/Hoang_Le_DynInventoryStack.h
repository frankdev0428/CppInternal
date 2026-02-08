#ifndef DYNINVENTORY_H
#define DYNINVENTORY_H

class DynInventoryStack {
 private:
    struct StackNode{
        int value;
        StackNode* next;
    };
    StackNode* top;
    public: 
      //constructor
      DynInventoryStack(){
        top = nullptr;
      }
      // Destructor
      ~DynInventoryStack();
      // Stack operations
      void push(int);
      void pop(int&);
      bool isEmplty();




}

#endif