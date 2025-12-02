#include <iostream>
using namespace std;

class Node {

public:

   int value;

   Node * next;

   Node (int val = 0 , Node * nxt = nullptr ){

       value = val;

        next = nxt;

    }

};


Node * sortHelper (Node * first) {
    if (first == nullptr || first->next == nullptr) return first;
    Node * t = sortHelper(first->next);

    // detach first (its next will be set when inserted)
    first->next = nullptr; 

    if (t == nullptr) return first;

    if(first->value < t->value){
        first->next = t;
        return first;
    
    Node * pre = t;

    while (pre->next != nullptr && pre->next->value < first->value) {
        pre = pre->next;
    }
    Node * pre = t;
   
    first->next = pre->next;
    pre->next = first;
    return t;
}
}



int main() {
   Node * first = new Node(0);

   for (int i = 1; i <= 5; i++) {

        first = new Node(i, first); 
   }

   Node * result =  sortHelper(first);

   while (result != nullptr) {                

         cout << result->value << " ";

         result = result->next;

   }
   return 0;
}
