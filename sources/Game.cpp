#include "Game.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <unordered_map>

const int max_players =6;
using namespace std;
using namespace coup;

namespace coup
{
    vector<string> Game::players()
    {
        vector<string> Players_names;
        for (size_t i = 0; i <= this->num_of_players; i++)
        {
            if (this->livePlayers.at(i) != NULL)
            {

                Players_names.push_back(this->livePlayers[i]->get_name());
            }
        }

        return Players_names;
    }
    Game &Game::add_player(Player &new_Player)
    {
        if (alive)
        {
            throw invalid_argument("Please wait to the next round, The game has started");
        }
        if (num_of_players > max_players)
        {
            throw invalid_argument("The Game is full");
        }
        num_of_players++;
        new_Player.set_turn(num_of_players);
        this->livePlayers.emplace(num_of_players, &new_Player);
        return *this;
    }
    string Game::turn()
    {
        return (livePlayers.at(curr_turn)->get_name());
    }

    string Game::winner()
    {
        if (alive)
        {
            throw invalid_argument{"the game is still running"};
        }
        if (livePlayers.size() != 1)
        {
            throw invalid_argument{"there is still more then one Player in the game"};
        }

        {
            return players().at(0);
        }
    }
        bool Game::is_alive()const
        {
            return alive;
        }
        void Game::set_is_alive(bool status)
        {
            alive = status;
        }

        int Game::num_players()const
        {
            return num_of_players;
        }

        unordered_map<int, Player *> &Game::getLivePlayers()
        {
            return livePlayers;
        }

        void Game::next_turn()
        {
            do
            {
                curr_turn++;
                curr_turn%=(num_of_players+1);
            } while (livePlayers.at(curr_turn) == NULL);
        }

        void Game::remove_player(Player & player)
        {
            if (livePlayers.at(player.get_turn()) == NULL)
            {
                throw invalid_argument{"the player is not in the game"};
            }
            livePlayers[player.get_turn()] = NULL;
            if (players().size() == 1)
            {
                alive = false;
            }
            

        }
    };