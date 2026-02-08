#include <iostream>
#include "Hoang_Le_Inventory.h"
#include <string>
#include <stack>
using namespace std;

int main() {
Inventory bottle(12,22,"3/12/2025");
cout << "This is inventory bottle information: " << endl;
cout << "Serial number: " << bottle.getSerialNum() << endl;
cout << "Lot number: " << bottle.getLotNum() << endl;
cout << "Manufacture Date: " << bottle.getManufacDate() << endl;



    return 0;
}