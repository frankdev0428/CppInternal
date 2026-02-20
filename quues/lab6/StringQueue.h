// Specification file for the StringQueue class
#ifndef STRINGQUEUE_H
#define STRINGQUEUE_H

#include <string>

class StringQueue{
    private:
        std::string* queueArray;    // Points to the queue array
        int queueSize;              // The queue size
        int front;                  // Subscript of the queue front
        int rear;                   // Subscript of the queue rear
        int numItems;               // Number of items in the queue
 
    public:
        // Constructor
        StringQueue(int);

        // Copy constructor
        StringQueue(const StringQueue&);

        // Destructor
        ~StringQueue();

        // Queue operations
        void enqueue(const std::string&);
        void dequeue(std::string&);
        bool isEmpty() const;
        bool isFull() const;
        void clear();
};

#endif



#ifndef STRINGQUEUE_H
#define STRINGQUEUE_H

class StringQueue {
    private: 
    int* queueArray;
    // queue size
    int queueSize;
    // front 
    int front;
    // rear
    int rear;
    // number item in the queue 
    int numItems
    public: 
    // construct
     StringQueue(int);
     // copy constructor
     StringQueue( const StringQueue& )
    // destructor
     ~StringQueue()
    // enqueue
     Enqueue(const int);
    //dequeue
     Dequeue(int);
    //isEmpty
     isEmpty() const;
    // clear
     Clear();
    //isFull
    isFull() const;
}