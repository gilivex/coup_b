#include <iostream>
#include "Player.hpp"
#include <string>
#include "Ambassador.hpp"

using namespace std;
using namespace coup;
namespace coup
{

    Ambassador &Ambassador::transfer(Player &p1, Player &p2)
    {
        if (!this->currGame->is_alive())
        {
            throw invalid_argument{"Game over"};
        }
        if (this->currGame->curr_turn != this->player_turn)
        {
            throw invalid_argument{"this is not your turn"};
        }
        if (!p1.get_in_game() || !p2.get_in_game())
        {
            throw invalid_argument{"at least one of the players is not in the game"};
        }

        if (p1.get_coins() < 1)
        {
            throw invalid_argument{"don't have any coins"};
        }

        p1.add_coins(-1);
        p2.add_coins(1);
        // this->currGame.game_action[this->player_turn].first = p1;
        this->currGame->getLivePlayers().at(player_turn)->last_action = Actions::transfer;
        this->currGame->next_turn();
        return *this;
    }

    Ambassador &Ambassador::block(Player &p1)
    {
        if (!p1.get_in_game())
        {
            throw invalid_argument{"the player is not in the game"};
        }
        if (this->currGame->getLivePlayers().at(p1.get_turn())->last_action == Actions::steal)
        {
            int id = this->currGame->game_action.at(p1.get_turn())->get_turn();
            
            //if the p2 is not in the game anymore.
            if (this->currGame->getLivePlayers().find(id) == this->currGame->getLivePlayers().end())
            {
                return *this;
            }
            p1.add_coins(-2);
            this->currGame->game_action.at(p1.get_turn())->add_coins(2);
        }
        else {
            throw invalid_argument("cann't block this action");
        }

        return *this;
    }
};
