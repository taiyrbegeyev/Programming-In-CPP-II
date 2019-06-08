/*
CH08-320143
testWindGauge.cpp
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include "WindGauge.h"
#include <iostream>
using namespace std;

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
