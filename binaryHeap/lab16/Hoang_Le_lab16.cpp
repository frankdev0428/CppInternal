// Main program for Lab 16
// Reads integers from data.txt, prompts the user for k,
// then reports the kth largest number using BinaryHeap.
#include <iostream>
#include <fstream>
#include <vector>
#include "Hoang_Le_BinaryHeap.h"

int main(){
    // Step 1: open the data file and verify it opened successfully
    std::ifstream inFile("data.txt");
    if (!inFile){
        std::cerr << "Error: could not open data.txt\n";
        return 1;
    }

    // Step 2: read all integers from the file into a vector
    std::vector<int> numbers;
    int value;
    while (inFile >> value){
        numbers.push_back(value);
    }

    // Step 3: close the file now that all data has been read
    inFile.close();

    // Step 4: build the min-heap using the copy constructor
    //         (passes the entire vector at once; internally calls buildHeap)
    BinaryHeap minHeap(numbers);

    // Step 5: prompt the user for k
    int k;
    std::cout << "Enter the value for integer k (to find the kth largest number. "
              << "E.g., k=1 for largest, k=2 for second largest): ";
    std::cin >> k;

    // Step 6: call getKthLargest and display the result
    int result = minHeap.getKthLargest(k);
    std::cout << "The " << k << "th largest number is: " << result << std::endl;

    return 0;
}

