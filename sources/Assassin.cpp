#include <iostream>
#include <string>
#include "Assassin.hpp"
#include "Player.hpp"
#include <stdexcept>
const int normal_coup = 7;
using namespace std;
using namespace coup;
namespace coup
{

    Assassin &Assassin::coup(Player &p1)
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
            throw invalid_argument{"this player is not in the game!"};
        }
        if (this->coins() < 3)
        {
            throw invalid_argument{"you don't have engthe coins"};
        }
        if (this->coins() >= 3 && this->coins() < normal_coup)
        {
            this->add_coins(-3);
            currGame->getLivePlayers().at(this->player_turn)->last_action = Actions::coup3;
        }
        else
        {
            this->add_coins(-(normal_coup));
            currGame->getLivePlayers().at(this->player_turn)->last_action = Actions::coup;
        }
        p1.set_in_game(false);
        currGame->game_action[this->player_turn] = &p1;
        currGame->remove_player(p1);
        currGame->next_turn();

        return *this;
    }
};