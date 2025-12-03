// The function receives an array of int called heap, and the array's size as parameters.
// The function will return the index of the first available location to store a new "node", similar to calling new when allocating an actual Node object for linked lists.

// The array heap simulates heap storage so that various elements are effectively nodes in a linked list.
// The contents of each element is the "next pointer" (really an index) of the given node, or 0 to indicate nullptr.
// To indicate that an element of heap is available, its value is -1.

// To make the code simple, our nodes contain no data field; they only store the next pointer.

// The function newNode must loop through the heap array, starting at index 1 (not index 0), and find the first element whose value is -1.
// Once found, that element’s value should be changed to 0, and the index returned.

// If no element of heap has value –1, the function should return 0, indicating that the heap is full.

// This exercise mainly gives you practice with using an array as simulated heap storage.
int newNode(int heap[], int size)
{
    // Loop from index 1 to size-1
    for (int i = 1; i < size; i++)
    {
        if (heap[i] == -1)        // Found free spot
        {
            heap[i] = 0;          // Mark it as allocated
            return i;             // Return index
        }
    }

    // If we reach here, heap is full
    return 0;
}


// Write the definition of a function named getLength. The function receives an array of int called heap and an int called headPtr as parameters.

// The function will return the length of a simulated linked list whose first "node" is stored at index headPtr.

// The array simulates heap storage so that each element acts like the “next pointer” of a node in a linked list.
// There is no value field — only the next pointer.

// To get the length of the list, start at headPtr and follow the next pointers until you reach a node whose next pointer has value 0, which is equivalent to a null pointer.

// Example:

// Given:

// heap = [-1, 6, -1, -1, 1, 6, 9, -1, 10, 8, 0, -1, -1, -1]
// headPtr = 4


// The list corresponds to “nodes” at indexes:

// 4 → 1 → 6 → 9 → 8 → 10 → 0


// So the function should return 6.


int getLength(int heap[], int headPtr)
{
    int count = 1;                
    int current = heap[headPtr];  

  
    while (current != headPtr)
    {
        count++;
        current = heap[current];
    }

    return count;
}

// Write the definition of a function named getLength. The function receives an array of int called heap and an int called headPtr as parameters.

// This time the list is a circular linked list, meaning the last node’s next pointer points back to the first node (headPtr) instead of being null.

// You may assume the function is only called on a non-empty list.

// To get the length of the list, traverse starting at headPtr and continue following next pointers until you reach a node whose next pointer is equal to headPtr.

// Example:

// Given:

// heap = [-1, 6, -1, -1, 1, 6, 9, -1, 10, 8, 4, -1, -1, -1]
// headPtr = 4


// The list corresponds to:

// 4 → 1 → 6 → 9 → 8 → 10 → back to 4


// So the function should return 6.
int newNode(int heap[], int size)
{
    for (int i = 1; i < size; i++)
    {
        if (heap[i] == -1)        
        {
            heap[i] = 0;          
            return i;             
        }
    }
    return 0;
}