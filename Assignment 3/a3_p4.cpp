/*
CH08-320143
a3_p4.cpp
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
    // create deque which is able to store float
    deque<float> A;

    float num;
    // read floats unless the entered value is 0
    cin >> num;
    while(num != 0) {
        // insert the positive element at the end
        // insert the negative element at the beginning
        (num > 0) ? (A.push_back(num)) : (A.push_front(num));
        cin >> num;
    }

    // print the elements of deque on the stdout using spaces
    deque<float>::iterator it;
    for (it = A.begin(); it != A.end(); it++)
        cout << *it << " ";
    cout << endl;

    // print an empty line
    cout << endl;

    // add the value 0 into the middle (between last negative 
    // and before the first positive)
    it = A.begin();
    while(*it < 0)
        it++;
    
    A.insert(it, 0);

    // print elements of A on the stdout using semicolons
    for (it = A.begin(); it != A.end(); it++) {
        if (it == A.end() - 1)
            cout << *it << endl;
        else
            cout << *it << "; ";
    }

    return 0;
}