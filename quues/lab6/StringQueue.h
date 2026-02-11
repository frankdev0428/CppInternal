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
