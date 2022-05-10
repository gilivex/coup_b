#include <string>
#include <iostream>
#include <stdexcept>

#include "Game.hpp"
#include "Player.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Duke.hpp"
#include "doctest.h"

using namespace std;
using namespace coup;

Game game_1{};
Game game_2{};
Ambassador ambassador1(game_1, "amb1");
Ambassador ambassador2(game_2, "amb2");
Assassin assassin1(game_1, "ass1");
Assassin assassin2(game_2, "ass2");
Captain captain1(game_1, "cap1");
Captain captain2(game_2, "cap2");
Contessa contessa1(game_1, "con1");
Contessa contessa2(game_2, "con2");
Duke duke1(game_1, "duk1");
Duke duke2(game_2, "duk2");



TEST_CASE("Game is alive")
{
    vector<string> players = {"amb1", "ass1","duk1","con1", "cap1", "amb2"};
    for (uint i = 0; i < players.size(); i++)
    {
        CHECK_EQ(game_1.turn(), players.at(i));
    }
}

TEST_CASE("Game is alive")
{
    vector<string> players = {"amb2", "ass2","duk2","con2", "cap2", "amb1"};
    for (uint i = 0; i < players.size(); i++)
    {
                CHECK_EQ(game_2.turn(), players.at(i));
    }
}
TEST_CASE("bad turns") {

            CHECK_EQ(game_1.turn(), "amb1");
    ambassador1.income();
            CHECK_EQ(game_1.turn(), "ass1");
    assassin1.income();
            CHECK_EQ(game_1.turn(), "duk1");
    duke1.income();
            CHECK_EQ(game_1.turn(), "con1");
    contessa1.income();
            CHECK_EQ(game_1.turn(), "cap1");
    captain1.income();
            CHECK_EQ(game_1.turn(), "amb1");
    ambassador1.income();

    CHECK_THROWS(duke1.income());

            CHECK_EQ(game_2.turn(), "amb1");
    ambassador2.income();
            CHECK_EQ(game_2.turn(), "ass1");
    assassin2.income();
            CHECK_EQ(game_2.turn(), "duk1");
    duke2.income();
            CHECK_EQ(game_2.turn(), "con1");
    contessa2.income();
            CHECK_EQ(game_2.turn(), "cap1");
    captain2.income();
            CHECK_EQ(game_2.turn(), "amb1");
    ambassador1.income();

    CHECK_THROWS(contessa2.income());
}

TEST_CASE("good turns") {

            CHECK_EQ(game_1.turn(), "amb1");
    ambassador1.income();
            CHECK_EQ(game_1.turn(), "ass1");
    assassin1.income();
            CHECK_EQ(game_1.turn(), "duk1");
    duke1.income();
            CHECK_EQ(game_1.turn(), "con1");
    contessa1.income();
            CHECK_EQ(game_1.turn(), "cap1");
    captain1.income();
            CHECK_EQ(game_1.turn(), "amb1");
    ambassador2.income();

    CHECK_NOTHROW(ambassador2.income());

            CHECK_EQ(game_2.turn(), "amb1");
    ambassador2.income();
            CHECK_EQ(game_2.turn(), "ass1");
    assassin2.income();
            CHECK_EQ(game_2.turn(), "duk1");
    duke2.income();
            CHECK_EQ(game_2.turn(), "con1");
    contessa2.income();
            CHECK_EQ(game_2.turn(), "cap1");
    captain2.income();
            CHECK_EQ(game_2.turn(), "amb1");
    ambassador1.income();

    CHECK_NOTHROW(ambassador1.income());;
}