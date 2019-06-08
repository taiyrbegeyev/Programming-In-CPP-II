/*
CH08-320143
testExceptions.cpp
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
    /* Test constructors */
    // Following cases should pass
    try {
        Fraction fraction2(25, 50);
        test(true);
    }
    catch (const char* e) {
        cout << e << endl;
        test(false);
    }

    try {
        Fraction fraction3(-100, 150);
        test(true);
    }
    catch (const char* e) {
        cout << e << endl;
        test(false);
    }

    try {
        Fraction fraction4(33, -120);
        test(true);
    }
    catch (const char* e) {
        cout << e << endl;
        test(false);
    }

    try {
        Fraction fraction5(-1, -9);
        test(true);
    }
    catch (const char* e) {
        cout << e << endl;
        test(false);
    }

    try {
        Fraction fraction6("+2/+100");
        test(true);
    }
    catch (const char* e) {
        cout << e << endl;
        test(false);
    }

    try {
        Fraction fraction7("+2/-500");
        test(true);
    }
    catch (const char* e) {
        cout << e << endl;
        test(false);
    }

    try {
        Fraction fraction8("+2/679");
        test(true);
    }
    catch (const char* e) {
        cout << e << endl;
        test(false);
    }

    try {
        Fraction fraction9("-2/-2");
        test(true);
    }
    catch (const char* e) {
        cout << e << endl;
        test(false);
    }

    try {
        Fraction fraction10("-2/+1");
        test(true);
    }
    catch (const char* e) {
        cout << e << endl;
        test(false);
    }

    try {
        Fraction fraction11("-155/45945");
        test(true);
    }
    catch (const char* e) {
        cout << e << endl;
        test(false);
    }

    try {
        Fraction fraction12("5657/1234");
        test(true);
    }
    catch (const char* e) {
        cout << e << endl;
        test(false);
    }

    try {
        Fraction fraction13("5657/1234");
        // test copy constructor
        Fraction fraction14(fraction13); 
        test(true);
    }
    catch (const char* e) {
        cout << e << endl;
        test(false);
    }

    /* Errors will be thrown for following cases */
    try {
        Fraction fraction15("12/");
        test(true);
    }
    catch (const char* e) {
        cout << e << endl;
        test(false);
    }

    try {
        Fraction fraction16("/12");
        test(true);
    }
    catch (const char* e) {
        cout << e << endl;
        test(false);
    }

    try {
        Fraction fraction17("+/12");
        test(true);
    }
    catch (const char* e) {
        cout << e << endl;
        test(false);
    }

    try {
        Fraction fraction18("12/-");
        test(true);
    }
    catch (const char* e) {
        cout << e << endl;
        test(false);
    }

    try {
        Fraction fraction19("/");
        test(true);
    }
    catch (const char* e) {
        cout << e << endl;
        test(false);
    }

    try {
        Fraction fraction20("12345");
        test(true);
    }
    catch (const char* e) {
        cout << e << endl;
        test(false);
    }

    try {
        Fraction fraction21("taiyr/begeyev");
        test(true);
    }
    catch (const char* e) {
        cout << e << endl;
        test(false);
    }

    try {
        Fraction fraction22("s101/s202");
        test(true);
    }
    catch (const char* e) {
        cout << e << endl;
        test(false);
    }

    try {
        Fraction fraction23("+taiyr/-begeyev");
        test(true);
    }
    catch (const char* e) {
        cout << e << endl;
        test(false);
    }

    try {
        Fraction fraction24("1/0");
        test(true);
    }
    catch (const char* e) {
        cout << e << endl;
        test(false);
    }

    try {
        Fraction fraction25(1, 0);
        test(true);
    }
    catch (const char* e) {
        cout << e << endl;
        test(false);
    }

    // test Assigment operator
    try {
        Fraction fraction26(1, 2);
        Fraction fraction27;
        fraction27 = fraction26;
        test(true);
    }
    catch(const char* e) {
        cout << e << endl;
        test(false);
    }

    cout << "Test Functions" << endl;
    cout << "Passed tests: " << pass << endl; 
    cout << "Failed tests: " << fail << endl;
    cout << endl;

    return 0;
}