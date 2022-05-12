#include <string>
#include <iostream>
#include <stdexcept>
#include "Player.hpp"
#include "Actions.hpp"

const int max_players = 6;
const int normal_coup = 7;
const int max_coins = 10;
using namespace std;
using namespace coup;
namespace coup
{
  Player::Player(Game &game, string const &name, string const &role)
  {
    if (game.getLivePlayers().size() >= max_players)
    {
      throw invalid_argument("The Game is full");
    }
    this->currGame = &game;
    this->player_coins = 0;
    this->in_game = true;
    this->name = name;
    this->my_role = role;
    this->player_turn = -1;
    this->last_action = Actions::income;
    currGame->add_player(*this);
  }

  string Player::role()
  {
    return my_role;
  }

  Player &Player::income()
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

    if (this->player_coins >= max_coins)
    {
      cout << "you must to make coup" << endl;
    }
    else
    {
      player_coins++;
    }
    currGame->game_action[this->player_turn] = this;
    this->last_action = Actions::income;
    currGame->next_turn();
    return *this;
  }

  Player &Player::foreign_aid()
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

    if (this->player_coins >= max_coins)
    {
      throw invalid_argument(" You cann't take any coins, you must curry out a coup");
    }
    player_coins += 2;

    currGame->game_action[this->player_turn] = this;
    currGame->getLivePlayers().at(this->player_turn)->last_action = Actions::foreign_aid;
    currGame->next_turn();
    return *this;
  }

  Player &Player::coup(Player &p1)
  {
    if (!currGame->is_alive())
    {
      throw invalid_argument{"Game over"};
    }
    if (currGame->curr_turn != player_turn)
    {
      throw invalid_argument{"this is not your turn"};
    }

    if (!p1.in_game)
    {
      throw invalid_argument(" The player is allready out of the game");
    }

    if (this->coins() < normal_coup)
    {
      throw invalid_argument("you don't have enough money to create a coup");
    }

    p1.in_game = false;
    this->player_coins -= normal_coup;
    currGame->game_action[this->player_turn] = &p1;
    currGame->getLivePlayers().at(this->player_turn)->last_action = Actions::coup;
    currGame->remove_player(p1);
    currGame->next_turn();
    return *this;
  }

  Player &Player::block()
  {
    if (!currGame->is_alive())
    {
      throw invalid_argument{"Game over"};
    }
    throw runtime_error("you cannot do this action");
  }

  int Player::coins() const
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
  int Player::get_turn() const
  {
    return player_turn;
  }
  string Player::get_name()
  {
    return name;
  }

  bool Player::get_in_game() const
  {
    return in_game;
  }
  void Player::set_in_game(bool is_in_game)
  {
    this->in_game = is_in_game;
  }

  void Player::add_coins(int coins)
  {
    this->player_coins += coins;
  }
  int Player::get_coins() const
  {
    return player_coins;
  }
}
