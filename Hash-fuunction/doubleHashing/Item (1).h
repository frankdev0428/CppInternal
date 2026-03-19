// Class representing a single item in the hash table
#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item{
    public:
        int key;
        std::string value;

    // Constructor
    Item(int k = -1, std::string v = ""){
        key = k;
        value = v;
    }
};

#endif