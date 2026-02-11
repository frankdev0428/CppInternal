// Implementation file for the StringQueue class
#include <iostream>
#include "StringQueue.h"

//***************************************************************
// This constructor creates an empty queue of a specified size. *
//***************************************************************
StringQueue::StringQueue(int s){
    queueArray = new std::string[s];
    queueSize = s;
    front = -1;
    rear = -1;
    numItems = 0;
}

//***************************************************************
// Copy constructor                                             *
//***************************************************************
StringQueue::StringQueue(const StringQueue& obj){
    // Allocate the queue array.
    queueArray = new std::string[obj.queueSize];

    // Copy the other object's attributes.
    queueSize = obj.queueSize;
    front = obj.front;
    rear = obj.rear;
    numItems = obj.numItems;

    // Copy the other object's queue array.
    for (int count = 0; count < obj.queueSize; count++)
        queueArray[count] = obj.queueArray[count];
}

//************************************************************
// Destructor                                                *
//************************************************************
StringQueue::~StringQueue(){
    delete [] queueArray;
}

//************************************************************
// Function enqueue inserts a value at the rear of the queue *
//************************************************************
void StringQueue::enqueue(const std::string& str){
    if (isFull())
        std::cout << "The queue is full.\n";
    else{
        // Calculate the new rear position
        rear = (rear + 1) % queueSize;
        // Insert new item
        queueArray[rear] = str;
        // Update item count
        numItems++;
    }
}

//***************************************************************
// Function dequeue removes the value at the front of the queue *
// and copies it into str.                                      *
//***************************************************************
void StringQueue::dequeue(std::string& str){
    if (isEmpty())
        std::cout << "The queue is empty.\n";
    else{
        // Move front
        front = (front + 1) % queueSize;
        // Retrieve the front item
        str = queueArray[front];
        // Update item count
        numItems--;
    }
}

//***************************************************************
// isEmpty returns true if the queue is empty, otherwise false. *
//***************************************************************
bool StringQueue::isEmpty() const{
    bool status;

    if(numItems)
        status = false;
    else
        status = true;

    return status;
}

//*************************************************************
// isFull returns true if the queue is full, otherwise false. *
//*************************************************************
bool StringQueue::isFull() const{
    bool status;

    if(numItems < queueSize)
        status = false;
    else
        status = true;

    return status;
}

//*****************************************************************
// clear sets the front and rear indices, and sets numItems to 0. *
//*****************************************************************
void StringQueue::clear(){
    front = queueSize - 1;      
    rear = queueSize - 1;
    numItems = 0;
}
