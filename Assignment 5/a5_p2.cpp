/*
CH08-320143
a5_p2.cpp
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include <iostream>
#include <cstring>
#include <exception>
using namespace std;

class OwnException: public exception {
    public:
        //OwnException() {}
        ~OwnException() {}
        const char *what() {
            return "OwnException\n";
        }
};

void function(int choice) {
    switch(choice) {
        case 1:
            throw 'a';
            break;
        case 2:
            throw 12;
            break;
        case 3:
            throw true;
            break;
        default:
            throw OwnException();
    }
}

int main() {
    // try all four versions and catch the 
    // corresponding exceptions
    try {
        function(1);
    }
    catch (char param) {
        cerr << "Caught in main: " << param << endl;
    }
    catch (int param) {
        cerr << "Caught in main: " << param << endl;
    }
    catch (bool param) {
        cerr << "Caught in main: " << param << endl;
    }
    catch (OwnException& param) {
        cerr << "Caught in main: " << param.what() << endl;
    }

    try {
        function(2);
    }
    catch (char param) {
        cerr << "Caught in main: " << param << endl;
    }
    catch (int param) {
        cerr << "Caught in main: " << param << endl;
    }
    catch (bool param) {
        cerr << "Caught in main: " << param << endl;
    }
    catch (OwnException& param) {
        cerr << "Caught in main: " << param.what() << endl;
    }

    try {
        function(3);
    }
    catch (char param) {
        cerr << "Caught in main: " << param << endl;
    }
    catch (int param) {
        cerr << "Caught in main: " << param << endl;
    }
    catch (bool param) {
        cerr << "Caught in main: " << param << endl;
    }
    catch (OwnException& param) {
        cerr << "Caught in main: " << param.what() << endl;
    }

    try {
        function(4);
    }
    catch (char param) {
        cerr << "Caught in main: " << param << endl;
    }
    catch (int param) {
        cerr << "Caught in main: " << param << endl;
    }
    catch (bool param) {
        cerr << "Caught in main: " << param << endl;
    }
    catch (OwnException& param) {
        cerr << "Caught in main: " << param.what() << endl;
    }

    return 0;
}