#include <iostream>
#include "Hoang_Le_Inventory.h"
#include "Hoang_Le_DynInventoryStack.h"
#include <string>
using namespace std;

int main() {
    DynInventoryStack stack;   // create the stack

    cout << "Adding parts to the inventory!" << endl;

    // =========================
    // ADD PARTS LOOP
    // =========================
    char choice = 'y';

    while (choice == 'y' || choice == 'Y')
    {
        int serialNum;
        int lotNum;
        string manufactureDate;

        cout << "Enter serial number: ";
        cin >> serialNum;

        cout << "Enter manufacture date (MM/DD/YYYY): ";
        cin >> manufactureDate;

        cout << "Enter lot number: ";
        cin >> lotNum;

        // create Inventory object
        Inventory item(serialNum, lotNum, manufactureDate);

        // push onto stack
        stack.push(item);

        cout << "Add another part? (y/n): ";
        cin >> choice;
        cout << endl;
    }
cout << "Is stack empty? " << stack.isEmpty() << endl;
    // =========================
    // POP SPECIFIED NUMBER
    // =========================
    int removeCount;
    cout << "How many parts do you want to take from the inventory? ";
    cin >> removeCount;
    cout << endl;

    cout << "Removed parts:" << endl;

    Inventory temp;
    int removed = 0;

    while (removed < removeCount && stack.pop(temp))
    {
        cout << "Serial Number: " << temp.getSerialNum() << endl;
        cout << "Manufacture Date: " << temp.getManufacDate() << endl;
        cout << "Lot Number: " << temp.getLotNum() << endl;
        cout << endl;

        removed++;
    }

    cout << "------------------------------------" << endl << endl;

    // =========================
    // POP REMAINING INVENTORY
    // =========================
    cout << "Remaining inventory:" << endl;

    while (stack.pop(temp))
    {
        cout << "Serial Number: " << temp.getSerialNum() << endl;
        cout << "Manufacture Date: " << temp.getManufacDate() << endl;
        cout << "Lot Number: " << temp.getLotNum() << endl;
        cout << endl;
    }
    

   
    return 0;
}


