/*
CH08-320143
a4_p3.cpp
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

void printSet(set<int> mySet) {
    for (auto it = mySet.begin(); it != mySet.end(); it++)
        cout << *it << " ";
    cout << endl;
}

void printMultiSet(multiset<int> myMSet) {
    for (auto it = myMSet.begin(); it != myMSet.end(); it++)
        cout << *it << " ";
    cout << endl;
}

int main() {
    // create a set A and a multiset B to store integers
    set <int> A;
    multiset <int> B;
    
    // read numbers as long as the num is not negative
    int num;
    cin >> num;
    while (num > 0) {
        // insert the num into set A
        A.insert(num);
        // insert the num into set B
        B.insert(num);
        cin >> num;
    }

    // print set A and multiset B on the stdout using spaces
    // with an empty line between A and B
    printSet(A);
    cout << endl;
    printMultiSet(B);

    // print an empty line
    cout << endl;

    // remove all elements with value 5 from both A and B
    for (auto it = A.begin(); it != A.end(); it++) {
        auto element5 = A.find(5);
        if (element5 != A.end())
            A.erase(element5);
    }

    for (auto it = B.begin(); it != B.end(); it++) {
        auto element5 = B.find(5);
        if (element5 != B.end())
        B.erase(element5);
    }

    // print set A and multiset B on the stdout using spaces
    // with an empty line between A and B as well as after B
    printSet(A);
    cout << endl;
    printMultiSet(B);
    cout << endl;

    // add values 14 and 198 to the set A
    A.insert(14);
    A.insert(198);

    // determine and print the union of A and B using spaces
    multiset <int> unionAandB; // result
    set_union(A.begin(), A.end(), B.begin(), B.end(),
            inserter(unionAandB, unionAandB.begin()));
    printMultiSet(unionAandB);

    // determine and print the intersection of A and B using spaces
    set <int> intersectionAandB; 
    set_intersection(A.begin(), A.end(), B.begin(), B.end(),
            inserter(intersectionAandB, intersectionAandB.begin()));
    printSet(intersectionAandB);

    // determine and print the difference between A and B 
    set <int> differenceAandB;
    set_difference(A.begin(), A.end(), B.begin(), B.end(),
                inserter(differenceAandB, differenceAandB.begin()));
    printSet(differenceAandB);

    // determine and print the symmetric difference between A and B
    set <int> symmetricDifferenceAandB;
    set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(),
                inserter(symmetricDifferenceAandB, symmetricDifferenceAandB.begin()));
    printSet(symmetricDifferenceAandB);

    return 0;
}
