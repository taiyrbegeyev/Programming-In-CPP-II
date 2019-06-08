/*
CH08-320143
Fraction.h
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#ifndef _FRACTION_H
#define _FRACTION_H
#include <iostream>

// class for working with rational numbers
class Fraction {
    private:
        int numerator;
        int denominator;
    public:
        // default constructor
        Fraction();
        // constructors
        Fraction(int, int);
        Fraction(std::string);
        // copy constructor
        Fraction(const Fraction&);
        // destructor
        ~Fraction();
        /* operator overloading */

        //relational operators 
        bool operator<(const Fraction&);
        bool operator<=(const Fraction&);
        bool operator>(const Fraction&);
        bool operator>=(const Fraction&);
        bool operator==(const Fraction&);
        bool operator!=(const Fraction&);

        // arithmetic operators
        Fraction operator+(const Fraction&);
        Fraction operator-(const Fraction&);
        Fraction operator*(const Fraction&);
        Fraction operator/(const Fraction&);

        // I/O operators
        friend std::ostream& operator<<(std::ostream&, Fraction&);
        friend std::istream& operator>>(std::istream&, Fraction&);

        // assignment
        void operator=(const Fraction&);

        // other methods
};

int gcd(int, int);
int lcm(int, int);

#endif