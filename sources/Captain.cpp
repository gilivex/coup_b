// #include <iostream>
// #include <string>
// #include "Game.hpp"
#include "Captain.hpp"

using namespace std;
using namespace coup;
namespace coup
{
    Captain &Captain::steal(Player &p1)
    {
        if (!currGame.is_alive())
        {
            throw invalid_argument{"Game over"};
        }
        if (currGame.curr_turn != player_turn)
        {
            throw invalid_argument{"this is not your turn"};
        }
        if (!(p1->in_game))
        {
            throw invalid_argument { "this player is not in the game!" }
        }
        if (p1->coins == 0)
        {
            throw invalid_argument { "this player has no coins at all" }
        }
        if (p1->coins == 1)
        {
            p1.add_coins(-1);
            this->player_coins++;
        }
        else
        {
            p1.add_coins(-2);
            this->player_coins += 2;
        }
        currGame.game_action[this->player_turn].first = p1.player_turn;
        currGame.game_action[this->player_turn].second = Actions::steal;
        currGame.next_turn();
        return *this;
    }

    Captain &Captain::block(Player &p1)
    {
        if (!p1.get_in_game())
        {
            throw invalid_argument{"the player is not in the game"};
        }
        if (currGame.game_action.at(p1.get_turn()).second == Actions::steal)
        {
            int id = currGame.game_action.at(p1.get_turn()).first;
            
            //if the p2 is not in the game anymore.
            if (currGame.getLivePlayers().find(id) == currGame.getLivePlayers().end())
            {
                return *this;
            }
            p1.add_coins(-2);
            currGame.getLivePlayers().at(id).add_coins(2);
        }

        return *this;
    }
};