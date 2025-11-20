#include <iostream>
#include "LinkedList.h"
using std::cout;
using std::cin;
using std::endl;

int main()
{

    LinkedList listTest;
    listTest.insertFirst(5);
    listTest.insertFirst(4);
    listTest.insertFirst(11);
    listTest.insertFirst(3);
    listTest.insertFirst(2);
    listTest.insertFirst(9);
    listTest.insertFirst(6);
    listTest.printList();
   
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
