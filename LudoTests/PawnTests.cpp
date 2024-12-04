#include <gtest/gtest.h>
#include "Pawn.h"
#include <map>


TEST(PawnTests, DefaultConstructorSetsIsBasedTrue) {
    Pawn pawn;
    EXPECT_TRUE(pawn.GetInitialPosition() == std::make_pair(0, 0));
}


TEST(PawnTests, ConstructorWithIteratorSetsCorrectValues) {
    std::map<int, std::pair<int, int>> mockMap;
    auto mockIterator = mockMap.begin();
    std::pair<int, int> initialPos = { 1, 2 };
    std::pair<int, int> winPos = { 3, 4 };
    PlayerColor color = PlayerColor::Red;

    Pawn pawn(mockIterator, color, initialPos, winPos);

    EXPECT_EQ(pawn.GetInitialPosition(), initialPos);

}


TEST(PawnTests, ConstructorWithCoordinatesSetsCorrectValues) {
    std::pair<int, int> coordinates = { 5, 6 };
    PlayerColor color = PlayerColor::Blue;
    std::pair<int, int> initialPos = { 1, 1 };

    Pawn pawn(coordinates, color, initialPos);

    EXPECT_EQ(pawn.GetInitialPosition(), initialPos);

}


TEST(PawnTests, GetInitialPositionReturnsCorrectValue) {
    std::pair<int, int> initialPos = { 3, 4 };
    Pawn pawn(initialPos, PlayerColor::Red, initialPos);

    EXPECT_EQ(pawn.GetInitialPosition(), initialPos);
}




