/*
CH08-320143
testRelational.cpp
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include <iostream>
#include "Fraction.h"
using namespace std;

int pass = 0, fail = 0;
int counter = 1;

void test(bool b) {
    if (b) {
        cout << "Test " << counter << " passes" << endl;
        pass++;
    }
    else {
        cout << "Test " << counter << " fails" << endl;
        fail++;
    }
    counter++;
}

int main() {

    try {
        cout << "Test relational operators" << endl;
        Fraction fraction1(1, 2);
        Fraction fraction2("1/2");
        Fraction fraction3(-1, 3);
        Fraction fraction4("-1/6");
        test(fraction3 < fraction1);
        test(fraction4 <= fraction2);  
        test(fraction1 > fraction3);
        test(fraction2 >= fraction4);
        test(fraction1 == fraction2);
        test(fraction1 != fraction3);
    }
    catch (const char* e) {
        cout << e << endl;
        test(false);
    }

    cout << "Test Functions" << endl;
    cout << "Passed tests: " << pass << endl; 
    cout << "Failed tests: " << fail << endl;
    cout << endl;
    
    return 0;
}