// Specification file for the List class
#ifndef LIST_H
#define LIST_H

#include <string>

class List{
    private:
    // Declare a structure for the list
        struct ListNode{
            int key;            // The key in this node
            std::string value;  // The value in this node
            ListNode* next;     // To point to the next node
        };

        ListNode* head;         // List head pointer

    public:
        // Constructor
        List(){
            head = nullptr;
        }
        // Destructor
        ~List();

        // Linkedin List operations
        void insertNode(int, std::string);
        bool deleteNode(int);
        std::string search(int);
};
#endif

