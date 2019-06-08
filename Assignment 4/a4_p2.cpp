/*
CH08-320143
a4_p2.cpp
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(NULL)));
    set<int> mySet;

    // randomly generate 6 numbers and put them in the set
    // duplicates are not allowed
    while(mySet.size() != 6) {
        mySet.insert(rand() % 49 + 1);
    }

    // sort in the ascending order and print the elements 
    // If you walk through the set from .begin() to .end(), 
    // you will have a sorted list of items.
    
    set<int>::iterator cursor;
    for(cursor = mySet.begin(); cursor != mySet.end(); cursor++)
        cout << *cursor << " ";
    cout << endl;

    return 0;
}