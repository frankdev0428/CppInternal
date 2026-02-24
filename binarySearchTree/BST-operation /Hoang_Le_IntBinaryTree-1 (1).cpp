// Implementation file for the IntBinaryTree class
#include <iostream>
#include "IntBinaryTree.h"

//****************************************************************
// insert accepts a TreeNode pointer and a pointer to a node.    *
// The function inserts the node into the tree pointed to by     *
// the TreeNode pointer. This function is called recursively.    *
//****************************************************************
void IntBinaryTree::insert(TreeNode*& nodePtr, TreeNode*& newNode){
    if (nodePtr == nullptr)
        nodePtr = newNode;                  // Insert the node.
    else if (newNode->value < nodePtr->value)
        insert(nodePtr->left, newNode);     // Search the left branch.
    else
        insert(nodePtr->right, newNode);    // Search the right branch.
}
//****************************************************************
//  A private recursive function that checks if the tree is a full binary tree. *
//****************************************************************
// private member function
bool IntBinaryTree::isFull(TreeNode* nodePtr) const {
   //case 1 empty subtree
   if (nodePtr == nullptr)
    return true;
   //case 2: leaf node
   if (nodePtr->left == nullptr && nodePtr->right == nullptr)
    return true;
   //case 3: two children
   if (nodePtr->left != nullptr && nodePtr->right != nullptr)
    return isFull(nodePtr->left) && isFull(nodePtr->right);
    //case 4: only 1 child
    return false;
}

// public member function
bool IntBinaryTree::isFull() const{
    // a full binary tree is the tree have either zero or two node for each nodes 
    return isFull(root);
}
//****************************************************************
// insertNode creates a new node to hold num as its value,       *
// and passes it to the insert function.                         *
//****************************************************************
void IntBinaryTree::insertNode(int num){
   // Create a new node and store num in it.
    TreeNode* newNode = new TreeNode;
    newNode->value = num;
    newNode->left = newNode->right = nullptr;

    // Insert the node.
    insert(root, newNode);
}

//***************************************************
// destroySubTree is called by the destructor. It   *
// deletes all nodes in the tree recursively.       *
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

//******************************************************
// searchNode determines whether a value is present in *
// the tree. If so, the function returns true.         *
// Otherwise, it returns false.                        *
//******************************************************
bool IntBinaryTree::searchNode(int num){
    TreeNode* nodePtr = root;

    while(nodePtr){
        if (nodePtr->value == num)
            return true;
        else if (num < nodePtr->value)
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }
    return false;
}

//**********************************************
// remove calls deleteNode to delete the       *
// node whose value member is the same as num. *
//**********************************************
void IntBinaryTree::remove(int num){
    deleteNode(num, root);
}

//********************************************
// deleteNode deletes the node whose value   *
// member is the same as num recursively.    *
//********************************************
void IntBinaryTree::deleteNode(int num, TreeNode*& nodePtr){
    if (num < nodePtr->value)
        deleteNode(num, nodePtr->left);
    else if (num > nodePtr->value)
        deleteNode(num, nodePtr->right);
    else
        makeDeletion(nodePtr);
}

//**********************************************************
// makeDeletion takes a reference to a pointer to the node *
// that is to be deleted. The node is removed and the      *
// branches of the tree below the node are reattached.     *
//**********************************************************
void IntBinaryTree::makeDeletion(TreeNode*& nodePtr){
    // Define a temporary pointer to use in reattaching
    // the left subtree.
    TreeNode* tempNodePtr = nullptr;
    
    if (nodePtr == nullptr)
        std::cout << "Cannot delete empty node.\n";
    else if (nodePtr->right == nullptr){
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left;    // Reattach the left child.
        delete tempNodePtr;
    }
    else if (nodePtr->left == nullptr){
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;   // Reattach the right child.
        delete tempNodePtr;
    }
    // If the node has two children.
    else{
        // Move one node to the right.
        tempNodePtr = nodePtr->right;
        // Go to the end left node.
        while(tempNodePtr->left)
            tempNodePtr = tempNodePtr->left;
        // Reattach the left subtree.
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;
        // Reattach the right subtree.
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
}

//***************************************************************
// The displayInOrder member function displays the values       *
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
// The displayPreOrder member function displays the values       *
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
// The displayPostOrder member function displays the values       *
// in the subtree pointed to by nodePtr, via postorder traversal. *
//*****************************************************************
void IntBinaryTree::displayPostOrder(TreeNode* nodePtr) const{
    if (nodePtr){
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        std::cout << nodePtr->value << std::endl;
    }
}
// member function insert new node unrecursive
void IntBinaryTree::newInsertNode(int num){
   TreeNode* newNode = new TreeNode;
   newNode->value = num;
   newNode->left = newNode->right = nullptr;
   // if tree is empty 
   if (root == nullptr)
    {
        root = newNode;
        return;
    }
    TreeNode* current = root;
    TreeNode* parent = nullptr;
    while(current != nullptr)
    {
        parent = current;

        if (num < current->value)
            current = current->left;
        else 
            current = current->right;
    }

    if (num < parent->value)
        parent->left = newNode;
    else 
        parent->right = newNode;
   
    
};
