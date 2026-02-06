#ifndef INTSTACK_H
#define INTSTACK_H

class IntStack {
  private:
    int *stackArray;  //point to stack array
    int stackSize;    // The stack size
    int top; //Indicates the top of the stack
  public:
    // constructor
     IntStack(int);
    // copy constructor
    IntStack(const IntStack&);
    // destructor
    ~IntStack();
    //Stack operations 
    void push(int);
    void pop(int&);
    bool isFull() const;
    bool isEmplty() const;

};

#endif
