/*
CH08-320143
LinkedList.h
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/

#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include <iostream>
using namespace std;

template <class T>
class Node {
    public:
        T info;
        Node *next;
        Node *prev;
    public:
        Node();
        Node(const T& el, Node *n = NULL, Node *p = NULL);
};

template <class T>
class DLL {
    public:
        Node <T> *head;
        Node <T> *tail;
        int items;
    public:
        DLL();
        DLL(Node <T> *, Node <T> *, int);
        ~DLL();

        // service methods
        void push_front(const T&);
        void push_back(const T&);
        T pop_front();
        T pop_back();
        T front() const;
        T back() const;
        int amountOfElements() const;
        void printDLL() const;
};

// Implementation of the Node
template <class T>
Node <T> :: Node() {
    next = prev = NULL;
}

template <class T>
Node <T> :: Node(const T& el, Node *n, Node *p) {
    info = el;
    next = n;
    prev = p;
} 

// Implementation of the Doubly Linked List
template <class T>
DLL <T> :: DLL() {
    tail = head = NULL;
    items = 0;
}

// constructor
template <class T>
DLL <T> :: DLL(Node <T> *front, Node <T> *rear, int items) {
    head = front;
    tail = rear;
    this->items = items;
}

// destructor
template <class T>
DLL <T> :: ~DLL() {
    Node <T> *p;
    while (head != NULL) {
        p = head->next;
        delete head;
        head = p;
    }
}

// push the number to the front
template <class T>
void DLL <T> :: push_front(const T& el) {
    if (items != 0) {
        head = new Node <T> (el, head, NULL);
        head->next->prev = head;
    }
    else {
        head = tail = new Node <T> (el);
    }
    items++;
}

// push the number to the back
template <class T>
void DLL <T> :: push_back(const T& el) {
    if (items != 0) {
        tail = new Node <T> (el, NULL, tail);
        tail->prev->next = tail;
    }
    else {
        head = tail = new Node <T> (el);
    }
    items++;
}

// pop the number at the front and return it
template <class T>
T DLL <T> :: pop_front() {
    if (items == 1) {
        T num;
        num = head->info;

        delete head;
        head = tail = NULL;
        items--;

        return num;
    }
    else if (items != 0) {
        T num;
        num = head->info;

        Node <T> *p;
        p = head->next;
        delete head;
        head = p;
        items--;
        
        return num;
    }
    else {
        cerr << "Stack Underflow" << endl;
        return -1;
    }
}

// pop the number at the back and return it
template <class T>
T DLL <T> :: pop_back() {
    if (items == 1) {
        T num;
        num = tail->info;

        delete tail;
        head = tail = NULL;
        items--;

        return num;
    }
    else if (items != 0) {
        T num;
        num = tail->info;

        tail = tail->prev;
        delete tail->next;
        tail->next = NULL;
        items--;

        return num;
    }
    else {
        cerr << "Stack Underflow" << endl;
        return -1;
    }
}

// get the element at the front
template <class T>
T DLL <T> :: front() const {
    return head->info;
}

// get the element at the back
template <class T>
T DLL <T> :: back() const {
    return tail->info;
}

// get the number of elements in the DLL
template <class T>
int DLL <T> :: amountOfElements() const {
    return items;
}

// print the elements of the DLL
template <class T>
void DLL <T> :: printDLL() const {
    Node <T> *p;
    cout << "All elements: ";
    for (p = head; p; p = p->next) {
        cout << p->info << " ";
    }
    cout << endl;
}

#endif
