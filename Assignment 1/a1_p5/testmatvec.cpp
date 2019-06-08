/*
CH08-320143
testmatvec.cpp
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/

#include <bits/stdc++.h>
#include "Vector.h"
#include "Matrix.h"

using namespace std;

int main()
{
    // create instances of the classes
    Vector myVector;
    Matrix myMatrix;

    // open files for a reading
    ifstream file1,file2;
    ofstream out;

    // check files whether they exist
    if(!(file1.is_open()))
    {
        file1.open("in1.txt");
        if(file1.bad())
        {
            cerr << "Cannot open file!" << endl;
        }
    }

    if(!(file2.is_open()))
    {
        file2.open("in2.txt", ios::out);
        if(file2.bad())
        {
            cerr << "Cannot open file!" << endl;
        }
    }

    if(!(out.is_open()))
    {
        out.open("output.txt", ios::in);
        if(out.bad())
        {
            cerr << "Cannot open file!" << endl;
        }
    }

    file1 >> myVector;
    file2 >> myMatrix;
    out << "Vector * Matrix = " << endl << myVector * myMatrix << endl;
    out << "Matrix * Vector = " << endl << myMatrix * myVector <<endl;

    return 0;
}