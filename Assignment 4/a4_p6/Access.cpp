/*
CH08-320143
Access.cpp
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include "Access.h"
#include <iostream>
#include <map>
#include <iterator>
using namespace std;

void Access::activate(unsigned int code, unsigned int level) {
    codes.insert( pair <unsigned int, unsigned int> (level, code) );
}

void Access::deactivate(unsigned int code) {
    codes.erase(code);
}

bool Access::isactive(unsigned int code, unsigned int level) const {
    map <unsigned int, unsigned int>::const_iterator it;
    for (it = codes.begin(); it != codes.end(); it++ ) {
        if (it->second == code) {
            break;
        }
    }

    if (it->first >= level) {
        return true;
    }
    else {
        return false;
    }
}