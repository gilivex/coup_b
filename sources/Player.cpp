#include <string>
#include <iostream>
#include <stdexcept>
#include "Player.hpp"
#include "Actions.hpp"

using namespace std;
using namespace coup;
namespace coup
{

  string Player::role()
  {
    return my_role;
  }

  Player &Player::income()
  {
    if (!currGame.is_alive() && currGame.getLivePlayers().size() > 1)
    {
      currGame.is_alive = true;
      currGame.curr_turn++;
    }
    if (!currGame.is_alive())
    {
      throw invalid_argument{"Game over"};
    }
    if (currGame.curr_turn != player_turn)
    {
      throw invalid_argument{"this is not your turn"};
    }

    if (this->player_coins >= 10)
    {
      cout << "you must to make coup" << endl;
    }
    else
    {
      player_coins++;
    }
    currGame.game_action[this->player_turn].first = this->player_turn;
    currGame.game_action[this->player_turn].second = Actions::income;
    currGame.next_turn();
    return *this;
  }

  Player &Player::foreign_aid()
  {
    if (!currGame.is_alive())
    {
      throw invalid_argument{"Game over"};
    }

    if (currGame.curr_turn != player_turn)
    {
      throw invalid_argument{"this is not your turn"};
    }

    if (this->player_coins >= 10)
    {
      throw invalid_argument(" You cann't take any coins, you must curry out a coup");
    }
    else
    {
      player_coins += 2;
    }
    currGame.game_action[this->player_turn].first = this->player_turn;
    currGame.game_action[this->player_turn].second = Actions::foreign_aid;
    currGame.next_turn();
    return *this;
  }

  Player &Player::coup(Player &p1)
  {
    if (!currGame.is_alive())
    {
      throw invalid_argument{"Game over"};
    }
    if (currGame.curr_turn != player_turn)
    {
      throw invalid_argument{"this is not your turn"};
    }

    if (!p1.in_game)
    {
      throw invalid_argument(" The player is allready out of the game");
    }

    if (*this->coins < 7)
    {
      throw invalid_argument("you don't have enough money to create a coup");
    }

    currGame.remove_player(p1);
    p1.in_game = false;
    this->player_coins -= 7;
    currGame.game_action[this->player_turn].first = p1.player_turn;
    currGame.game_action[this->player_turn].second = Actions::coup;
    currGame.next_turn();
    return *this;
  }

  Player &Player::block()
  {
    if (!currGame.is_alive())
    {
      throw invalid_argument{"Game over"};
    }
    throw runtime_error("you cannot do this action");
  }

  int Player::coins()
  {
    if (!this->in_game)
    {
      throw invalid_argument{"the player isn't in the game"};
    }

    return this->player_coins;
  }
  void Player::set_turn(int turn)
  {
    player_turn = turn;
  }
  int Player::get_turn()
  {
    return player_turn;
  }
  string Player::get_name()
  {
    return name;
  }

  bool Player::get_in_game()
  {
    return in_game;
  }
  void Player::add_coins(int coins){
      this->player_coins+=coins;
  }
}
