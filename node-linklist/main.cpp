  #include <vector>
  #include <algorithm>
  #include <cstdlib>
  #include <limits>
  using namespace std;
  using std::vector;
  
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

int newNode(int heap[], int size){
    for (int i = 1; i < size;i++){
        if (heap[i] == -1){
            heap[i] == 0;
            return i;
        }
     // if not found , after reach the stop 
     // simply exit the code;
     return 0;
    }
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

  
    while (current != 0)
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
//Define a function bool canMakeInRange(int nums[],int length, int min, int max);

// that returns true if the values in some subset of nums add up to a total range[min,max], and false otherwise. If min <= 0 and max >= 0 is in that range, was can trivially make a value in the range by using no numbers at all). If min > 0 or max < 0 and length == 0 then the function should return false. (We need to make a nonzero value but we have no numbers to use).

// Your function is tested with the array {-4,5,-7,4,7} and various values of min and max.

// Hint: consider two cases: either the last element of nums in used or not. If you don't uses the last element then mind and max are unchanged. If you do uses the last element then min and max are both decreased by that amount for your recursive call.

//Additional Notes: Regarding your code's standard output, CodeLab will check for case errors but will ignore whitespace (tabs, spaces, newlines) altogether.



bool canMakeInRange(int nums[], int length, int min, int max) {

    if (length == 0)
        return (min <= 0 && max >= 0);

  
    if (canMakeInRange(nums, length - 1, min, max))
        return true;

    int last = nums[length - 1];
    return canMakeInRange(nums, length - 1, min - last, max - last);
}

//Write a definition of a recursive function named canMakeTotal with return type bool. The function receives two integer arguments: n and total. The function shuould return true if there is some subset of the digits of n that add up to the given total. Special cases are when total is 0, we will always return true if total is any nonzero values but n is 0,we'll always return false.

// Example canMakeTotal(1001007003,8) return true since 1 + 7 = 8 but canMakeTotal(1001007003,6) returns false since there is no subset of the digits in 1001007003 that add up to 6.

// Rules: No loops, no arrays, no funciton calls. Only local variables of type int or bool allowed.


bool canMakeTotal(int n , int total){
    if (total == 0) return true;
    if (n == 0) return false;
    if (total < 0) return false;

    if (n < 0) n = -n;
    int digit = n % 10;
    return canMakeTotal(n / 10, total - digit) || canMakeTotal(n / 10, total);
}

//Write a function called fastIntegerRoot that takes and int parameter n (assumed to be nonnegative) and returns an int equal to the integer suqaroot n. For example fastIntegerRoot(20). In general, the integer rot of n is the biggest interger r, such that r*r <= n.

// Use the following algorith (required) : if n is zero then just return 0. otherwise call the function recursively with argument n/4 and assign twice that value to a temporary variable t. Now you have something close to the integer root of n or perhaps something a bit too small. Use an if statement to decide which case you're in. 

int fastIntegerRoot(int n) {
   
    if (n == 0)
        return 0;

 
    int t = fastIntegerRoot(n / 4);

    if ((2 * t + 1) * (2 * t + 1) <= n)
        return 2 * t + 1;
    else
        return 2 * t;
}


// Suppose we add a new method of our Shape class with the prototype

// Shape& operator*=(int k) ;
// The job of operator*= is to multiply both width and height of the current object by k, assuming k > 0,  and return a reference to the updated current object.   Note: there is a special case where k is 0 or negative.  In this situation we will leave the current object unchanged, since multiplying width and height by 0 or a negative number would result in illegal values.

// a) Implement operator*= as it would appear in Shape.cpp.
Shape& Shape::operator*= (int k){
    if (k <= 0)
        return *this;
    // multiply both width and height of the current object by k
    width *= k;
    height *= k;
    return *this;
}
 

// b) Suppose r is a pointer of type Shape * which points to some object of an appropriate type. 

cout << ++((*r) *= 5) << endl;
// We've previously implemented the stream insertion operator << (outputs the Shape object's width and height in parentheses) and the pre-increment operator (increments width and height by 1).

// Type a single line of code that multiplies the object by 5, then increments it and and finally outputs the object to the console followed by an endl. This should all be done within one statement without using any other variables.   As an example, if initially the object's width is 10 and height 12 then the new values for the  width and height would be 51 and 61, respectively so the output would be (51,61)  (followed by the endl).


// c) Implement the * operator by calling operator*=. Write your function as it would appear Shape.cpp.

 Shape Shape::operator* (int k) const {
    Shape temp = *this;
    temp *= k;       
    return temp;
}

// d) Suppose we also have a += operator that adds the width and height of the right operand to the left operand and returns a reference to the left operand.

Shape Shape::operator+ (const Shape& rhs) const {
    Shape temp = *this;
    temp += rhs;
    return temp;
}