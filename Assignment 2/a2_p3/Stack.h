/*
CH08-320143
Stack.h
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/

#ifndef _STACK_H
#define _STACK_H
#include <iostream>
using namespace std;

template <class T, int initializeStack = 10>
class Stack {
    private:
        T *data; //data will be stored in an array
        int size; // the size of the array
        int count; // number of elements in the array
    public:
        // default constructor
        Stack();
        // parametrical constructor
        Stack(int);
        // destructor
        ~Stack();
        // copy constructor
        Stack(const Stack&);

        // service methods
        void extend();
        bool push(const T&);
        bool pop(T&);
        T back();
        int getNumEntries();

        // + a2_p3
        void resize(int);
        int getSize();
};

// Implementation

// default constructor
template <class T, int initializeStack>
Stack <T, initializeStack> :: Stack () {
    size = initializeStack;
    data = new T[size];
    count = 0;
} 

// parameterical constructor
template <class T, int initializeStack>
Stack <T, initializeStack> :: Stack (int newSize) {
    size = newSize;
    data = new T[size];
    count = 0;
}

// destructor
template <class T, int initializeStack>
Stack <T, initializeStack> :: ~Stack () {
    delete [] data;
}

// copy constructor
template <class T, int initializeStack>
Stack <T, initializeStack> :: Stack(const Stack <T, initializeStack> &newStack) {
    size = newStack.size;
    data = new T[size];
    count = newStack.count;

    for (int i = 0; i < count; i++) {
        data[i] = newStack.data[i];
    }
}

// extend the current stack
template <class T, int initializeStack>
void Stack <T, initializeStack> :: extend() {
    T *newData = new T[2 * size];
    for (int i = 0; i < size; i++)
        newData[i] = data[i];
    delete[] newData; // release the memory
    size *= 2;
    cout << "The stack is extended by two" << endl;
}

// push the element to the stack
// return true if succeed, otherwise false
template <class T, int initializeStack>
bool Stack<T, initializeStack> :: push(const T& element) {
    if (count >= size) {
        //base case
        cerr << "Stack Overflow" << endl;
        return false;
    }
    else {
        count++;
        data[count] = element;
        cout << "Element " << element <<  " is pushed" << endl;
        return true;
    }
}

// pop the element from the stack
// if it is successful return true, otherwise false
template <class T, int initializeStack>
bool Stack <T, initializeStack> :: pop(T& out) {
    if (count <= 0) {
        cerr << "Stack Underflow" << endl;
        return false;
    }
    else {
        cout << "Element is popped" << endl;
        out = data[count];
        count--;
        return true;
    }
}

// returns the data on the top of the Stack
template <class T, int initializeStack>
T Stack <T, initializeStack> :: back() {
    return data[count];
}

// returns the number of elements in the Stack
template <class T, int initializeStack>
int Stack <T, initializeStack> :: getNumEntries() {
    return count;
}

// resize the stack. If size is smaller than the number of entries
// then the older elements should be lost
template <class T, int initializeStack>
void Stack <T, initializeStack> :: resize(int size) {
    T *newData = new T[size];
    for(int i = 1; i <= min(count, size); i++){
        newData[i] = data[i];
    }
    delete [] data;
    data = newData; //adjust pointers
    this->size = size; // new size
    count = min(count, size);
}

// returns the size of the Stack
template <class T, int initializeStack>
int Stack <T, initializeStack> :: getSize() {
    return size;
}

#endif