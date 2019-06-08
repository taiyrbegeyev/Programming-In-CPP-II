/*
CH08-320143
Complex.cpp
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/

#include "Complex.h"
#include <iostream>
#include <fstream>
using namespace std;

// default constructor
Complex::Complex() {
    real = imaginary = 0;
}

// constructor for setting real and imaginary
Complex::Complex(double newreal, double newimaginary) {
    real = newreal;
    imaginary = newimaginary;
}

// copy constructor
Complex::Complex(Complex &src) {
    real = src.real;
    imaginary = src.imaginary;
}

// destructor
Complex::~Complex() {}

//setter methods
void Complex::setReal(double newreal)
{
    real = newreal;
}

void Complex::setImaginary(double newimaginary)
{
    imaginary = newimaginary;
}

//getter methods
double Complex::getReal()
{
    return real;
}

double Complex::getImaginary()
{
    return imaginary;
}

//service method
void Complex::print()
{
    if (imaginary > 0)
        cout << real << "+" << imaginary << "i" << endl;
    else if (imaginary < 0)
        cout << real << imaginary << "i" << endl;
    else
        cout << real << endl;
}

// overloaded operator +
Complex Complex::operator+(const Complex& complex) {
    Complex temp;
    temp.real = this->real + complex.real;
    temp.imaginary = this->imaginary + complex.imaginary;
    return temp;
}

// overloaded operator -
Complex Complex::operator-(const Complex& complex) {
    Complex temp;
    temp.real = this->real - complex.real;
    temp.imaginary = this->imaginary - complex.imaginary;
    return temp;
}

// overloaded operator *
Complex Complex::operator*(const Complex& complex) {
    Complex temp;
    temp.real = this->real * complex.real - this->imaginary * complex.imaginary;
    temp.imaginary = this->imaginary * complex.real + this->real * complex.imaginary;
    return temp;
}

// overloaded operator =
Complex& Complex::operator=(const Complex& complex) {
    this->real = complex.real;
    this->imaginary = complex.imaginary;
    return *this;
}

ostream& operator<<(ostream& o, const Complex& complex) {
    if (complex.imaginary > 0)
        o << complex.real << "+" << complex.imaginary << "i" << endl;
    else if (complex.imaginary < 0)
        o << complex.real << complex.imaginary << "i" << endl;
    else
        o << complex.real << endl;
    return o;
}

istream& operator>>(istream& i, Complex& complex) {
    i >> complex.real; 
    i >> complex.imaginary;
    return i;
}