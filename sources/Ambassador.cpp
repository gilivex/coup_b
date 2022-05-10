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
        if (!currGame.is_alive())
        {
            throw invalid_argument{"Game over"};
        }
        if (currGame.curr_turn != player_turn)
        {
            throw invalid_argument{"this is not your turn"};
        }
        if (!p1.get_in_game() || !p2.get_in_game())
        {
            throw invalid_argument{"at least one of the players is not in the game"};
        }

        if (p1.coins < 1)
        {
            throw invalid_argument{p1.role "don't have any coins"};
        }

        p1.player_coins--;
        p2.player_coins++;
        currGame.game_action[this->player_turn].first = this->player_turn;
        currGame.game_action[this->player_turn].second = Actions::transfer;
        currGame.next_turn();
        return *this;
    }

    Ambassador &Ambassador::block(Player &p1)
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
