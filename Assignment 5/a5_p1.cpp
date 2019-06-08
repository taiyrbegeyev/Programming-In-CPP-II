/*
CH08-320143
a5_p1.cpp
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // create a vector of integers
    vector <int> arr;
    // add the value 8, 20 times
    for (int i = 0; i < 20; i++) 
        arr.push_back(8);

    // try and catch block
    try
    {
        cout << arr.at(20) << endl;
    }
    catch(const out_of_range& e)
    {
        cerr << "Out of Range Error: " << e.what() << endl;
    }
    

    return 0;
}