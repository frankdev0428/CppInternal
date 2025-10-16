// Factorial is ONLY defined for nonnegative integers.
// Factorial of zero is 1.
// Factorial of any positive integer is the product of all 
// Integers from 1 up to that number.


#include <iostream>
using namespace std;

// return the factorial of n, using a loop.
unsigned long factIterative(int n);

// return the factorial of n, using recursion.
unsigned long factRecursive(int n);

unsigned long factRecursiveOpt(int n);

int main()
{
    // 15! = 1,307,674,368,000 so we might have integer overflow!
    cout << sizeof(unsigned int) << endl;
    cout << sizeof(unsigned long int) << endl;
    cout << sizeof(unsigned long long int) << endl;
    cin.get();
    for (int turn = 1; turn < 10; turn++) {
        int userValue;
        cout << "Please enter a nonnegative integer: ";
        cin >> userValue;
        if (userValue > 20) {
            cout << "Sorry that's too big, setting to 20." << endl;
            userValue = 20;
        }
        cout << "The iterative factorial of " << userValue << " is "
            << factIterative(userValue) << endl;
    
        cout << "The recursivefactorial of " << userValue << " is "
            << factRecursive(userValue) << endl;

        cout << "The recursivefactorialOptimized of " << userValue << " is "
            << factRecursiveOpt(userValue) << endl;
    }
    return 0;
}

// int ranges from -2^(31) up to 2^(31) -1
// or -2,147,483,648 to 2,147,483,647

// unsigned int ranges from 0 to 2^(32) - 1
// or 0 to 4,294,967,296

// long long int ranges from -2^(63) to 2^(63)-1
// or 9,223,372,036,854,775,808 to 9,223,372,036,854,775,807

// unsigned long long int ranges from 0 to 2^(64)-1
// or 0 to 18,446,744,073,709,551,615

// long int is the same as int or long long int depending on compiler




unsigned long factIterative(int n) {
    unsigned long result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}

// Precondtion: n >= 0
// Also because we are using 64 bit integers,
// the biggest value of n that can be used is 20.
// Base case is n==0, with return value 1.
// Recursive case will be n > 0.
// RATIONALE for returing n * factRecursive(n-1):
// Write n! as n *(n-1)*(n-2) *... * (3)*(2)*(1), so n! = n * (n-1)!
// For example 5! = 5 * 4 * 3 * 2 * 1, so 5! = 5 * 4!
// The final result will be correct, assuming the recursive call is correct.
// Also, using argument n-1 moves us closer the base case.
unsigned long factRecursive(int n) {
    if (n == 0)     // base case (correct)
        return 1;
    return n * factRecursive(n-1); // recursive case correct
}


unsigned long factRecursiveOpt(int n) {
    if (n == 0)  // base case (correct)
        return 1;
    if (n == 1)
        return 1;
    return n * (n-1) * factRecursiveOpt(n-2);
    // This works since n! = n * (n-1) * (n-2)!
    
}