#include <iostream>
#include "IntBinaryTree.h"
using namespace std;


int main(){
IntBinaryTree tree;
int value;

cout << "Build you binary search tree" << endl;
cout << "Enter numbers to add to the tree or -1 when finished." << endl;

cout << "Enter a number: ";
cin >> value;
while (value != -1)
{
    tree.newInsertNode(value);
    cout << "Enter another number: ";
    cin >> value;
}
 cout << "\nInorder traversal." << endl;
 tree.displayInOrder();
 cout << endl;
 if (tree.isFull())
    cout << "This tree is a full binary tree!" << endl;
 else 
    cout << "This tree is NOT a full binary tree" << endl;
    return 0;
}