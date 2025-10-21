#ifndef NUMBERS_H
#define NUMBERS_H

class Numbers {
    private:
     int number;
    public:
     Numbers(int num = 0);
     void print();
     int getNum();
     void setNum(int n);
     Numbers operator+(const Numbers &other);
     
};


#endif