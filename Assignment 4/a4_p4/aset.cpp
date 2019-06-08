/*
CH08-320143
aset.cpp
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include <iostream>
#include <set>
using namespace std;

class Access {
    private:
        std::set <unsigned int> codes;
    public:
        void activate(unsigned int);
        void deactivate(unsigned int);
        bool isactive(unsigned int) const;
};

void Access::activate(unsigned int code) {
    codes.insert(code);
}

void Access::deactivate(unsigned int code) {
    auto dummy = codes.find(code);
    // if exists erase it
    if (isactive(code)) 
        codes.erase(dummy);
    else 
        cout << "Code is not found" << endl;
}

bool Access::isactive(unsigned int code) const {
    auto dummy = codes.find(code);
    // ternary operator
    return (dummy != codes.end()) ? (1) : (0);
}

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