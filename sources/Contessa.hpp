#pragma once
#include <iostream>
#include <string>
#include "Player.hpp"

using namespace std;

namespace coup
{
    class Contessa : public Player
    {
    public:
        Contessa(Game &game, string name): Player(game,name,"Contessa"){};
        ~Contessa(){};
        Contessa& block(Player&);
    };
}