/*
CH08-320143
Hand.cpp
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include "Hand.h"
#include <iostream>
#include <vector>
using namespace std;

Hand::Hand()
{
    m_Cards.reserve(7);
}

Hand::~Hand()  
{
    Clear();
}

void Hand::Add(Card* pCard)
{
    m_Cards.push_back(pCard);
}
 
void Hand::Clear()
{
    //iterate through vector, freeing all memory on the heap
    vector<Card*>::iterator iter = m_Cards.begin();
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
        delete *iter;
        *iter = 0;
    }
    //clear vector of pointers
    m_Cards.clear();
}

int Hand::GetTotal() const
{
	int total = 0;
    int numberOfCards = m_Cards.size();
    for (int i = 0; i < numberOfCards; i++) {
        if (total < 11 && m_Cards[i]->GetValue() == 1)
            total += 11;
        else    
            total += m_Cards[i]->GetValue(); 
    } 

    return total;
}