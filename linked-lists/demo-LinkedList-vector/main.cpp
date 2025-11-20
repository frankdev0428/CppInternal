#include <iostream>
#include <string>
#include <vector>
#include "LinkedList.h"
using namespace std;

int main()
{
    cout << boolalpha;

    LinkedList<int> list1;
    list1.insertFirst(3);
    list1.insertFirst(5);
    list1.insertFirst(7);
    list1.printList();       // < 7 5 3 >

    list1.removeFirst();
    list1.printList();       // < 5 3 >

    cout << list1.getFirst() << endl; // 5

    list1[1] = 99;
    list1.printList();       // < 5 99 >


    LinkedList<string> list2;
    list2.insertFirst("hello");
    list2.insertFirst("hola");
    list2.insertFirst("salut");
    list2.printList();       // < salut hola hello >

    list2.removeFirst();
    list2.printList();       // < hola hello >

    cout << list2.getFirst() << endl; // hola

    list2[1] = "bonjour";
    list2.printList();       // < hola bonjour >

    cout << list2.contains("hola") << endl; // true


    vector<int> v1;
    vector<int> v2;

    v1.push_back(22);
    v1.push_back(33);

    v2.push_back(800);
    v2.push_back(900);
    v2.push_back(600);

    cout << (v1 < v2) << endl;  // vector lexicographical comparison


    // FIXED TEMPLATE SYNTAX
    LinkedList<vector<int > > list3;

    list3.insertFirst(v1);
    list3.insertFirst(v2);

    cout << list3.getFirst()[1] << endl;    // second element of v2
    cout << list3.contains(v1) << endl;     // true

    return 0;
}
