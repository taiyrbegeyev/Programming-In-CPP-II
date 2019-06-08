/*
CH08-320143
minheritance.cpp
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/

/* Errors are
  minheritance1.cpp: In function ‘int main()’:
  minheritance1.cpp:43:5: error: request for member ‘print’ is ambiguous
   d.print();
     ^~~~~
  minheritance1.cpp:17:10: note: candidates are: void A::print()
     void print() {
          ^~~~~
  minheritance1.cpp:17:10: note: void A::print()
*/

#include <iostream>
using namespace std;
 
class A {
  int x;
  public:
    void setX(int i) {
      x = i;
    }
    void print() { 
      cout << x << endl; 
    }
};

// initially the problem was here, it was declared as 'public A'
// we need to make it virtual
class B: public virtual A {
  public:
    B() { 
      setX(10); 
    }
};
 
// initially the problem was here, it was declared as 'public A'
// we need to make it virtual
class C: public virtual A  
{
  public:
    C() { 
      setX(20);
    }
};

// The error occured because there was an ambiguity of the 
// print() method. Since class D inherits from B and C and 
// B and C both contain print() method, it doesn't know which method to use. 
// the solution is to create unambiguousness by declaring a base class as virtual
class D: public B, public C {
};
 
int main()
{
  D d;
  d.print();
  return 0;
}
