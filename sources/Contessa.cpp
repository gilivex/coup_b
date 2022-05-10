#include <iostream>
#include <string>
#include "Game.hpp"
#include "Contessa.hpp"

using namespace std;
using namespace coup;
namespace coup
{
    Contessa &Contessa::block(Player &p1)
    {
        if (!p1.get_in_game())
        {
            throw invalid_argument{"the player is not in the game"};
        }
        if (currGame.game_action.at(p1.get_turn()).second == Actions::coup && p1.role() == "Assassin")
        {
            
        }

        return *this;
    }
};