#pragma once
#include <vector>
#include <stdexcept>
#include <unordered_map>
#include "Actions.hpp"

using namespace coup;
using namespace std;
namespace coup
{
    class Player;
    class Game
    {
    private:
        int num_of_players;
        // string game_action;

        // vector<Player*> livePlayers;
        unordered_map<int, Player &> livePlayers;
        bool alive;

    public:
        int curr_turn;
        unordered_map<int,pair<int, coup::Actions>> game_action;

        Game() : curr_turn(-1), num_of_players(0), alive(false);
        // Game():cur_player_turn(0),was_player_turn(0),quantity(0),game_action(to_string(cur_player_turn) + "." + to_string(was_player_turn) + "." + to_string(quantity));
        ~Game(){};
        vector<string> players();
        Game &add_player(Player *new_Player);
        string turn();
        string winner();
        bool is_alive();
        int num_players();
        unordered_map<int, Player &> getLivePlayers();
        void next_turn();
        void remove_player(Player &);
    };
};