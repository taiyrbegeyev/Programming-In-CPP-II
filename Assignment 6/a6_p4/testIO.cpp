/*
CH08-320143
testIO.cpp
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
        cout << "Test I/O operators" << endl;
        Fraction fraction;
        cout << "Enter fraction (numerator and denominator "
            "are separated by space or line)" << endl;

        cin >> fraction;
        test(true);
        cout << fraction;
        test(true);
    }
    catch (const char* e) {
        cout << e << endl;
        test(false);
        test(false);
    }

    cout << "Test Functions" << endl;
    cout << "Passed tests: " << pass << endl; 
    cout << "Failed tests: " << fail << endl;
    cout << endl;

    return 0;
}