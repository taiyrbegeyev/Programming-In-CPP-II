/*
CH08-320143
House.h
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#ifndef _HOUSE_H
#define _HOUSE_H
#include "GenericPlayer.h"
#include <iostream>

class House : public GenericPlayer
{
public:
    House(const std::string& name = "House");

    virtual ~House();

    //indicates whether house is hitting - will always hit on 16 or less
    virtual bool IsHitting() const;

    //flips over first card
    void FlipFirstCard();
};

#endif