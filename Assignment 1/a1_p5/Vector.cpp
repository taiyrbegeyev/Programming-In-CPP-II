/*
CH08-320143
Vector.cpp
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/

#include <bits/stdc++.h>
#include "Vector.h"
#include "Matrix.h"
using namespace std;

//default constructor
Vector::Vector()
{
    size = 0;
    vector = 0;
}

//constructor
void Vector::setN(int newNum)
{
    size = newNum;
}

//constructor
Vector::Vector(double *x, int newNum)
{
    vector = new double[newNum];
    size = newNum;
    for(int i = 0; i < newNum; i++)
    {
        vector[i] = x[i];
    }
}

// copy constructor
Vector::Vector(const Vector& x)
{
    size = x.size;
    vector = new double[x.size];
    for(int i = 0; i < size; i++)
    {
        vector[i] = x.vector[i];
    }
}

// destructor
Vector::~Vector()
{
    delete [] vector;
}

void Vector::print()
{
    cout << "vector = [";
    for (int i = 0; i < size; i++)
    {
        cout << vector[i] << " ";
    }
    cout << "]" << endl;
}

void Vector::setV(double *x)
{
    vector = new double[size];
    for(int i = 0; i < size; i++)
    {
        vector[i] = x[i];
    }
}

int Vector::getN()
{
    return size;
}

double Vector::getV(int n)
{
    return vector[n];
}

Vector Vector::add(const Vector &newvector)
{
    //creating new object in order to return it
    Vector vector_temp;
    vector_temp.setN(this->size);
    //till the end of the array adding two vectors
    for (int i = 0; i < this->size; i++)
        vector_temp.vector[i] = this->vector[i] + newvector.vector[i];

    //since Vector constructor has two arguments, we need to include
    //the size of the vector as well
    vector_temp = Vector(vector_temp.vector, this -> size);
    return vector_temp;
}

double Vector::norm()
{
    double norm, sum = 0;

    //finding the sum of coordinates of vector
    for (int i = 0; i < size; i++)
        sum += (vector[i] * vector[i]);

    //using function from cmath library
    norm = sqrt(sum);

    return norm;
}

Vector Vector::diff(const Vector &newvector)
{
    //creating new object in order to return it
    Vector vector_temp;
    vector_temp.setN(this->size);

    //till the end of the array substracting two vectors
    for (int i = 0; i < this->size; i++)
        vector_temp.vector[i] = this->vector[i] - newvector.vector[i];

    //since Vector constructor has two arguments, we need to include
    //the size of the vector as well
    vector_temp = Vector(vector_temp.vector, this -> size);
    return vector_temp;
}

Vector Vector::pro(const Vector &newvector)
{
    //creating new object in order to return it
    Vector vector_temp;
    vector_temp.setN(this->size);
    //till the end of the array * two vectors
    for (int i = 0; i < this -> size; i++)
        vector_temp.vector[i] = this -> vector[i] * newvector.vector[i];

    //since Vector constructor has two arguments, we need to include
    //the size of the vector as well
    vector_temp = Vector(vector_temp.vector, this -> size);
    return vector_temp;
}

istream& operator>>(istream &in, Vector &x)
{
    in >> x.size;
    x.vector = new double[x.size];
    for(int i = 0; i < x.size; i++)
    {
        in >> x.vector[i];
    }
    return in;
}

ostream& operator<<(ostream &os, const Vector &x)
{
    if(x.size == 0)
    {
        os << "This cannot be multiplied" << endl;
    }
    else
    {
        for(int i = 0; i < x.size; i++)
        {
            os << x.vector[i] << " ";
        }
        os << endl;
    }
    return os;
}

Vector Vector::operator*(Matrix &b)
{
    if(this->size == b.getX())
    {
        double *vec = new double[b.getY()];
        for(int i = 0; i < b.getY(); i++)
        {
            vec[i] = 0;
            for(int j = 0; j <this->size; j++)
            {
                vec[i] += this->vector[j] * b.getMat(j,i);
            }
        }
        return Vector(vec,b.getY());
    }
    else
    {
        return Vector();
    }
}
