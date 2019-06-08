/*
CH08-320143
a3_p1.cpp
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
        cin >> dummy;
        if (dummy == "END") 
            break;

        words.push_back(dummy);
    }

    // print the words on the standart output separated by spaces
    // using the index operator
    int length = words.size();
    for (int i = 0; i < length; i++) {
        cout << words[i] << " ";
    }
    cout << endl;

    // print the words on the standart output separated by comma
    // using a corresponding iterator
    vector<string>::const_iterator pos;
    for(pos = words.begin(); pos != words.end(); pos++) {
        if (pos < words.end() - 1)
            cout << *pos << ", ";
        else 
            cout << *pos;
    }
    cout << endl;
    return 0;
}