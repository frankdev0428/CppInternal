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
            return i / 2;
        }
        // Helper to return the index of left child
        int leftChild(int i){
            return 2 * i;
        }
        // Helper to return the index of right child
        int rightChild(int i){
            return 2 * i + 1;
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
            currentSize = 0;
            // The actual heap content starts at index 1
            // Put a dummy value at index 0
            heap.push_back(-1);
        }

        // A constructor copying content from an existing vector
        BinaryHeap(const std::vector<int>&);

        // Getter
        // the getter will return the index of the heapArray
        int getCurrentSize() const{
            return currentSize;
        }

        // Binary heap operations
        void insert(int);
        void deleteMin(int&);

        // Build the whole heap
        void buildHeap();

        // Display all items in the binary heap
        void display();

        // Operations that can be done if positions
        // of elements are known (when some other
        // data structure is used).
        void decreaseKey(int, int);
        void increaseKey(int, int);
        void remove(int);

        // Returns the kth largest element in the heap.
        // k=1 means the largest, k=2 the second largest, etc.
        int getKthLargest(int k);
};

#endif



