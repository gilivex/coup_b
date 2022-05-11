#pragma once
#include <vector>
#include <stdexcept>
#include <utility>
#include <unordered_map>
#include "Actions.hpp"
#include "Player.hpp"

using namespace coup;
using namespace std;
namespace coup
{
    class Player;
    class Game
    {
    private:
        int num_of_players;
    
        unordered_map<int, Player* > livePlayers;
    //    vector<Player> thePlayers;
        bool alive;

    public:
        int curr_turn;
        unordered_map<int,Player*> game_action;
        Game() : curr_turn(0), num_of_players(-1), alive(false){};
        ~Game(){};
        vector<string> players();
        Game &add_player(Player &new_Player);
        string turn();
        string winner();
        bool is_alive()const;
        void set_is_alive(bool);
        int num_players()const;
        unordered_map<int, Player *>& getLivePlayers();
        void next_turn();
        void remove_player(Player &);
    };
};