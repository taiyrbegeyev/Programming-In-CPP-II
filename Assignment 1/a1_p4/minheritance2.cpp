/*
CH08-320143
minheritance2.cpp
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/

#include <iostream>
using namespace std;

/* Errors are
  In function ‘int main()’:
    error: use of deleted function ‘D::D()’
     D d;
       ^
    error: no matching function for call to ‘A::A()’

*/
 
class A {
  int x;
  public:
    A(int i) { 
      x = i; 
    }
    void print() { 
      cout << x;
    }
};

// instead of virtual public write public virtual 
class B: public virtual A {
  public:
    B() : A(10) {  }
};
 
// instead of virtual public write public virtual
class C: public virtual A {
  public:
    C() : A(10) {  }
};
 
// since we create unambigioness by declaring a base class
// as virtual, we need to specify all constructors "above". Also
// there is no direct connection between base class A and D 
class D: public B, public C {
  public:
    D(): A(20), B(), C() {}
};
 
int main()
{
  D d;
  d.print();
  return 0;
}
