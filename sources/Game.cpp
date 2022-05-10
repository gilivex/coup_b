#include "Game.hpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
using namespace coup;

vector<string> Game::players()
{
    vector<string> Players_names = [];
    for (p : livePlayers)
    {
        Players_names.push_back(p.get_name());
    }
    return Players_names;
}
Game &Game::add_player(Player *new_Player)
{
    if (alive)
    {
        throw invalid_argument("Please wait to the next round, The game has started")
    }

    if (num_of_players > 5)
    {
        throw invalid_argument("The Game is full")
    }
    num_of_players++;
    new_Player->set_turn(num_of_players);
    livePlayers[num_of_players] = new_Player;
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
    else
    {
        return players().at(0);
    }
}

bool Game::is_alive()
{
    return alive;
}

int Game::num_players()
{
    return num_of_players;
}

unordered_map<int, Player &>& Game::getLivePlayers(){
    return livePlayers;
}

void Game::next_turn()
{
    do
    {
        curr_turn++;
    } while (livePlayers.find(curr_turn) == livePlayers.end());
}


void Game::remove_player(Player &player)
{
    if (livePlayers.find(new_Player) == livePlayers.end()){
        throw invalid_argument{"the player is not in the game"};
    }
    livePlayers.erase(player.get_turn());
    if (livePlayers.size() ==1)
    {
        alive = false;
    }
    
    return *this;
}
