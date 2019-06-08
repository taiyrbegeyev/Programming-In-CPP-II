/*
CH08-320143
Fraction.cpp
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include <iostream>
#include "Fraction.h"
using namespace std;

// default constructor
Fraction::Fraction() {
    numerator = 1;
    denominator = 1;
}

// parametric constructors
Fraction::Fraction(int a, int b) {
    if (b == 0)
        throw "Invalid data or logical error"; // exception

    int tmp_gcd = gcd(abs(a), abs(b));
    numerator = a / tmp_gcd;
    denominator = b / tmp_gcd;

    // if both are negative, then make them positive
    if (numerator < 0 && denominator < 0) { 
        numerator = abs(numerator);
        denominator = abs(denominator);
    }
}

Fraction::Fraction(string s) {
    int length = s.length();
    // find the position of the /
    int pos = s.find("/");
    // base case
    // if it is not found
    if (pos == -1)
        throw "Invalid data or logical error"; // exception

    // extract numerator, lefthand side from /
    string num1 = s.substr(0, pos); 
    // extract denominator, righthand side from /
    string num2 = s.substr(pos + 1, length - pos - 1); 
    // base case
    // if we don't have anything between sign and /  or  after the second sign
    if (num1.length() < 1 || num2.length() < 1)
        throw "Invalid data or logical error"; // exception

    // extract signs
    char sign1 = s[0];
    char sign2 = s[pos + 1];

    // check if there are signs in front of the numbers
    if (sign1 == '+' || sign1 == '-') {
        num1.erase(0, 1); // remove sign from the string
    }
    if (sign2 == '+' || sign2 == '-') {
        num2.erase(0, 1); // remove sign from the string
    }

    pos = s.find("/");

    // check whether there is a number for numerator
    bool isNumber = true;
    int lengthOfNum1 = num1.length();
    for (int i = 0; i < lengthOfNum1; i++) {
        if (!isdigit(num1[i])) {
            isNumber = false;
            break;
        }
    }
    // if it is, then convert it to int
    if (isNumber && lengthOfNum1 > 0)
        numerator = stoi(num1); // string to int
    else 
        throw "Invalid data or logical error"; // exception 
    
    // check whether there is a number for denominator
    isNumber = true;
    int lengthOfNum2 = num2.length();
    for (int i = 0; i < lengthOfNum2; i++) {
        if (!isdigit(num2[i])) {
            isNumber = false;
            break;
        }
    }
    // if it is, then convert it to int
    if (isNumber && lengthOfNum2 > 0)
        denominator = stoi(num2); // string to int
    else 
        throw "Invalid data or logical error"; // exception

    if (denominator != 0) {    
        if (sign1 == '-')
            numerator = -numerator;
        if (sign2 == '-')
            denominator = -denominator; 
    
        // use greatest common divisor function to reduce fraction
        int tmp_gcd = gcd(abs(numerator), abs(denominator));
        numerator /= tmp_gcd;
        denominator /= tmp_gcd;
    
        // if both are negative, then make them positive
        if (numerator < 0 && denominator < 0) { 
            numerator = abs(numerator);
            denominator = abs(denominator);
        }
    }
    else
        throw "Invalid data or logical error"; // exception
}

// copy constructor
Fraction::Fraction(const Fraction& myFraction) {
    numerator = myFraction.numerator;
    denominator = myFraction.denominator;
}

// destructor
Fraction::~Fraction() {}

/* Operator overloading */

// relational operators
bool Fraction::operator<(const Fraction& myFraction) {
    return this->numerator * myFraction.denominator 
        < myFraction.numerator * this->denominator;
}

bool Fraction::operator<=(const Fraction& myFraction) {
    return this->numerator * myFraction.denominator 
        <= myFraction.numerator * this->denominator;
}

bool Fraction::operator>(const Fraction& myFraction) {
    return this->numerator * myFraction.denominator 
        > myFraction.numerator * this->denominator;
}

bool Fraction::operator>=(const Fraction& myFraction) {
    return this->numerator * myFraction.denominator 
        >= myFraction.numerator * this->denominator;
}

bool Fraction::operator==(const Fraction& myFraction) {
    return this->numerator * myFraction.denominator 
        == myFraction.numerator * this->denominator;
}

bool Fraction::operator!=(const Fraction& myFraction) {
    return this->numerator * myFraction.denominator 
        != myFraction.numerator * this->denominator;
}

// arithmetic operators
Fraction Fraction::operator+(const Fraction& myFraction) {
    Fraction temp;
	temp.numerator = 
        (this->numerator * (lcm(this->denominator, myFraction.denominator) /
        this->denominator)) + (myFraction.numerator * 
        (lcm(this->denominator, myFraction.denominator) / 
        myFraction.denominator));

	temp.denominator = lcm(this->denominator, myFraction.denominator);
	return temp;
}

Fraction Fraction::operator-(const Fraction& myFraction) {
    Fraction temp;
	temp.numerator = 
        (this->numerator * (lcm(this->denominator, myFraction.denominator) /
        this->denominator)) - (myFraction.numerator * 
        (lcm(this->denominator, myFraction.denominator) / 
        myFraction.denominator));

	temp.denominator = lcm(this->denominator, myFraction.denominator);
	return temp;
}

Fraction Fraction::operator*(const Fraction& myFraction)
{
	Fraction temp;
	temp.numerator = this->numerator * myFraction.numerator;
	temp.denominator = this->denominator * myFraction.denominator;
	return temp;
}

Fraction Fraction::operator/(const Fraction& myFraction)
{
	Fraction temp;
	temp.numerator = this->numerator * myFraction.denominator;
	temp.denominator = this->denominator * myFraction.numerator;
	return temp;
}

// I/O operators
ostream& operator<<(ostream& out, const Fraction& myFraction) {
    if (myFraction.denominator == 1)
        out << myFraction.numerator << endl;     
    else 
        out << myFraction.numerator << "/" << myFraction.denominator << endl;
    return out;
}
    
istream& operator>>(istream& in, Fraction& myFraction) {
    in >> myFraction.numerator;
    in >> myFraction.denominator;

    //checking the validity of the input
	if(myFraction.denominator == 0)
	{
        throw "Invalid data or logical error"; // exception
        myFraction.denominator = 1;
		return in;
	}
	else
	{
		return in;
	}
}

// assignment
void Fraction::operator=(const Fraction& myFraction)
{
	this->numerator = myFraction.numerator;
	this->denominator = myFraction.denominator;
}

// other methods

int Fraction::gcd(int a, int b)
{
	int tmp_gcd = 1;

	// Implement GCD of two numbers;
	for (int i = 1; i <= a && i <= b; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            tmp_gcd = i;
        }
    }

	return tmp_gcd;
}

int Fraction::lcm(int a, int b)
{
	return a * b / gcd(a, b);
}