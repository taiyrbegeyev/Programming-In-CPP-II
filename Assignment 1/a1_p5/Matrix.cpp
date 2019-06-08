/*
CH08-320143
Matrix.cpp
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include <bits/stdc++.h>
#include "Vector.h"
#include "Matrix.h"

using namespace std;

//default constructor
Matrix::Matrix()
{
    x = 0;
    y = 0;
}

Matrix::~Matrix()
{
    for(int i = 0; i < x; i++)
    {
        delete [] mat[i];
    }
    delete [] mat;
}

int Matrix::getX()
{
    return this->x;
}

int Matrix::getY()
{
    return this->y;
}

int Matrix::getMat(int a, int b)
{
    return this->mat[a][b];
}

istream& operator>>(istream &in, Matrix &a)
{
    in >> a.x;
    in >> a.y;
    a.mat = new double*[a.x];
    for(int i = 0; i < a.x; i++)
    {
        a.mat[i] = new double[a.y];
    }
    for(int i = 0; i < a.x; i++)
    {
        for(int j = 0; j < a.y; j++)
        {
            in >> a.mat[i][j];
        }
    }
    return in;
}

ostream& operator<<(ostream &os, Matrix &a)
{
    for(int i = 0; i < a.x; i++)
    {
        for(int j = 0; j < a.y; j++)
        {
            os << a.mat[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

///Here I am taking as the vector is a column vector
Vector Matrix::operator*(Vector &a)
{
    if(this->y == a.getN())
    {
        double *vec = new double[this->x];
        for(int i = 0; i < this->x; i++)
        {
            vec[i] = 0;
            for(int j = 0; j < this->y; j++)
            {
                vec[i] += a.getV(j) * this->mat[i][j];
            }
        }
        return Vector(vec,this->x);
    }
    else
    {
        return Vector();
    }
}