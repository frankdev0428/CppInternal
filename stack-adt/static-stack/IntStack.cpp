#include <iostream>
#include "IntStack.h"
using namespace std;


  IntStack::IntStack(int size){
    // allocate int array on the heap using  "new" notation
    // the new int array will store in the variable stackArray 
    stackArray = new int[size];
     stackSize = size;
     top = -1;
 };
    // copy constructor
    IntStack::IntStack(const IntStack&){
      // create the stack array
      
    };
    // destructor
    IntStack::~IntStack(){

    };
    //Stack operations 
    void IntStack::push(int){

    };
    void IntStack::pop(int&){

    };
    bool IntStack::isFull() const{

    };
    bool IntStack::isEmpty() const{

    };