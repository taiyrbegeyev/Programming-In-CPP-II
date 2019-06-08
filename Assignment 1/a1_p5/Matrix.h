/*
CH08-320143
Matrix.h
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/

#include "Vector.h"
#ifndef _MATRIX_H
#define _MATRIX_H

class Vector;

class Matrix
{
private:
    int x, y;
    double **mat;
public:
    // default constructor
    Matrix();
    //destructor
    ~Matrix();

    // getters
    int getX();
    int getY();
    int getMat(int,int);

    // overloaded operators
    friend std::istream& operator>>(std::istream &in, Matrix&);
    friend std::ostream& operator<<(std::ostream &os, Matrix&);
    Vector operator*(Vector&);
};

#endif