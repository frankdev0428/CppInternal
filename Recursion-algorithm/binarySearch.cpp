// return the index of target in nums or -1 if target is not found.
// Precondition: The array is sorted in ascending order.
int binarySearchIterative(int nums[], int length, int target);
int binarySearchRecursive(int nums[], int low, int high, int target);

#include <iostream>
using namespace std;

int main()
{
    int numbers[8] = { 1, 3, 5, 7, 9, 11, 13, 15};
    cout << "binarySearchIterative output." << endl;
    for (int i = 0; i < 16; i++) 
        cout << (i % 2 == 1 ? '\t' : ' ')  << i << ": "
              << binarySearchIterative(numbers, 8, i) << endl;
    cout << endl << endl;
    cout << "binarySearchRecursive output." << endl;
    for (int i = 0; i < 16; i++)
        cout << (i % 2 == 1 ? '\t' : ' ') << i << ": "
              << binarySearchRecursive(numbers, 0, 7, i) << endl;

    return 0;
}

// Integer division of two positive numbers always rounds down.
// Example 3 / 2 mathematically is 1.5 but in C++ it's just 1.
// 11/4 mathematically is 2.75 but in C++ it's just 2.
// { 1, 3, 5, 7, 9, 11, 13, 15}; 
int binarySearchIterative(int nums[], int length, int target)
{
    int low = 0, high = length - 1;
    while (low < high) {
        int mid= (low + high)/ 2; // First compare target with nums[3]=7
        if (target <= nums[mid])
            high = mid;
        else
            low = mid + 1;

    }
    if (nums[low] == target)
        return low;
    return -1;
}

int binarySearchRecursive(int nums[], int low, int high, int target)
{
    if (low == high) {
        return nums[low] == target ? low : -1;
    }
    if (low < high) {
        int mid = (low + high) / 2;  // First compare target with nums[3] = 7
        if (target <= nums[mid])
            return binarySearchRecursive(nums, low, mid, target);
        return binarySearchRecursive(nums, mid + 1, high, target);
    }
  
}
