/*
CH08-320143
House.cpp
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include "House.h"
#include <iostream>
using namespace std;

House::House(const string& name): 
    GenericPlayer(name)
{}

House::~House()
{}

bool House::IsHitting() const
{
    return (GetTotal() <= 16);
}   

void House::FlipFirstCard()
{
    if (!(m_Cards.empty()))
	{
        m_Cards[0]->Flip();
	}
    else
	{
		cout << "No card to flip!\n";
	}
}