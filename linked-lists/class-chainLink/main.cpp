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
  //   cout << list1[1] << endl;
  //   list1[1] = 7;
  //   cout << list1[1] << endl;
    
    /*
    try {
        cout << list1.getFirst() << endl;
    }
    catch (std::logic_error e) {
        cout << e.what() << endl;
    }
    */

    
  //  list1.printList();
  //  list1.removeFirst();
  //  list1.printList();
  //  std::cin.get();
  //  for (int i = 10; i >= 1; i--) {
  //      list1.insertFirst(i);
      //  cout << list1.getLength() << endl;
       // cout << list1.getFirst() << endl;
      //  cin.get();
       // list1.printList();
      //  list1.removeFirst();
       // if (i % 10000000 == 0)
        //    std::cout << i << std::endl;
  //  }
  //  list1.printList();
  //  list1.removeFirst();
  //  list1.printList();
  //  cin.get();

    for (int j = 0; j < 100; j++) {
        LinkedList list2;
        for (int i = 0; i < 50000000; i++) {
            list2.insertFirst(i);
        }
        cout << list2.getFirst() << endl;
       // cin.get();
    }
    
    return 0;
}