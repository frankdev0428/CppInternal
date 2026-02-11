#include <iostream>
#include <string>
#include "StringQueue.h"
using namespace std;

int main()
{
    int n;

    cout << "This program displays binary numbers from 1 to n." << endl;
    cout << "Enter a decimal number: ";
    cin >> n;

    // Input validation
    while (n < 1)
    {
        cout << "ERROR! Please enter a positive number: ";
        cin >> n;
    }

    // Create queue of size 100
    StringQueue queue(100);

    // Start with "1"
    queue.enqueue("1");

    // Generate binary numbers
    for (int i = 0; i < n; i++)
    {
        string current;

        // Remove front element
        queue.dequeue(current);

        // Print it
        cout << current << endl;

        // Generate next two binary numbers
        queue.enqueue(current + "0");
        queue.enqueue(current + "1");
    }

    return 0;
}