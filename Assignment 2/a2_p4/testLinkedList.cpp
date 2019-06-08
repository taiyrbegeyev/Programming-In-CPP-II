/*
CH08-320143
testLinkedList.cpp
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include "LinkedList.h"
#include <iostream>
using namespace std;

int main() {
    DLL <int> myDLL;
    myDLL.push_front(5);
    myDLL.push_back(6);
    myDLL.push_back(7);
    myDLL.push_front(4);
    cout << "Number of elements: " << myDLL.amountOfElements() << endl;
    cout << "Front element: " << myDLL.front() << endl;
    cout << "Rear element: " << myDLL.back() << endl;

    myDLL.printDLL();

    cout << "Popped at the front number: " << myDLL.pop_front() << endl;
    cout << "Popped at the end number: " << myDLL.pop_back() << endl;

    myDLL.printDLL();

    cout << "Popped at the front number: " << myDLL.pop_front() << endl;
    cout << "Popped at the end number: " << myDLL.pop_back() << endl;

    myDLL.printDLL();
    cout << "Number of elements: " << myDLL.amountOfElements() << endl;

    // check for Underflow
    myDLL.pop_front();

    return 0;
}