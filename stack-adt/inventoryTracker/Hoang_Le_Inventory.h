#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>

class Inventory {
    private:
      int serialNum;
      //string that hold  manufatured (MM//DD/YYYY)
      string manufactDate;
      int lotNum;

    public:
    Inventory(int seri = 0,int lNum = 0 ,string manuDate = "")
    //getter + setter for serialNumber
    void setSeriaNum(int seri);
    int getSerialNum() const;
    //getter + setter for lotNumber
    void setLotNum(int lotN);
    int getLotNum() const;
    //getter + setter for manufacDate
     void setManufacDate(string date);
     string getManufacDate() const;



}


#endif