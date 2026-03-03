#include <iostream>
#include <string>
#include <fstream>
#include "Hoang_Le_LinearPHashTable.h"
#include "Hoang_Le_QuadPHashTable.h"
using namespace std;


int main() {
     LinearPHashTable linear151(151);
     LinearPHashTable linear211(211);

     QuadPHashTable quad151(151);
     QuadPHashTable quad211(211);

     ifstream file("cityData.txt");

     if (!file)
     {
        cout << "Error opening file." << endl;
        return 1;
     }

     int key;
     string value; 
     while (file >> key >> value )
     {
        linear151.insert(key,value);
        linear211.insert(key, value);
        quad151.insert(key, value);
        quad211.insert(key, value);
     }

     file.close();

        cout << "--- Hash Table Report ---" << endl;

    cout << "\nLinear Probing (Size 151):" << endl;
    cout << "- Load Factor: " << linear151.getLoadFactor() << endl;
    cout << "- Total Probe Count: " << linear151.getTotalProbeCount() << endl;
    cout << "- Max Probe Count for one item: " << linear151.getMaxProbeCount() << endl;

    cout << "\nLinear Probing (Size 211):" << endl;
    cout << "- Load Factor: " << linear211.getLoadFactor() << endl;
    cout << "- Total Probe Count: " << linear211.getTotalProbeCount() << endl;
    cout << "- Max Probe Count for one item: " << linear211.getMaxProbeCount() << endl;

    cout << "\nQuadratic Probing (Size 151):" << endl;
    cout << "- Load Factor: " << quad151.getLoadFactor() << endl;
    cout << "- Total Probe Count: " << quad151.getTotalProbeCount() << endl;
    cout << "- Max Probe Count for one item: " << quad151.getMaxProbeCount() << endl;

    cout << "\nQuadratic Probing (Size 211):" << endl;
    cout << "- Load Factor: " << quad211.getLoadFactor() << endl;
    cout << "- Total Probe Count: " << quad211.getTotalProbeCount() << endl;
    cout << "- Max Probe Count for one item: " << quad211.getMaxProbeCount() << endl;

    // Comparison
    if (quad151.getTotalProbeCount() < linear151.getTotalProbeCount())
        cout << "\nQuadratic probing performs better for size 151." << endl;
    else
        cout << "\nLinear probing performs better for size 151." << endl;

    if (quad211.getTotalProbeCount() < linear211.getTotalProbeCount())
        cout << "Quadratic probing performs better for size 211." << endl;
    else
        cout << "Linear probing performs better for size 211." << endl;


    return 0;
}