/*
 * Hoang_Le_lab17.cpp
 *
 * Lab 17 – Four Sorting Algorithms with Comparison Counting
 *
 * Each of the four sorting algorithms (Bubble, Selection, Insertion, Heap)
 * has been modified to count and return the number of element comparisons
 * it performs.  A "comparison" is counted only when two actual elements
 * stored in the vector are compared against each other (e.g. data[i] > data[j]).
 * Index-bounds checks (e.g. i < size) are NOT element comparisons and are
 * never counted.
 *
 * The main() function reads integers from "randomNumbers.txt", runs all four
 * sorts on identical copies of the data, and prints how many comparisons
 * each algorithm required.
 */

#include <iostream>
#include <fstream>   // for ifstream / file I/O
#include <vector>

// ─────────────────────────────────────────────────────────────
//  Function prototypes
// ─────────────────────────────────────────────────────────────
int  bubbleSort   (std::vector<int>&);
int  selectionSort(std::vector<int>&);
int  insertionSort(std::vector<int>&);
int  heapSort     (std::vector<int>&);
int  leftChild    (int);
int  rightChild   (int);
void percolateDown(std::vector<int>&, int, int, int&);  // int& threads the count through recursion

void displayVector(const std::vector<int>&);

// ─────────────────────────────────────────────────────────────
//  Bubble Sort  (ascending order)
//  Returns: number of element comparisons performed
//
//  How Bubble Sort works:
//    Repeatedly walk through the array and "bubble" each too-large
//    element rightward by swapping adjacent neighbours.  After every
//    complete pass the largest unsorted element has settled at the
//    end.  We stop as soon as a full pass produces no swaps, which
//    means the array is already sorted.
//
//  Comparison counting logic:
//    Every evaluation of  data[i] > data[i+1]  is one element
//    comparison, regardless of whether a swap follows.  This condition
//    is tested exactly once per inner-loop iteration, so we simply
//    increment the counter inside that loop before (or after) the
//    comparison.  Even the final "clean" pass (no swaps) still makes
//    comparisons, so those are included.
// ─────────────────────────────────────────────────────────────
int bubbleSort(std::vector<int>& data) {
    int comparisons = 0;   // will accumulate every element comparison
    bool swapped;          // tracks whether any swap occurred in a pass
    int size = data.size();

    do {
        swapped = false;

        // Each iteration compares the element at i with its right neighbour.
        // That single test  data[i] > data[i+1]  is one element comparison.
        for (int i = 0; i < size - 1; i++) {
            comparisons++;                          // count this element comparison

            if (data[i] > data[i + 1]) {           // are neighbours out of order?
                std::swap(data[i], data[i + 1]);   // yes → swap them
                swapped = true;                    // mark that a swap occurred
            }
        }
        // If no swap occurred in this pass, the array is fully sorted;
        // the do-while condition will terminate the outer loop.
    } while (swapped);

    return comparisons;
}

// ─────────────────────────────────────────────────────────────
//  Selection Sort  (ascending order)
//  Returns: number of element comparisons performed
//
//  How Selection Sort works:
//    Divide the array into a sorted prefix (left) and an unsorted
//    suffix (right).  In each pass, scan the entire unsorted suffix
//    to find its minimum value, then swap that minimum into the
//    first position of the suffix, growing the sorted prefix by one.
//
//  Comparison counting logic:
//    The only element comparison is  data[index] < minValue  inside
//    the inner loop.  It is executed once per inner-loop iteration,
//    so we increment the counter there.  The total is always
//    n*(n-1)/2, which for 100 elements equals 4 950 – a fixed cost
//    regardless of the input order because the inner loop always
//    runs to the end.
// ─────────────────────────────────────────────────────────────
int selectionSort(std::vector<int>& data) {
    int comparisons = 0;
    int size = data.size();
    int startScan, minIndex, minValue;

    // startScan marks the boundary between the sorted and unsorted regions.
    for (startScan = 0; startScan < size - 1; startScan++) {
        minIndex = startScan;           // assume first unsorted element is minimum
        minValue = data[startScan];

        // Scan the rest of the unsorted region for a smaller value.
        for (int index = startScan + 1; index < size; index++) {
            comparisons++;                      // count this element comparison

            if (data[index] < minValue) {       // found a new minimum?
                minValue = data[index];
                minIndex = index;
            }
        }

        // Place the found minimum at the start of the unsorted region.
        data[minIndex]  = data[startScan];
        data[startScan] = minValue;
    }

    return comparisons;
}

// ─────────────────────────────────────────────────────────────
//  Insertion Sort  (ascending order)
//  Returns: number of element comparisons performed
//
//  How Insertion Sort works:
//    Treat the array as a sorted hand of cards growing leftward.
//    Take the next unsorted element (currentVal) and slide it
//    leftward past every element that is larger, inserting it at
//    the correct position.
//
//  Comparison counting logic:
//    The while-loop condition is:  j > 0  &&  data[j-1] > currentVal
//    "j > 0" is an index-bounds guard – NOT an element comparison.
//    "data[j-1] > currentVal" IS an element comparison, but due to
//    C++ short-circuit evaluation it is only evaluated when j > 0.
//    So we count one comparison each time j > 0 holds and we actually
//    test data[j-1] against currentVal (whether the test is true or
//    false).  When j reaches 0, the short-circuit prevents the element
//    test, so nothing is counted for that final guard check.
// ─────────────────────────────────────────────────────────────
int insertionSort(std::vector<int>& data) {
    int comparisons = 0;
    int size = data.size();

    // Start from index 1; element at index 0 is trivially "sorted".
    for (int i = 1; i < size; i++) {
        int currentVal = data[i];   // the element being inserted
        int j = i;

        // Shift elements that are larger than currentVal one position right.
        // We only reach  data[j-1] > currentVal  when j > 0, so each
        // evaluation of that test is exactly one element comparison.
        while (j > 0 && (++comparisons, data[j - 1] > currentVal)) {
            // (++comparisons, expr) uses the comma operator:
            //   1. increments comparisons  (counts this element comparison)
            //   2. evaluates  data[j-1] > currentVal  as the while condition
            // This ensures we count the comparison before deciding to continue.
            data[j] = data[j - 1];   // shift the larger element right
            j--;
        }

        data[j] = currentVal;   // insert currentVal at its sorted position
    }

    return comparisons;
}

// ─────────────────────────────────────────────────────────────
//  Helper: index of left child in a 0-based array heap
// ─────────────────────────────────────────────────────────────
int leftChild(int i) {
    return 2 * i + 1;
}

// ─────────────────────────────────────────────────────────────
//  Helper: index of right child in a 0-based array heap
// ─────────────────────────────────────────────────────────────
int rightChild(int i) {
    return 2 * i + 2;
}

// ─────────────────────────────────────────────────────────────
//  percolateDown  – restores the max-heap property at index
//  Parameters:
//    data       – the heap stored as a vector
//    index      – root of the sub-tree to fix
//    size       – number of elements still in the heap
//    comparisons – reference counter; updated in place so the
//                  caller (heapSort) accumulates the total across
//                  every recursive call without needing a return value
//
//  How it works:
//    Compare the node at 'index' with its children.  If a child is
//    larger, swap it with the parent and recurse downward, because
//    the swap may have broken the heap property further down.
//
//  Comparison counting logic:
//    Each child that EXISTS (index < size) is compared against the
//    current largest candidate  data[minIndex].  That comparison is
//    one element comparison per existing child, so we get up to 2
//    comparisons per call (1 for left child, 1 for right child).
// ─────────────────────────────────────────────────────────────
void percolateDown(std::vector<int>& data, int index, int size, int& comparisons) {
    int maxIndex = index;   // start by assuming the current node is the largest

    int left = leftChild(index);
    if (left < size) {              // left child exists?
        comparisons++;              // count: data[left] vs data[maxIndex]
        if (data[left] > data[maxIndex])
            maxIndex = left;        // left child is larger → update candidate
    }

    int right = rightChild(index);
    if (right < size) {             // right child exists?
        comparisons++;              // count: data[right] vs data[maxIndex]
        if (data[right] > data[maxIndex])
            maxIndex = right;       // right child is largest → update candidate
    }

    // If a child was larger than the parent, swap and continue percolating.
    if (index != maxIndex) {
        std::swap(data[index], data[maxIndex]);
        percolateDown(data, maxIndex, size, comparisons);   // fix the affected sub-tree
    }
}

// ─────────────────────────────────────────────────────────────
//  Heap Sort  (ascending order)
//  Returns: number of element comparisons performed
//
//  How Heap Sort works:
//    Phase 1 – Build Max Heap:
//      Rearrange the array into a max-heap (parent ≥ children)
//      by calling percolateDown on every non-leaf node, bottom-up.
//      After this phase, data[0] is the largest element.
//    Phase 2 – Repeated deleteMax:
//      Swap the heap root (maximum) with the last element of the
//      heap, shrink the heap by one, then percolate the new root
//      down to restore the heap property.  Repeat until the heap
//      has one element.  The array is now sorted ascending.
//
//  Comparison counting logic:
//    All comparisons happen inside percolateDown.  We pass the
//    counter by reference so every recursive call accumulates into
//    the same variable without needing a wrapper or extra storage.
// ─────────────────────────────────────────────────────────────
int heapSort(std::vector<int>& data) {
    int comparisons = 0;
    int size = data.size();

    // ── Phase 1: Build Max Heap ──────────────────────────────
    // Start from the last non-leaf (index size/2 - 1) and work
    // upward.  Leaves are trivially valid heaps, so we skip them.
    for (int i = size / 2 - 1; i >= 0; i--) {
        percolateDown(data, i, size, comparisons);
    }

    // ── Phase 2: Repeatedly extract the maximum ──────────────
    // Swap the current maximum (data[0]) with the last element,
    // logically shrink the heap (j decreases), then restore the
    // heap property so data[0] becomes the next maximum.
    for (int j = size - 1; j > 0; j--) {
        std::swap(data[0], data[j]);            // move current max to its final position
        percolateDown(data, 0, j, comparisons); // restore heap over the reduced range
    }

    return comparisons;
}

// ─────────────────────────────────────────────────────────────
//  displayVector  – prints every element on one line
// ─────────────────────────────────────────────────────────────
void displayVector(const std::vector<int>& data) {
    for (int i = 0; i < (int)data.size(); i++)
        std::cout << data[i] << " ";
    std::cout << std::endl;
}

// ─────────────────────────────────────────────────────────────
//  main
//  1. Open "randomNumbers.txt" and read every integer into a vector.
//  2. Copy the original (unsorted) data for each algorithm so that
//     every sort starts from the same input.
//  3. Run all four sorts and collect their comparison counts.
//  4. Print the results.
// ─────────────────────────────────────────────────────────────
int main() {
    // ── Step 1: Open the file ────────────────────────────────
    std::ifstream inFile("randomNumbers.txt");

    // Always verify that the file opened successfully before reading.
    if (!inFile) {
        std::cerr << "Error: could not open randomNumbers.txt\n";
        return 1;   // non-zero exit signals failure to the OS
    }

    // ── Step 2: Read all integers from the file ──────────────
    std::vector<int> original;   // stores the unsorted numbers exactly as read
    int value;
    while (inFile >> value) {    // read one integer at a time until EOF or error
        original.push_back(value);
    }

    inFile.close();   // close the file as soon as we are done with it

    // ── Step 3: Sort with each algorithm ─────────────────────
    // We copy 'original' into a fresh vector before each sort so
    // that every algorithm operates on the same unsorted input.

    std::vector<int> data1 = original;
    int bubbleCmp    = bubbleSort   (data1);

    std::vector<int> data2 = original;
    int selectionCmp = selectionSort(data2);

    std::vector<int> data3 = original;
    int insertionCmp = insertionSort(data3);

    std::vector<int> data4 = original;
    int heapCmp      = heapSort     (data4);

    // ── Step 4: Display results ───────────────────────────────
    std::cout << "To sort the data from randomNumbers.txt...\n\n";
    std::cout << "Bubble Sort made "    << bubbleCmp    << " comparisons.\n";
    std::cout << "Selection Sort made " << selectionCmp << " comparisons.\n";
    std::cout << "Insertion Sort made " << insertionCmp << " comparisons.\n";
    std::cout << "Heap Sort made "      << heapCmp      << " comparisons.\n";

    return 0;
}
