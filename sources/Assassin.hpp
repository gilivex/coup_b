#pragma once
#include <iostream>
#include <string>
#include "Player.hpp"

using namespace std;

namespace coup
{

    class Assassin : public Player
    {
        public:
        Assassin(Game & game,string name): Player(game,name,"Assassin"){};
        ~Assassin(){};
        Assassin& coup(Player &p1);
    };
}