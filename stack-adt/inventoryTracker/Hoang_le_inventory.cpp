#include <iostream>
#include <string>
#include "Hoang_Le_Inventory.h"
using namespace std;

//  int serialNum;
//       //string that hold  manufatured (MM//DD/YYYY)
//       string manufactDate;
//       int lotNum;

Inventory::Inventory(int seri,int lNum ,string manuDate ){
   serialNum = seri;
   manufactDate = manuDate;
   lotNum = lNum; 
};
    //getter + setter for serialNumber
void Inventory::setSeriaNum(int seri){
      serialNum = seri;
};
int Inventory::getSerialNum() const {
    return serialNum;
};
    //getter + setter for lotNumber
void Inventory::setLotNum(int lotN) {
    loNum = lotN;
};
int Inventory::getLotNum() const {
    return lotNum;
};
    //getter + setter for manufacDate
void Inventory::setManufacDate(string date) {
    manufactDate = date;
};
string Inventory::getManufacDate() const{
    return manufactDate;
};