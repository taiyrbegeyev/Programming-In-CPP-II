/*
CH08-320143
amap.cpp
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include <iostream>
#include <map>
#include <iterator>
using namespace std;

class Access {
    private:
        std::map <unsigned int, unsigned int> codes;
    public:
        void activate(unsigned int, unsigned int);
        void deactivate(unsigned int);
        bool isactive(unsigned int, unsigned int) const;
};

void Access::activate(unsigned int code, unsigned int level) {
    codes.insert( pair <unsigned int, unsigned int> (level, code) );
}

void Access::deactivate(unsigned int code) {
    codes.erase(code);
}

bool Access::isactive(unsigned int code, unsigned int level) const {
    map <unsigned int, unsigned int>::const_iterator it;
    // iterate through keys and compare keys' codes with entered one
    // if succeed then break the loop
    for (it = codes.begin(); it != codes.end(); it++ ) {
        if (it->second == code) {
            break;
        }
    }

    // if code's security level is greater than entered one
    // then return true 
    if (it->first >= level) {
        return true;
    }
    else {
        return false;
    }
}

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