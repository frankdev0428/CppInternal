#include <iostream>
#include "Hoang_Le_IntBinaryTree.h"
using namespace std;



int main() {
 IntBinaryTree tree;
    int value;

    cout << "Build your binary search tree!" << endl;
    cout << "Enter numbers to add to the tree or -1 when finished." << endl;

    cout << "Enter a number: ";
    cin >> value;

    while (value != -1)
    {
        tree.insertNode(value);

        cout << "Enter another number: ";
        cin >> value;
    }

    cout << "\nInorder traversal:" << endl;
    tree.displayInOrder();   // assuming your class already has this

    cout << "\nTotal number of nodes: "
         << tree.numNodes() << endl;

    cout << "Number of leaf nodes: "
         << tree.numLeafNodes() << endl;
    return 0;
}