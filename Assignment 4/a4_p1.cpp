/*
CH08-320143
a4_p1.cpp
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
    vector<int> arr;
    // fill a vector with the integer values from 1 to 30
    for(int i = 0; i < 30; i++) {
        arr.push_back(i + 1);
    }
    // then add value 5 at the end of the vector
    arr.push_back(5);
    // reverse it
    reverse(arr.begin(), arr.end());

    // use an iterator to print the content of the vector
    vector<int>::iterator cursor;
    for(cursor = arr.begin(); cursor != arr.end(); cursor++)
        cout << *cursor << " ";
    cout << endl;

    // replace all occurrences of the value 5 by the value 129
    replace(arr.begin(), arr.end(), 5, 129);

    // print the modified vector again
    for(cursor = arr.begin(); cursor != arr.end(); cursor++)
        cout << *cursor << " ";
    cout << endl;

    return 0;
}