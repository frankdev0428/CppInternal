#ifndef NUMBERLIST_H
#define NUMBERLIST_H

class NumberList{
    private:
    struct ListNode {
        double value;    // The value in this node
        struct ListNode *next; // To point to next node
    };
    ListNode *head; // List head pointer
    public: 
    // constructor
    NumberList(){ head = nullptr;}
    //destructor
    ~NumberList();
    
    // Linklist operations
    void appendNode(double);
    void insertNode(double);
    void deleteNode(double);
    void displayList() const;

};




#endif