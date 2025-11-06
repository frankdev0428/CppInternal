#include <iostream>
#include "LinkedList.h"
using std::cout;
using std::cin;
using std::endl;

int main()
{
    LinkedList list1;
    list1.insertFirst(3);
    list1.insertFirst(5);
    list1.insertFirst(7);
    list1.printList();

    cout << "Insert value 9 at index 1" << endl;
    list1.insertAtIndex(9, 1);
    list1.printList();

    cout << "Remove first value" << endl;
    list1.removeFirst();
    list1.printList();

    cout << "Remove value 9" << endl;
    list1.removeAValue(9);
    list1.printList();

    cout << "Insert value 10 at index 0" << endl;
    list1.insertAtIndex(10, 0);
    list1.printList();

    cout << "Remove index 2" << endl;
    list1.removeAtIndex(2);
    list1.printList();

    cout << "Count of 3 = " << list1.count(3) << endl;
    cout << "Length = " << list1.getLength() << endl;

    for (int j = 0; j < 3; j++) {  // reduced to 3 loops for testing
        LinkedList list2;
        for (int i = 0; i < 10; i++) {  // reduced to 10 for safety
            list2.insertFirst(i);
        }
        cout << "First value of list2 = " << list2.getFirst() << endl;
        list2.printList();
    }

    return 0;
}
