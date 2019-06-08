/*
CH08-320143
WindGauge.h
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include <deque>
#ifndef _WINDGAUGE_H
#define _WINDGAUGE_H

class WindGauge {
    private:
        std::deque<int> logs;
        int period;
    public:
        // parametrical constructor
        WindGauge(int = 12);
        //destructor
        ~WindGauge();
        
        // add the current speed to deque
        void currentWindSpeed(int);
        // get the highest speed  
        int highest() const;
        // get the lowest speed
        int lowest() const;
        // get the average speed
        int average() const;  
        void printResults();
};

#endif