#include <iostream>
#include <string>
#include "Assassin.hpp"
#include "Player.hpp"
#include <stdexcept>

using namespace std;
using namespace coup;
namespace coup
{

    Assassin &Assassin::coup(Player &p1)
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
        else
        {
            if (this->coins < 3)
            {
                throw invalid_argument { "you don't have engthe coins" }
            }
            if (this->coins > 3 && this->coins < 7)
            {
                this->coins -= 3;
            }
            else
            {
                this->coins -= 7;
            }
            currGame.remove_player(p1);
            p1.in_game = false;
            currGame.game_action[this->player_turn].first = p1.player_turn;
            currGame.game_action[this->player_turn].second = Actions::coup;
            currGame.next_turn();
        }
        return *this;
    }
};