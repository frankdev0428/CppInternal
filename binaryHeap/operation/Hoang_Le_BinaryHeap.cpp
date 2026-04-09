// Implementation file for the BinaryHeap class
#include <iostream>
#include "Hoang_Le_BinaryHeap.h"

// Percolate Up to maintain heap-order property
void BinaryHeap::percolateUp(int index){
    // i should not be root
    // adjust stop condition index > 1 -> index > 0
    while (index > 0 && heap[index] < heap[parent(index)]){
        std::swap(heap[index], heap[parent(index)]);
                
        // Update current index
        index = parent(index);
    }
}

// Percolate Down to maintain heap-order property
void BinaryHeap::percolateDown(int index){
    int minIndex = index;

    int left = leftChild(index);
    if (left < currentSize && heap[left] < heap[minIndex])
        minIndex = left;
    int right = rightChild(index);
    if (right < currentSize && heap[right] < heap[minIndex])
        minIndex = right;

    // Swap if there is still a smaller child
    if (index != minIndex){
        std::swap(heap[index], heap[minIndex]);
        // Recursive call, minIndex is the new i
        percolateDown(minIndex);
    }
}

// Insert member function
void BinaryHeap::insert(int element){
    // Add element as a new leaf at the end of vector
    heap.push_back(element);

    currentSize++;
    
    // Percolate up
    percolateUp(currentSize - 1);
}

// deleteMin member function
void BinaryHeap::deleteMin(int& element){

    if (isEmpty()){
        std::cout << "The heap is empty.\n";
    }
    else{
        // The root is at index 0
        element = heap[0];

        // Swap root with the last leaf in the vector
        heap[0] = heap[--currentSize];
        // Remove the last element
        heap.pop_back();

        // Percolate down
        percolateDown(0);
    }
}

// Display all elements in the binary heap
void BinaryHeap::display(){
    for (int i = 0; i < heap.size(); i++){
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

