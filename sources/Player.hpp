#pragma once
#include "Game.hpp"
#include <string>
#include <iostream>

using namespace coup;
using namespace std;
namespace coup
{
    class Game;
    class Player
    {

    protected:
        Game *currGame;
        int player_coins;
        int player_turn;
        string name;
        string my_role;
        bool in_game;
        // Actions last_action;

    public:
        // constractor
        Player(Game &game, string const &name, string const &role);
        // : currGame(game), name(name), my_role(role), player_coins(0), in_game(true){};
        
        
        
        ~Player(){};
        Actions last_action;
        // getters and setter
        string role();
        int coins()const;
        void set_turn(int);
        int get_turn()const;
        string get_name();
        bool get_in_game()const;
        void set_in_game(bool);
        void add_coins(int);
        int get_coins()const;

        // funcations
        Player &income();
        Player &foreign_aid();
        Player &coup(Player &p1);
        Player &block();
    };
}