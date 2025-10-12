#include "clock.h"
#include <iostream>

Clock::Clock(int h, int m,int s)
{
   
  setHour(h);
  setMinute(m);
  setSecond(s);
}
       int Clock::getHour() const {
            return hour;
       };
       int Clock::getMinute()  const {
            return minute;
       };
       int Clock::getSecond() const {
            return second;
       }
       
       void Clock::setHour(int h)  {
           if (h < 0)
                hour = 0;
        else if (h > 23)
                hour = 23;
        else 
                hour = h;

       }
       void Clock::setMinute(int m)
       {
            if (m < 0)
                minute = 0;
            else if (m > 59)
                minute = 59;
            else 
                minute = m;
       }
       void Clock::setSecond(int s){
                if (s < 0)
                    second = 0;
                else if (s > 59)
                    second = 59;
                else 
                    second = s;
       }

       void Clock::tick()
       {
            second++;
            if (second == 60)
            {
                    second = 0;
                    minute++;
                    if (minute == 60 )
                    {
                     minute = 0;
                     hour++;

                    }
                    if (hour == 24) hour = 0;
            }
       } //increment the time by 1 sec;
        void Clock::setCurrent() {
            time_t now = time(0);
            tm *ltm = localtime(&now);
            setHour(ltm->tm_hour);
            setMinute(ltm->tm_min);
            setSecond(ltm->tm_sec);
        }

      void Clock::print() const {
          std::cout << hour << ":";
          if (minute < 10) std::cout << "0";
          std::cout << minute << ":";
          if (second < 10) std::cout << "0";
          std::cout << second;
          std::cout << std::endl;
       } // print the time

