#pragma once
#include <iostream>
#include "Player.hpp"
#include <string>

using namespace std;

namespace coup
{
    class Captain : public Player
    {

    public:
        Captain(Game & game,string name): Player(&game,name,"Captain"){};
        ~Captain(){};
        Captain& steal(Player &p1);
        Captain& block(Player &p1);
    };
}
