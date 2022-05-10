#include <iostream>
#include <string>
#include "Duke.hpp"
#include "Player.hpp"

using namespace std;
namespace coup
{

    Duke& Duke::tax()
    {
        this->player_coins+=3;
        return *this;
    }
    Duke& Duke::block(Player p1)
    {
        if (p1.foreign_aid)
        {
            p1.player_coins-=2;
        }
        
        return *this;
    }
};
