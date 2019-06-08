/*
CH08-320143
Access.cpp
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include "Access.h"
#include <iostream>
#include <set>
using namespace std;

void Access::activate(unsigned int code) {
    codes.insert(code);
}

void Access::deactivate(unsigned int code) {
    auto dummy = codes.find(code);
    if (isactive(code)) 
        codes.erase(dummy);
    else 
        cout << "Code is not found" << endl;
}

bool Access::isactive(unsigned int code) const {
    auto dummy = codes.find(code);
    return (dummy != codes.end()) ? (1) : (0);
}