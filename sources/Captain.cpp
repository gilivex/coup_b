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
        if (!currGame->is_alive())
        {
            throw invalid_argument{"Game over"};
        }
        if (currGame->curr_turn != player_turn)
        {
            throw invalid_argument{"this is not your turn"};
        }
        if (!(p1.get_in_game()))
        {
            throw invalid_argument { "this player is not in the game!" };
        }
        if (p1.coins() == 0)
        {
            throw invalid_argument { "this player has no coins at all" };
        }
        if (p1.coins() == 1)
        {
            p1.add_coins(-1);
            this->player_coins++;
        }
        else
        {
            p1.add_coins(-2);
            this->player_coins += 2;
        }
        currGame->game_action[this->player_turn] = &p1;
        currGame->getLivePlayers().at(this->player_turn)->last_action = Actions::steal;
        currGame->next_turn();
        return *this;
    }

    Captain &Captain::block(Player &p1)
    {
        if (!p1.get_in_game())
        {
            throw invalid_argument{"the player is not in the game"};
        }
        if (currGame->game_action.at(p1.get_turn())->last_action == Actions::steal)
        {
            int id = currGame->game_action.at(p1.get_turn())->get_turn();
            
            //if the p2 is not in the game anymore.
            if (currGame->getLivePlayers().at(id) == NULL)
            {
                return *this;
            }
            p1.add_coins(-2);
            currGame->getLivePlayers().at(id)->add_coins(2);
        }
        else {
            throw invalid_argument("cann't block this action");
        }

        return *this;
    }
};