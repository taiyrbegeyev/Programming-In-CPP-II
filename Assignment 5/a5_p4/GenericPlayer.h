/*
CH08-320143
GenericPlayer.h
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#ifndef _GENERICPLAYER_H
#define _GENERICPLAYER_H
#include "Hand.h"
#include <iostream>

class GenericPlayer : public Hand
{
    friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);

public:
    GenericPlayer(const std::string& name = "");
    
    virtual ~GenericPlayer();

    //indicates whether or not generic player wants to keep hitting
    virtual bool IsHitting() const = 0;

    //returns whether generic player has busted - has a total greater than 21
    bool IsBusted() const;

    //announces that the generic player busts
    void Bust() const;

protected:
    std::string m_Name;
};

std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);

#endif