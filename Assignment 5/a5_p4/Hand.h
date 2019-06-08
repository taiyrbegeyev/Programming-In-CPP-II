/*
CH08-320143
Hand.h
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#ifndef _HAND_H
#define _HAND_H
#include "Card.h"
#include <iostream>
#include <vector>

class Hand
{
public:
    Hand();
    
    virtual ~Hand();

    //adds a card to the hand
    void Add(Card* pCard);
 
    //clears hand of all cards
    void Clear();
 
    //gets hand total value, intelligently treats aces as 1 or 11
    int GetTotal() const;

protected:
    std::vector<Card*> m_Cards;
};

#endif