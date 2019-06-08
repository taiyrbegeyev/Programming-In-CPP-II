/*
CH08-320143
testAccessSet.cpp
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include "Access.h"
#include <iostream>
using namespace std;

int main() {
    Access Bank;

    // activate codes
    Bank.activate(1234);
    Bank.activate(9999);
    Bank.activate(9876);

    // ask the user for an access code
    unsigned int access;
    
    while(1) {
        cout << "Enter the access code: ";
        cin >> access;
        if (Bank.isactive(access)) {
            cout << "Door is open. Come on in!" << endl;
            break;
        }
        else 
            cout << "Something went wrong" << endl;
    }

    //deactivate the code that worked
    Bank.deactivate(access);
    // also deactivate 9999
    Bank.deactivate(9999);
    // activate 1111
    Bank.activate(1111);    

    while(1) {
        cout << "Enter the access code: ";
        cin >> access;
        if (Bank.isactive(access)) {
            cout << "Door is open. Come on in!" << endl;
            break;
        }
        else 
            cout << "Something went wrong" << endl;
    }    

    return 0;
}