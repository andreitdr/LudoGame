#include <gtest/gtest.h>
#include "gameManagement/game/Game.h"

TEST(GameTests, InitializePlayersCreatesCorrectNumberOfPlayersAndPawns) {
    Game game = Game::getInstance();
    game.InitializePlayers();

    auto players = game.GetPlayers();
    ASSERT_EQ(players.size(), 4); 

    for (const auto& player : players) {
        EXPECT_EQ(player->GetPawns().size(), 4); 
    }
}


TEST(GameTests, RollDiceReturnsValidRange) {
    Game game = Game::getInstance();

    for (int i = 0; i < 100; ++i) {
        uint16_t result = game.RollDice();
        EXPECT_GE(result, 1);
        EXPECT_LE(result, 6); 
    }
}

TEST(GameTests, SetCurrentPlayerWorksCorrectly) {
    Game game = Game::getInstance();
    game.InitializePlayers();

    game.SetCurrentPlayer(2); 
    auto currentPlayer = game.GetCurrentPlayer();

    EXPECT_EQ(currentPlayer, game.GetPlayers()[2]); 
}

TEST(GameTests, GetPlayersReturnsCorrectPlayers) {
    Game game = Game::getInstance();
    game.InitializePlayers();

    auto players = game.GetPlayers();
    ASSERT_EQ(players.size(), 4); 

    EXPECT_EQ(players[0]->GetColor(), PlayerColor::Green);
    EXPECT_EQ(players[1]->GetColor(), PlayerColor::Yellow);
    EXPECT_EQ(players[2]->GetColor(), PlayerColor::Red);
    EXPECT_EQ(players[3]->GetColor(), PlayerColor::Blue);
}