/*
CH08-320143
adeque.cpp
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include <iostream>
#include <deque>
#include <iterator>
using namespace std;

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

// parametrical constructor
WindGauge::WindGauge(int period) {
    this->period = period;
}

//destructor
WindGauge::~WindGauge() {
    logs.clear();
}

// add the current speed to deque
void WindGauge::currentWindSpeed(int speed) {
    // if the history is longer than the period,
    // the oldest wind speed is discarded
    int length = logs.size();
    if (length >= period && period > 0)
        logs.pop_front();
    
    logs.push_back(speed);
}

// get the highest speed  
int WindGauge::highest() const {
    deque<int>::const_iterator it;
    it = logs.begin();
    int max = *it;
    for (it = logs.begin(); it != logs.end(); it++) {
        if (*it > max)
            max = *it;
    }
    return max;
}

// get the lowest speed
int WindGauge::lowest() const {
    deque<int>::const_iterator it;
    it = logs.begin();
    int min = *it;
    for (it = logs.begin(); it != logs.end(); it++) {
        if (*it < min)
            min = *it;
    }
    return min;
}

// get the average speed
int WindGauge::average() const {
    deque<int>::const_iterator it;
    int sum = 0;
    int length = logs.size();
    for (it = logs.begin(); it != logs.end(); it++) {
        sum += *it;
    }
    return sum / length;
}

void WindGauge::printResults() {
    cout << "The lowest: " << lowest() << endl;
    cout << "The average: " << average() << endl;
    cout << "The highest: " << highest() << endl;
}

int main() {
    WindGauge myWind;
    myWind.currentWindSpeed(15);
    myWind.currentWindSpeed(16);
    myWind.currentWindSpeed(12);
    myWind.currentWindSpeed(15);
    myWind.currentWindSpeed(15);

    myWind.printResults();

    myWind.currentWindSpeed(16);
    myWind.currentWindSpeed(17);
    myWind.currentWindSpeed(16);
    myWind.currentWindSpeed(16);
    myWind.currentWindSpeed(20);
    myWind.currentWindSpeed(17);
    myWind.currentWindSpeed(16);
    myWind.currentWindSpeed(15);
    myWind.currentWindSpeed(16);
    myWind.currentWindSpeed(20);

    myWind.printResults();
 
    return 0;
}
