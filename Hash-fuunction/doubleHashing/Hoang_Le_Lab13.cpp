#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

#include "Hoang_Le_LinearPHashTable.h"
#include "Hoang_Le_QuadPHashTable.h"
#include "Hoang_Le_DoubleHHashTable.h"
using namespace std;


int main() {
   srand(time(0));
    LinearPHashTable linear(211);
    QuadPHashTable quad(211);
    DoubleHHashTable dbl(211);

    ifstream file1("cityData.txt");
    if(!file1) {
        cout << "Error opening cityData.txt";
        return 1;
    }

    int key;
    string value;
    int insertcount = 0l
    while(!file >> key >> value)
    {
        linear.insert(key,value);
        quad.insert(key,value);
        dbl.insert(key,value);
        insertCount++;
    }
   
    file1.close();

    ifstream file2("newCountryData.txt");
    if(!file2) {
        cout << "Error opening newCountryData.txt\n";
        return 1;
    }

    int searchCount  = 0;
    while (file2 >> key >> value)
    {
        linear.lookup(key);
        quad.lookup(key);
        dbl.lookup(key);
        searchCount++;
    }
   file2.close();
    cout << "--- Hash Table Report ---\n";

    cout << "\nLinear Probing (Size 211):\n";
    cout << "- Average Insert Probe Count: "
         << (double)linear.getInsertProbeCount() / insertCount << endl;
    cout << "- Average Search Probe Count: "
         << (double)linear.getSearchProbeCount() / searchCount << endl;

    cout << "\nQuadratic Probing (Size 211):\n";
    cout << "- Average Insert Probe Count: "
         << (double)quad.getInsertProbeCount() / insertCount << endl;
    cout << "- Average Search Probe Count: "
         << (double)quad.getSearchProbeCount() / searchCount << endl;

    cout << "\nDouble Hashing (Size 211):\n";
    cout << "- Average Insert Probe Count: "
         << (double)dbl.getInsertProbeCount() / insertCount << endl;
    cout << "- Average Search Probe Count: "
         << (double)dbl.getSearchProbeCount() / searchCount << endl;

    cout << "\n--- Hash Table Evaluation ---\n";
      if (dbl.getInsertProbeCount() < quad.getInsertProbeCount() &&
        dbl.getInsertProbeCount() < linear.getInsertProbeCount())
        cout << "Double Hashing performed the best during insertion.\n";

    if (dbl.getSearchProbeCount() < quad.getSearchProbeCount() &&
        dbl.getSearchProbeCount() < linear.getSearchProbeCount())
        cout << "Double Hashing performed the best during (unsuccessful) searching.\n";
   
    return 0;
}