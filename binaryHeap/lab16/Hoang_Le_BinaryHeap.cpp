// Implementation file for the BinaryHeap class
#include <iostream>
#include "Hoang_Le_BinaryHeap.h"

// Percolate Up to maintain heap-order property
void BinaryHeap::percolateUp(int index){
    // If i is root, don't swap
    
    while (index > 1 && heap[index] < heap[parent(index)]){
        std::swap(heap[index], heap[parent(index)]);

        // Update current index
        index = parent(index);
    }
}

// Percolate Down to maintain heap-order property
void BinaryHeap::percolateDown(int index){
    int minIndex = index;

    int left = leftChild(index);
    if (left <= currentSize && heap[left] < heap[minIndex])
        minIndex = left;
    int right = rightChild(index);
    if (right <= currentSize && heap[right] < heap[minIndex])
        minIndex = right;

    // Swap if there is still a smaller child
    if (index != minIndex){
        std::swap(heap[index], heap[minIndex]);
        // Recursive call, minIndex is the new i
        percolateDown(minIndex);
    }
}
// pass number 4 to the function parcolateDown -- what happen here 
    // first declare a new variable minIndex set it to 4;
    // declare a left var  set it  to the value return by leftChildFunction() => return 2*4 = 8
    //  minIndex = 4 --- left = 8
     // 


// Insert member function
void BinaryHeap::insert(int element){
    // Add element as a new leaf at the end of vector
    heap.push_back(element);

    currentSize++;

    // Percolate up
    percolateUp(currentSize);
}

// deleteMin member function
void BinaryHeap::deleteMin(int& element){

    if (isEmpty()){
        std::cout << "The heap is empty.\n";
    }
    else{
        // The root is at index 1
        element = heap[1];

        // Swap root with the last leaf in the vector
        heap[1] = heap[currentSize--];
        // Remove the last element
        heap.pop_back();

        // Percolate down
        percolateDown(1);
    }
}

// Display all elements in the binary heap
void BinaryHeap::display(){
    for (int i = 1; i < (int)heap.size(); i++){
        std::cout << heap[i] << " ";
    }
    std::cout << std::endl;
}

// decreaseKey member function
void BinaryHeap::decreaseKey(int position, int amount){
    heap[position] -= amount;

    percolateUp(position);
}

// increaseKey member function
void BinaryHeap::increaseKey(int position, int amount){
    heap[position] += amount;

    percolateDown(position);
}

// remove member function (assuming all keys are positive)
void BinaryHeap::remove(int position){

    // Call decreaseKey to set its key to be zero.
    // It will move this element to the root.
    decreaseKey(position, heap[position]);

    // Call deleteMin to remove that element
    int temp;
    deleteMin(temp);
}

// buildHeap member function
void BinaryHeap::buildHeap(){
    for (int i = currentSize / 2; i > 0; i--)
        percolateDown(i);
}

// if current size 9/2  = 4 integer
// pass i = 4  to the loop 
// interate i = 4 , call percolateDown(4);
  // => 



// A constructor copying content from an existing vector
BinaryHeap::BinaryHeap(const std::vector<int>& items){
    currentSize = items.size();
    // The actual heap content starts at index 1
    // Put a dummy value at index 0
    heap.push_back(-1);

    // Copy elements from items into the heap vector
    for (int i = 0; i < (int)items.size(); i++){
        heap.push_back(items[i]);
    }

    // Build the whole heap at once
    buildHeap();
}

// getKthLargest: returns the kth largest element in the heap.
// Strategy (without converting to max-heap):
//   Step 1 - Work on a copy so the original heap is not modified.
//   Step 2 - A min-heap gives the smallest element at the root.
//             If we call deleteMin (n - k) times we peel away the
//             (n - k) smallest values, leaving exactly k elements.
//   Step 3 - At that point the root is the minimum of the remaining
//             k elements, which is exactly the kth largest overall.
//   Step 4 - One final deleteMin extracts that value and returns it.
int BinaryHeap::getKthLargest(int k){
    // Step 1: make a working copy so the original heap stays intact
    BinaryHeap copy(*this);   // uses the compiler-generated copy constructor

    int discarded;

    // Step 2: remove the (n - k) smallest elements from the copy
    int removals = copy.getCurrentSize() - k;
    for (int i = 0; i < removals; i++){
        copy.deleteMin(discarded);
    }

    // Step 3 & 4: the root is now the kth largest — extract and return it
    int kthLargest;
    copy.deleteMin(kthLargest);
    return kthLargest;
}






// ----------------///

// Helper to return the index of parent
       
        // Percolate Up
        void percolateUp(int) {

        };

        // Percolate Down
        void percolateDown(int){

        };

    
        // Constructor
        BinaryHeap(){
            currentSize = 0;
            // The actual heap content starts at index 1
            // Put a dummy value at index 0
            heap.push_back(-1);
        }

        // A constructor copying content from an existing vector
        BinaryHeap(const std::vector<int>&){

        };

        
        // Binary heap operations
        void insert(int){

        };
        void deleteMin(int&){

        };

        // Build the whole heap
        void buildHeap(){

        };

        // Display all items in the binary heap
        void display(){

        };

        // Operations that can be done if positions
        // of elements are known (when some other
        // data structure is used).
        void decreaseKey(int, int){

        };

        void increaseKey(int, int){

        };
        void remove(int){

        };

        // Returns the kth largest element in the heap.
        // k=1 means the largest, k=2 the second largest, etc.
        int getKthLargest(int k){
            
        };


/// insert 


// deleteMin 

// increaseKey
//decreaseKey 

//buildHeap
// remove