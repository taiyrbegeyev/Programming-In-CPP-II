/*
CH08-320143
Vector.h
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/

#ifndef _VECTOR_H
#define _VECTOR_H

#include <bits/stdc++.h>
#include "Matrix.h"

class Vector {
    private:
        int size;
        double *vector;
    public:
        // default constructor
        Vector();
        // parametrical constructor
        Vector(double* , int);
        // copy constructor
        Vector(const Vector&);
        //destructor
        ~Vector();

        // getters and setters
        void setV(double*);
        void setN(int);
        int getN();
        double getV(int); 

        // service methods
        void print();
        Vector add(const Vector&);
        double norm();
        Vector diff(const Vector&);
        Vector pro(const Vector&);
        Vector operator*(Matrix&);

        // overloaded operators
        friend std::istream& operator>>(std::istream &in, Vector &);
        friend std::ostream& operator<<(std::ostream &os, const Vector&);
};

#endif