#include <iostream>
#include <vector>

// Function prototypes
// Bubble Sort
void bubbleSort(std::vector<int>&);
// Selection Sort
void selectionSort(std::vector<int>&);
// Insertion Sort
void insertionSort(std::vector<int>&);
// Heap Sort
void heapSort(std::vector<int>&);
int leftChild(int);
int rightChild(int);
void percolateDown(std::vector<int>&, int, int);

void displayVector(const std::vector<int>&);

// Bubble Sort function (ascending order)
void bubbleSort(std::vector<int>& data){
    bool swap;
    int temp;
    int size = data.size();
    do{
        swap = false;
        for (int i = 0; i < (size - 1); i++){
            if (data[i] > data[i + 1]){
                std::swap(data[i], data[i + 1]);
                swap = true;
            }
        }
    } while (swap);
}

// Selection Sort function (ascending order)
void selectionSort(std::vector<int>& data){
    int startScan, minIndex, minValue;
    int size = data.size();

    for (startScan = 0; startScan < (size - 1); startScan++){
        minIndex = startScan;
        minValue = data[startScan];
        for (int index = startScan + 1; index < size; index++){
            if (data[index] < minValue){
                minValue = data[index];
                minIndex = index;
            }
        }
        data[minIndex] = data[startScan];
        data[startScan] = minValue;
    }
}

// Insertion Sort function (ascending order)
void insertionSort(std::vector<int>& data){
    int size = data.size();

    // Starting at index 1
    for (int i = 1; i < size; i++){
        int currentVal = data[i];
        int j = i;

        // Move elements before currentVal that are
        // greater than currentVal, to one position
        // after their current position
        while(j > 0 && data[j - 1] > currentVal){
            data[j] = data[j - 1];
            j--;
        }
        data[j] = currentVal;
    }
}

// Helper to return the index of left child
int leftChild(int i){
    return 2 * i + 1;
}

// Helper to return the index of right child
int rightChild(int i){
    return 2 * i + 2;
}

// Percolate Down to maintain heap-order property (Max Heap)
void percolateDown(std::vector<int>& data, int index, int size){
    int minIndex = index;

    int left = leftChild(index);
    if (left < size && data[left] > data[minIndex])
        minIndex = left;
    int right = rightChild(index);
    if (right < size && data[right] > data[minIndex])
        minIndex = right;

    // Swap if there is still a smaller child
    if (index != minIndex){
        std::swap(data[index], data[minIndex]);
        // Recursive call, minIndex is the new i
        percolateDown(data, minIndex, size);
    }
}

// Heap Sort function (ascending order)
void heapSort(std::vector<int>& data){
    int size = data.size();

    // buildHeap
    for (int i = size/2 - 1; i >= 0; i--){
        percolateDown(data, i, size);
    }
    for (int j = size - 1; j > 0; j--){
        // deleteMax
        std::swap(data[0], data[j]);
        percolateDown(data, 0, j);
    }
}

// Function to display the content of vector
void displayVector(const std::vector<int>& data){
    for (int i = 0; i < data.size(); i++)
        std::cout << data[i] << " ";
    std::cout << std::endl;
}
