// Implementation file for the IntBinaryTree class
// This version does not have search or deletion operations.
#include <iostream>
#include "Hoang_Le_IntBinaryTree.h"
//****************************************************************
// insert accepts a TreeNode pointer and a pointer to a node. *
// The function inserts the node into the tree pointed to by *
// the TreeNode pointer. This function is called recursively. *
//****************************************************************
void IntBinaryTree::insert(TreeNode*& nodePtr, TreeNode*& newNode){
    if (nodePtr == nullptr)
    nodePtr = newNode; // Insert the node.
    else if (newNode->value < nodePtr->value)
    insert(nodePtr->left, newNode); // Search the left branch.
    else
    insert(nodePtr->right, newNode); // Search the right branch.
}

    // insert function accept 2 pointer, one pointer point to the root node, second pointer point to a new Node
    // first check if the list is empty 
        // if so the newNode will become root node
    // else if value of newNode (use arrow because newNode is pointer) < value of rootPointer
        // insert the node to the left branch 
    // else (mean the value of newNode > root->value )
        // insert to the right branch
void IntBinaryTree::insertNode(int num){
TreeNode* newNode = nullptr; // Pointer to a new node.
// Create a new node and store num in it.
newNode = new TreeNode;
newNode->value = num;
newNode->left = newNode->right = nullptr;
// Insert the node.
insert(root, newNode);
}

//****************************************************************
// insertNode creates a new node to hold num as its value, *
// and passes it to the insert function. *
//****************************************************************
//***************************************************
// destroySubTree is called by the destructor. It *
// deletes all nodes in the tree recursively. *
//***************************************************
void IntBinaryTree::destroySubTree(TreeNode* nodePtr){
    if (nodePtr){
    if (nodePtr->left)
    destroySubTree(nodePtr->left);
    if (nodePtr->right)
    destroySubTree(nodePtr->right);
    delete nodePtr;
}
}
//***************************************************************
// The displayInOrder member function displays the values *
// in the subtree pointed to by nodePtr, via inorder traversal. *
//***************************************************************
void IntBinaryTree::displayInOrder(TreeNode* nodePtr) const{
    if (nodePtr){
    displayInOrder(nodePtr->left);
    std::cout << nodePtr->value << std::endl;
    displayInOrder(nodePtr->right);
}
}
//****************************************************************
// The displayPreOrder member function displays the values *
// in the subtree pointed to by nodePtr, via preorder traversal. *
//****************************************************************
void IntBinaryTree::displayPreOrder(TreeNode* nodePtr) const{
    if (nodePtr){
    std::cout << nodePtr->value << std::endl;
    displayPreOrder(nodePtr->left);
    displayPreOrder(nodePtr->right);
}
}
//*****************************************************************
// The displayPostOrder member function displays the values *
// in the subtree pointed to by nodePtr, via postorder traversal. *
//*****************************************************************
void IntBinaryTree::displayPostOrder(TreeNode* nodePtr) const{
if (nodePtr){
displayPostOrder(nodePtr->left);
displayPostOrder(nodePtr->right);
std::cout << nodePtr->value << std::endl;
}
}
 // Count total nodes
int IntBinaryTree::countNodes(TreeNode* node) const{
    if (node == nullptr)
    return 0;
  return 1 + countNodes(node->left) + countNodes(node->right);
}


int IntBinaryTree::numNodes() const{
    return countNodes(root);
}
// Count leaf Nodes

int IntBinaryTree::countLeafNodes(TreeNode* node) const {
    if (node == nullptr)
     return 0;
    if (node->left == nullptr && node->right == nullptr )
        return 1;
return countLeafNodes(node->left) + countLeafNodes(node->right);
}


int IntBinaryTree::numLeafNodes() const {
     return countLeafNodes(root);
}