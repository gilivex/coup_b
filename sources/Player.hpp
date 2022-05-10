#pragma once
#include "Game.hpp"
#include <string>
#include <iostream>

using namespace std;
namespace coup
{
    class Game;
    class Player
    {

    private:
        Game &currGame;
        int player_coins;
        int player_turn;
        string name;
        string my_role;
        bool in_game;

    public:
        // constractor
        Player(Game &game, string name, string role) : currGame(game), name(name), my_role(role), player_coins(0), in_game(true)
        {
            currGame.add_player(this);
        };

        ~Player(){};
        // getters and setter
        string role();
        int coins();
        void set_turn(int);
        int get_turn();
        string get_name();
        bool get_in_game();
        void add_coins(int);

        // funcations
        Player &income();
        Player &foreign_aid();
        Player &coup(Player *p1);
        Player &block();
    };
}