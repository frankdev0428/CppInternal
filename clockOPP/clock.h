
#ifndef CLOCK_H
#define CLOCK_H


class Clock {
   private:
        int hour;
        int minute;
        int second;

   public:
   //constructor
       Clock(int h = 0, int m = 0,int s = 0 );
       void print() const; // print the time
       int getHour() const;
       int getMinute() const;
       int getSecond() const;
       
       void setHour(int h);
       void setMinute(int m);
       void setSecond(int s);

       void tick();  //increment the time by 1 sec;
       void setCurrent();


};

#endif