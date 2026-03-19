// Specification file for the BinaryHeap class
#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <vector>
#include <string>

class BinaryHeap{
    private:
        int currentSize;
        std::vector<int> heap;

        // Helper to return the index of parent
        int parent(int i){
            // convert the equation to i/2 -> (i - 1)/2
            return (i - 1) / 2;
        }
        // Helper to return the index of left child
        int leftChild(int i){
            // convert the equation from 2*i -> 2*i + 1
            return 2 * i + 1;
        }
        // Helper to return the index of right child
        int rightChild(int i){
            // 2*i + 1 -> 2* i + 2
            return 2 * i + 2;
        }

        bool isEmpty() const{
            return currentSize == 0;
        }

        // Percolate Up
        void percolateUp(int);

        // Percolate Down
        void percolateDown(int);

    public:
        // Constructor
        BinaryHeap(){
            // removed dummy -1 at inex 0
            currentSize = 0;
        }

        // Getter
        int getCurrentSize() const{
            return currentSize;
        }

        // Binary heap operations
        void insert(int);
        void deleteMin(int&);

        // Display all items in the binary heap
        void display();

        // Operations that can be done if positions
        // of elements are known (when some other
        // data structure is used).
        void decreaseKey(int, int);
        void increaseKey(int, int);
        void remove(int);

};

#endif


