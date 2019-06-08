/*
CH08-320143
a3_p3.cpp
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include <iostream>
#include <list>
#include <iterator>
#include <fstream>
#include <cassert>
#include <algorithm>
using namespace std;

int main() {
    // create two lists
    list<int> A, B;

    // read integers from the keyboard until 
    // the entered integer is negative or zero
    int num;
    cin >> num;
    while(num > 0) {
        // insert the number into list A by adding to the end
        A.insert(A.end(), num);
        // insert the same number into list B by adding to the beginning
        B.insert(B.begin(), num);
        cin >> num;
    }

    // print list A separated by spaces on the standart output 
    // and print list B into a file "listB.txt"
    list<int>::iterator it;
    for (it = A.begin(); it != A.end(); it++) 
        cout << *it << " ";
    cout << endl;
    // open the file
    ofstream out;
    out.open("listB.txt", ios::out | ios::trunc);
    assert(out.is_open());
    for (it = B.begin(); it != B.end(); it++) {
        out << *it << " ";
    }
    // close the file
    out.close();

    // print an empty line
    cout << endl;

    // move the first element of the lists to the end (for both)
    it = A.begin();
    A.insert(A.end(), *it);
    A.pop_front();

    it = B.begin();
    B.insert(B.end(), *it);
    B.pop_front(); 

    // A.splice(A.end(), A, A.begin());
    // B.splice(B.end(), B, B.begin());

    // print list A and list B on the standart output (both separated
    // by comma) using an iterator
    list<int>::iterator copyit = A.end(); // initialize new iterator 
    copyit--; // decrement it to get the last element of the list
    for (it = A.begin(); it != copyit; it++) {
        // exclude the last element
        cout << *it << ", ";
    }
    cout << *it << endl; //print the last element of the list 

    copyit = B.end(); // initialize new iterator 
    copyit--; // decrement it to get the last element of the list
    for (it = B.begin(); it != copyit; it++) {
        // exclude the last element
        cout << *it << ", ";
    }
    cout << *it << endl; //print the last element of the list
    // print an empty line
    cout << endl;

    // Merge list A and B
    list<int> C; // create a new list, which will be the result of merge
    A.sort();
    B.sort();
    set_union(A.begin(), A.end(),
              B.begin(), B.end(),
              inserter(C, C.begin())); 

    // print the  result of merging
    for (it = C.begin(); it != C.end(); it++) 
        cout << *it << " ";
    cout << endl;

    return 0;
}