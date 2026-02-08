#include <iostream>
#include "Hoang_Le_Inventory.h"
#include "Hoang_Le_DynInventoryStack.h"
#include <string>
using namespace std;

int main() {
// create and push the item to inventory DB

Inventory item1(323,123,"02/07/2026");
Inventory item2(324,124,"02/07/2026");
Inventory item3(325,125,"02/07/2026");
Inventory item4(326,126,"02/07/2026");
DynInventoryStack stack1;
stack1.push(item1);
stack1.push(item2);
stack1.push(item3);
stack1.push(item4);
Inventory temp;

while(stack1.pop(temp)){
    cout << "Serial: " << temp.getSerialNum() << endl;
    cout << "Lot number: " << temp.getLotNum() << endl;
    cout << "ManuaFac Date: " << temp.getManufacDate() << endl;
    cout << "_______________-" << endl;
}
    

   
    return 0;
}


