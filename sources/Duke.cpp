#include <iostream>
#include <string>
#include "Duke.hpp"
#include "Player.hpp"

using namespace std;
namespace coup
{

    Duke &Duke::tax()
    {
        if (!currGame->is_alive() && currGame->getLivePlayers().size() > 1)
        {
            currGame->set_is_alive(true);
        }
        if (!currGame->is_alive())
        {
            throw invalid_argument{"Game over"};
        }
        if (currGame->curr_turn != player_turn)
        {
            throw invalid_argument{"this is not your turn"};
        }
        this->add_coins(3);
        currGame->game_action[this->player_turn] = this;
        currGame->getLivePlayers().at(this->player_turn)->last_action = Actions::tax;
        currGame->next_turn();
        return *this;
    }

    Duke &Duke::block(Player &p1)
    {
        if (!p1.get_in_game())
        {
            throw invalid_argument{"the player is not in the game"};
        }

        if (currGame->game_action.at(p1.get_turn())->last_action == Actions::foreign_aid)
        {
            if (p1.get_coins() == 1)
            {
                p1.add_coins(-1);
            }
            else if (p1.get_coins() > 1)
            {
                p1.add_coins(-2);
            }
        }
        else
        {
            throw invalid_argument("cann't block this action");
        }

        return *this;
    }
};
