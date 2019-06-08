/*
CH08-320143
a4_p5.cpp
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include <map>
#include <iterator>
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

int main() {
    // open the file for a reading
    ifstream in;
    in.open("data.txt", ios::in);
    assert(in.is_open());

    // create a map
    map <string, string> birthdays;

    string str1, str2;
    int lineCounter = 1;

    // read until the end of the file
    while(!in.eof()) {
        if (lineCounter == 2) {
            // read birtday
            getline(in, str2);
            birthdays.insert(pair <string, string> (str1, str2) );
            str1.erase(str1.begin(), str1.end());
            str2.erase(str2.begin(), str2.end());
            lineCounter = 0;
        }
        else {
            // read name
            getline(in, str1);
        }
        lineCounter++;
    }
    
    // simulate querying
    // ask for a name from the keyboard and print corresponding birthday
    // if name is not in the container then print "Name not found!"
    string name;
    cout << "Enter the name: ";
    getline(cin, name);

    map <string, string>::iterator it;
    it = birthdays.find(name);

    if (it != birthdays.end())
        cout << birthdays[name] << endl;
    else
        cout << "Name is not found" << endl; 

    in.close();
    return 0;
}