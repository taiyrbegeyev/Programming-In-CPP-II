/*
CH08-320143
Game.h
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#ifndef _GAME_H
#define _GAME_H
#include "Deck.h"
#include "House.h"
#include "Player.h"
#include <iostream>
#include <vector>

class Game
{
public:
    Game(const std::vector<std::string>& names);
    
    ~Game();
    
    //plays the game of blackjack    
    void Play();

private:
    Deck m_Deck;
    House m_House;
    std::vector<Player> m_Players;  
};

#endif

