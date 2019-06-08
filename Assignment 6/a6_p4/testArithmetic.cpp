/*
CH08-320143
testArithmetic.cpp
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
    // exception is thown if denominator is zero
    try {
        cout << "Test Arithmetic operators" << endl;
        Fraction fraction2(25, 50);
        Fraction fraction3(-100, 150);
        Fraction fraction9("-2/-2");
        Fraction fraction10("-2/+1");
        Fraction sum(3, 2);
        Fraction difference("+3/+1");
        Fraction multiplication("1/-3");
        Fraction division(-3, 4);

        // test arithmetical operators
        test(fraction2 + fraction9 == sum);
        test(fraction9 - fraction10 == difference);
        test(fraction2 * fraction3 == multiplication);
        test(fraction2 / fraction3 == division);
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