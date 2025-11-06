#include <iostream>
#include "NumberList.h"
using std::cout;
using std::cin;
using std::endl;
using namespace std;
  
  NumberList(){
    
  };
    //destructor
    ~NumberList(){

    };
    
    // Linklist operations
    void NumberList::appendNode(double num){
      ListNode *newNode; // To point to a new node
      ListNode *nodePtr; // To move to through the list

      //Allocate a new node and store num there;
      newNode = new ListNode;
      newNode->value = num;
      newNode->next = nullptr;

      // if there are no node in the list
      // make newNode the frst node 
      if (!head)
        head = newNode;
      else {
        //initialize nodePtr to head of the list.
        nodePtr = head;
        // Find the last node in the list.
        while(nodePtr->next){
            nodePtr = nodePtr->next;
            //insert newNode as the last node.
            nodePtr->next = newNode;
        }
      }

    };
    void NumberList::insertNode(double){

    };
    void NumberList::deleteNode(double){

    };
    void NumberList::displayList() const {
       
    };