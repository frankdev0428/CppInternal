#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    const int TABLE_SIZE = 151;
    // create a hash table using vector
    vector<int> hashTable(TABLE_SIZE,0);
    // openning file to read data into main function 
    ifstream inputFile("numbers.txt");

    if (!inputFile)
    {
      cout << "Error opening numbers.txt file." << endl;
      return 1;
    }
    
    cout << "Reading from numbers.txt......." << endl << endl;
    // Get universal hash function values 
    int a,b;
    cout << "Enter a value for a: ";
    cin >> a;
      cout << "Enter vale for b: ";
    cin >> b;
    
    int number; 
    // Read a file and hash values 
    while (inputFile>> number)
    {
        // Apply universal hash funciton formula 
        int index = (a * number + b) % TABLE_SIZE;
        hashTable[index]++;
    }
    inputFile.close();
    // display distribution 
    cout << endl;
    cout << "Hash Table Distribution:" << endl;
   for (int i = 0; i < TABLE_SIZE;i++)
   {
    cout << "Location " << i << ": "
     << hashTable[i] << " insertions" << endl;
   }
   // Find location with most insertions
   int maxInsertions = hashTable[0];
   int maxLocation = 0;

   for (int i = 1;i < TABLE_SIZE; i++){
      if (hashTable[i] > maxInsertions)
      {
        maxInsertions = hashTable[i];
        maxLocation = i;
      }
   }

   cout << endl;
   cout << "Location with the most insertions: " << endl;
   cout << "Location " << maxLocation << " with " << maxInsertions << " insertions" << endl;

     return 0;
}