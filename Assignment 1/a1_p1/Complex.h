/*
CH08-320143
Complex.h
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include <fstream>

class Complex {
    private:
        double real;
        double imaginary;
    public:
        // default constructor
        Complex();
        // constructor for setting real and imaginary
        Complex(double, double);
        // copy constructor
        Complex(Complex&);
        // destructor
        ~Complex();

        // setter methods
        void setReal(double newreal);
        void setImaginary(double newimaginary);

        // getter methods
        double getReal();
        double getImaginary();

        // service method
        void print();

        // operators overloading
        Complex operator+(const Complex&);
        Complex operator-(const Complex&);
        Complex operator*(const Complex&);
        Complex& operator=(const Complex&);
        friend std::ostream& operator<<(std::ostream&, const Complex&);
        friend std::istream& operator>>(std::istream&, Complex&);
};