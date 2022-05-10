#pragma once
#include <iostream>
#include "Player.hpp"
#include <string>

using namespace std;
namespace coup{

    class Ambassador : public Player
    {
       public:
       Ambassador(Game & game,string name): Player(game,name,"Ambassador"){};
        ~Ambassador(){};
        Ambassador& transfer(Player &p1, Player &p2);
        Ambassador& block(Player &p1);
    };
}