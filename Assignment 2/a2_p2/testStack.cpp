/*
CH08-320143
testStack.cpp
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include "Stack.h"
#include <iostream>
using namespace std;

int main() {
    // check different type for the Stack
    Stack <int, 3> myStack1; // declaring size using template
    Stack <float, 4> myStack2; // declaring size using template
    Stack <double> myStack3(5); // declaring size constructor
    Stack <char> myStack4(6); // declaring size using constructor

    // declaring size using template, but not specifying it
    // by default is 10
    Stack <string> myStack5;  

    // as you can see Stack works with different types
    // so we will just show for int

    // check push and the base case for overflowing Stack
    myStack1.push(1);
    myStack1.push(2);
    myStack1.push(3);
    // should throw an error  - Stack Overflow
    myStack1.push(4);

    myStack1.extend();
    cout << "Number of elements: " << myStack1.getNumEntries() << endl;;
    cout << "The top element on the Stack: " <<  myStack1.back() << endl;

    // try to push it again after extending Stack
    myStack1.push(4);
    cout << "Number of elements: " << myStack1.getNumEntries() << endl;;
    cout << "The top element on the Stack: " <<  myStack1.back() << endl;

    // check pop and the base case for underflowing Stack

    int dummy;
    myStack1.pop(dummy);
    myStack1.pop(dummy);
    myStack1.pop(dummy);
    myStack1.pop(dummy);
    // should throw an error  - Stack Underflow
    myStack1.pop(dummy);

    return 0;
}