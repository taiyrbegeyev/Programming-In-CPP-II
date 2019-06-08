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
    Bank.activate(1234, 1);
    Bank.activate(9999, 5);
    Bank.activate(9876, 9);

    // ask the user for an access code
    unsigned int access;
    
    while(1) {
        cout << "Enter the access code: ";
        cin >> access;
        if (Bank.isactive(access, 5)) {
            cout << "Door is open. Come on in!" << endl;
            break;
        }
        else 
            cout << "Something went wrong" << endl;
    }
    // change the access level
    Bank.activate(9999, 8);
    //deactivate the code that worked
    Bank.deactivate(access);
    // activate 1111 
    Bank.activate(1111, 7);    

    while(1) {
        cout << "Enter the access code: ";
        cin >> access;
        if (Bank.isactive(access, 7)) {
            cout << "Door is open. Come on in!" << endl;
            break;
        }
        else 
            cout << "Something went wrong" << endl;
    }    

    return 0;
}