/*
CH08-320143
testFraction.cpp
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
        Fraction fraction1; // default constructor
        // test constructor integers are passed to
        Fraction fraction2(25, 50);
        Fraction fraction3(-100, 150);
        Fraction fraction4(33, -120);
        Fraction fraction5(-1, -9);
        // test constructor string is passed to
        Fraction fraction6("+2/+100");
        Fraction fraction7("+2/-500");
        Fraction fraction8("+2/679");
        Fraction fraction9("-2/-2");
        Fraction fraction10("-2/+1");
        Fraction fraction11("-155/45945");
        Fraction fraction12("5657/1234");
        // test copy constructor
        Fraction fraction13(fraction8); 

        Fraction sum(3, 2);
        Fraction difference("+3/+1");
        Fraction multiplication("1/-3");
        Fraction division(-3, 4);

        // test relational operators
        test(fraction3 < fraction2);
        test(fraction10 <= fraction9);  
        test(fraction12 > fraction6);
        test(fraction5 >= fraction11);
        test(fraction13 == fraction8);
        test(fraction7 != fraction4);

        // test arithmetical operators
        test(fraction2 + fraction9 == sum);
        test(fraction9 - fraction10 == difference);
        test(fraction2 * fraction3 == multiplication);
        test(fraction2 / fraction3 == division);

        // test assigment operator
        fraction1 = fraction12;
        test(fraction1 == fraction12);

        // test I/O operators
        cout << fraction1;
        cout << fraction2;
        cout << fraction3;
        cout << fraction4;
        cout << fraction5;
        cout << fraction6;
        cout << fraction7;
        cout << fraction8;
        cout << fraction9;
        cout << fraction10;
        cout << fraction11;
        cout << fraction12;
        cout << fraction13;

        int num, den;
        cout << "Enter the new one: ";
        cin >> num;
        cin >> den;
        Fraction fraction14(num, den);
        cout << fraction14;

        // should throw exception in following tests
        Fraction fraction15("12/");
        Fraction fraction16("/12");
        Fraction fraction17("+/12");
        Fraction fraction18("12/-");
        Fraction fraction19("/");
        Fraction fraction20("12345");
        Fraction fraction21("taiyr/begeyev");
        Fraction fraction22("s101/s202");
        Fraction fraction23("+taiyr/-begeyev");
        Fraction fraction24("1/0");
        Fraction fraction25(1, 0);
    }
    catch(const char* e) {
        cout << e << endl;
        cout << "Test " << counter << " fails" << endl;
        fail++;
        counter++;
    }

    cout << endl;
    cout << "Test Functions" << endl;
    cout << "Passed tests: " << pass << endl; 
    cout << "Failed tests: " << fail << endl;

    return 0;
}

