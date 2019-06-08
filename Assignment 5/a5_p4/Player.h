/*
CH08-320143
Player.h
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#ifndef _PLAYER_H
#define _PLAYER_H
#include "GenericPlayer.h"
#include <iostream>

class Player : public GenericPlayer
{
public:
    Player(const std::string& name = "");

    virtual ~Player();

    //returns whether or not the player wants another hit       
    virtual bool IsHitting() const;

    //announces that the player wins
    void Win() const;

    //announces that the player loses
    void Lose() const;

    //announces that the player pushes
    void Push() const;
};

#endif