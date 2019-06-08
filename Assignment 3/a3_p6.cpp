/*
CH08-320143
a3_p6.cpp
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
/* Priority Queue */
#include <iostream>
#include <queue>
using namespace std;

class myComparison1 {
    public:
        // overloaded operator
        bool operator() (const int& lhs, const int& rhs) const {
            return lhs < rhs;
        }
};

class myComparison2 {
    public:
        // overloaded operator
        bool operator() (const int& lhs, const int& rhs) const {
            return lhs > rhs;
        }
};

int main() {
    int arr [] = {10, 60, 50, 20};
    // use different comparison classes
    priority_queue <int, vector <int>, myComparison1> myPriorityQueue1(arr, arr + 4);
    priority_queue <int, vector <int>, myComparison1> myPriorityQueue2;
    priority_queue <int, vector <int>, myComparison2> myPriorityQueue3;

    // print the size of the priority queue
    cout << "Size of the container 1: " << myPriorityQueue1.size() << endl;
    cout << "Size of the container 2: " << myPriorityQueue2.size() << endl;
    // add new elements to the priority queue
    myPriorityQueue2.push(110);
    myPriorityQueue2.push(120);
    myPriorityQueue2.push(130);
    myPriorityQueue2.push(140);
    myPriorityQueue2.push(150);
    // pop an element from the priority queue
    myPriorityQueue2.pop();    

    // cout the top priority element of the queue
    cout << "Top 1: " << myPriorityQueue1.top() << endl;
    cout << "Top 2: " << myPriorityQueue2.top() << endl;

    // swap two containers
    cout << "Swapping two containers ..." << endl;
    myPriorityQueue1.swap(myPriorityQueue2);
    
    // add new elements using emplace
    myPriorityQueue3.emplace(1);

    // print containers
    cout << "Container 1: " << endl;
    while (!myPriorityQueue1.empty()) {
        cout << myPriorityQueue1.top() << " ";
        myPriorityQueue1.pop();
    }
    cout << endl;
    cout << "Container 2: " << endl;
    while (!myPriorityQueue2.empty()) {
        cout << myPriorityQueue2.top() << " ";
        myPriorityQueue2.pop();
    }
    cout << endl;
    cout << "Container 3: " << endl;
    while (!myPriorityQueue3.empty()) {
        cout << myPriorityQueue3.top() << " ";
        myPriorityQueue3.pop();
    }
    cout << endl;

    return 0;
}