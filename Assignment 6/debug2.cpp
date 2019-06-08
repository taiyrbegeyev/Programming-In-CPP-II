/*
CH08-320143
debug2.cpp
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
// comments at the bottom
#include <iostream>
#include <sstream>
using namespace std;

void foo(int *array, int n, int *positives) {
	for(int i=0; i<n; i++)
		if (array[i]>0)
			(*positives)++; //fixed
}

class Test {
	private:
		int *a;
		int n;
	public:
		Test() {
			a=NULL;
			n=0;
		}
		Test(int *a, int n) {
			this->n = n;
			if (this->a != NULL) {
				delete this->a;
			}
			this->a = new int[n];
			for(int i=0; i<n; i++)
				this->a[i] = a[i];
		}
		string toString() {
			ostringstream ss;
			ss << "Length: " << n << endl << "Elements: ";
			for(int i=0; i<n; i++)
				ss << a[i] << " ";
			ss << endl;
			return ss.str();
		}
		~Test() {
			delete a;
		}
};

int main() {
	int v[3] = {1, 2, 3};
	int p=0;
	// breakpoint
	foo(v, 3, &p);
	cout << "Amount of positive values in the array=" << p << endl;
	Test arr[5];
	Test *obj1;
	// breakpoint
	obj1=&arr[0]; 
	Test *obj2=new Test(v, 3);
	Test *obj3 = &arr[1];
	cout << obj1->toString();
	cout << obj2->toString();
	cout << obj3->toString();
	// delete obj1;
	delete obj2;
	// delete obj3;
	return 0;
}

/* 
	First, compile the file with followin flags
		g++ -Wall -g -o debug1 debug1.cpp 
	and then run the environment
		gdb ./debug1
	Start debugging. Let's execute the program first
	and see what happens in there
		(gdb) run
	The output is
		Amount of positive values in the array=0
		Length: 0
		Elements: 
		Length: 3
		Elements: 1 2 3 
		Length: 0
		Elements: 
		free(): invalid size
	We can conclude that we have a problem with foo function. 
	Let's put a breakpoint there
	break 51
	run
	step
	step
	p positives
	step
	step
	step
		15	*positives++;
	p positives
	We can see that we there is a difference between intitial address of 
	the pointer and the modified one, because we increase the address,
	not the value. There is a priority for the operators. So it should be
	(*positives)++;

	Then move on the next issue, which is related to the toString() function
	break 58
	run
	(gdb) p arr[0]
	$1 = {a = 0x0, n = 0}
	Since we don't have any parameters passed, the default one is being used. 
	Therefore, a is NULL and number of elements is zero
	step
	step
	(gdb) p n
	$2 = 3
	step 
	step
	step
	step
	(gdb) p a[i]
	$3 = 1
	and so on, it works
	So on line 60  should be like this Test *obj3 = &arr[1];
	and we need to comment out delete command for first and third
	objects, because we have NULL pointers for their a elements.
	But we can't delete NULL pointer 
*/