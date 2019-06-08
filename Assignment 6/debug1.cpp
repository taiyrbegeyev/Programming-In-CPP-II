/*
CH08-320143
debug1.cpp
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
// comments at the bottom
#include <iostream>
using namespace std;

int sum(int a[], int nr) {
	// breakpoint
	int s = 0;
	for(int i = 0; i < nr; i++)
		s += a[i];
	return s;
}

int difference(int a, int b) {
	// breakpoint
	if (a - b < 0)
		return b - a;
	else
		return a - b;
}

int main() {
	int n;
	// breakpoint 
	cout << "n = ";
	cin >> n;

	int v[n];
	cout << "Enter values for the array" << endl;

	for(int i = 0; i < n; i++)
		cin >> v[i];
	int result = sum(v, n);

	cout << "Result=" << result << endl;
	int x, y;
	cout << "x=";
	cin >> x;
	cout << "y=";
	cin >> y;
	cout << "Difference=" << difference(x, y) << endl;

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
	Once we tested it, we can observe that it computes the sum
	of elements of the array wrong and it calculates the difference
	between two numbers incorrectly

	Let's check the loop for entering the values of the array
	Add breakpoints
	break 28
	(gdb) run and then (gdb) continue 
	We can infer that enter process is correct

	That means that there are problems with the functions which are 
	responsible for calculating 
	Let' add breakpoints before functions
	break 12
	For example, we entered two values: 5 and 6
	(gdb) run 
	(gdb) next
	(gdb) next
	(gdb) p i 
		i = 0
	(gdb) next
	(gdb) next
		i = 1
	(gdb) next
	(gdb) next
		i = 2
	(gdb) next
	(gdb) next
	(gdb) p s 
		s = some random value
	So we execute our loop one more time. So we get access to the number 
	which is not in our array. So it should go from 0 till nr exclusively

	Next break point 
	break 19
	If we enter 1 and 2, then
	next
	p a-b
		shows 1
	which is not correct
	next
	shows some random number
	We just need to get rid of unsigned
	Because we have int in main, so if enter negative numbers in the function,
	then it transforms it to smth different
*/