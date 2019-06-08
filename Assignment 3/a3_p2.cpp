/*
CH08-320143
a3_p2.cpp
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // vector container for strings
    vector <string> words;

    string dummy;
    while (1) {
        getline(cin, dummy);
        if (dummy == "END") 
            break;

        words.push_back(dummy);
    }

    // check whether the second and the fifth
    // element exist and swap them
    int length = words.size();
    if (length >= 5) {
        iter_swap(words.begin() + 2, words.begin() + 5);
    }
    else {
        cerr << "One or the both elements with such indexes doesn't exist" << endl;
    }

    // replace the last element with the string "???"
    if (length != 0)
        words[length - 1] = "???";
    else 
        cerr << "There are no elements" << endl;

    // print the strings on the standart output separated by comma
    // using the index operator
    for (int i = 0; i < length; i++) {
        if (i != length - 1)
            cout << words[i] << ", ";
        else 
            cout << words[i];
    }
    cout << endl;

    // print the strings on the standart output separated by semicolon
    // using a correspnoding operator
    vector<string>::const_iterator pos;
    for (pos = words.begin(); pos != words.end(); pos++) {
        if (pos < words.end() - 1)
            cout << *pos << "; ";
        else 
            cout << *pos;
    }
    cout << endl;

    // print the strings on the standart output in the reversed order
    // separated by space using an iterator
    for (pos = words.end() - 1; pos != words.begin() - 1; pos--) {
        cout << *pos << " ";
    }
    cout << endl;

    return 0;
}