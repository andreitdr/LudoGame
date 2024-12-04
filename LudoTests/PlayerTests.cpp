#include <gtest/gtest.h>
#include "Player.h"

TEST(PlayerTests, ConstructorWithColor) {
    Player player(PlayerColor::Red);
    EXPECT_EQ(player.GetColor(), PlayerColor::Red);
    EXPECT_EQ(player.GetPawns().size(), 4);
}


TEST(PlayerTests, DefaultConstructor) {
    Player player;
    EXPECT_EQ(player.GetPawns().size(), 0); 
}

TEST(PlayerTests, SetAndGetColor) {
    Player player;
    player.SetColor(PlayerColor::Blue);
    EXPECT_EQ(player.GetColor(), PlayerColor::Blue);
}


TEST(PlayerTests, SetAndGetPawns) {
    Player player;
    Pawn pawn1, pawn2;
    std::vector<Pawn*> pawns = { &pawn1, &pawn2 };

    player.SetPawns(pawns);
    EXPECT_EQ(player.GetPawns().size(), 2);
    EXPECT_EQ(player.GetPawns()[0], &pawn1);
    EXPECT_EQ(player.GetPawns()[1], &pawn2);
}

TEST(PlayerTests, HasAllPawnsInBase) {
    Player player(PlayerColor::Green);

   
    Pawn pawn1({ 0, 0 }, PlayerColor::Green, { 0, 0 });
    Pawn pawn2({ 0, 0 }, PlayerColor::Green, { 0, 0 });
    Pawn pawn3({ 0, 0 }, PlayerColor::Green, { 0, 0 });
    Pawn pawn4({ 0, 0 }, PlayerColor::Green, { 0, 0 });

    std::vector<Pawn*> pawns = { &pawn1, &pawn2, &pawn3, &pawn4 };
    player.SetPawns(pawns);

    EXPECT_TRUE(player.HasAllPawnsInBase()); 
}



TEST(PlayerTests, SetAndCheckWinnerStatus) {
    Player player(PlayerColor::Yellow);

    EXPECT_FALSE(player.IsWinner()); 

    player.SetIsWinner();
    EXPECT_TRUE(player.IsWinner()); 
}




