#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Hoang_Le_HashTable.h"
using namespace std;


int main() {
    HashTable ht(101);

    std::ifstream file("data.txt");

    if (!file){
        std::cout << "Error opening file." << std::endl;
        return 1;
    }

    int key;
    std::string value;
    int totalRecords = 0;

    //Read file
    while (file >> key >> value){
        ht.insert(key, value);
        totalRecords++;
    }

    file.close();
    // find location with most collisions
    int maxIndex = 0;
    int maxSize = 0;

    for(int i = 0; i < 101; i++){
        int size = ht.getLocationSize(i);

        if (size > maxSize) {
            maxSize = size;
            maxIndex = i;
        }
    }
    //display report 

    std::cout << "---- Hash Table Report ----" << std::endl;
    std::cout << "Total records processed: " << totalRecords << std::endl;
    std::cout << "Location with the most collsions: Index " << mainIndex << std::endl;
    std::cout << "Number of records at this location: " << maxSize << std::endl;
    std::cout << "Recors at this location: ";
    ht.displayLocation(maxIndex);

    return 0;
}