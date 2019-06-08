/*
CH08-320143
a2_p1.cpp
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include <iostream>
using namespace std;

class Complex {
	private:
		double re, im;
	public:
		Complex(double re, double im) {
			this->re = re;
			this->im = im;
		}
		Complex& operator=(const Complex o) {
			this->re = o.re;
			this->im = o.im;
			return *this;
		}
		Complex operator+(const Complex o) {
			return Complex(this->re + o.re, this->im + o.im);
		}
		friend ostream& operator<<(ostream &o, Complex c) {
			o << c.re << "+" << c.im << "i" << endl;
			return o;
		}
        int operator==(const Complex& o) {
            if (this->re == o.re && this->im == o.im)
                return 1;
            else
                return 0;
        } 
};

template <typename T>
int array_search(T arr[], int length, T search) {
    for (int i = 0; i < length; i++) {
        if (arr[i] == search) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length1 = 10;
    int search1 = 5;
    cout << array_search<int>(arr1, length1, search1) << endl;

    double arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1};
    int length2 = 10;
    double search2 = 5;
    cout << array_search<double>(arr2, length2, search2) << endl;

    string arr3[] = {"apple", "cherry", "orange"};
    int length3 = 3;
    string search3 = "cherry";
    cout << array_search<string>(arr3, length3, search3) << endl;

    Complex arr4[] = {Complex(1, 2), Complex(3, 4), Complex(-3, -5)};
    int length4 = 3;
    Complex search4(-3, -5); 
    cout << array_search<Complex>(arr4, length4, search4) << endl;

    return 0;
}