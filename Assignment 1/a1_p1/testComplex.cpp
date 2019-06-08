/*
CH08-320143
testComplex.cpp
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include <iostream>
#include <fstream>
#include "Complex.h"

using namespace std;

int main()
{
    Complex myComplex1, myComplex2;

    // reading from the file
    ifstream in1, in2;

    cout << "Reading from the file..." << endl;
    in1.open("in1.txt", ios::in);
    in2.open("in2.txt", ios::in);
    in1 >> myComplex1; 
    in2 >> myComplex2;
    in1.close();
    in2.close();

    // writing to the file
    cout << "Writing to the file ..." << endl;
    ofstream out;
    out.open("output.txt", ios::out);

    Complex myComplex3;
    myComplex3 = myComplex1 + myComplex2;
    cout << "The sum = " << myComplex3;
    out << myComplex3;

    myComplex3 = myComplex1 - myComplex2;
    cout << "The sub = " << myComplex3;
    out << myComplex3;

    myComplex3 = myComplex1 * myComplex2;
    cout << "The mult = " << myComplex3;
    out << myComplex3;

    out.close();

    return 0;
}
