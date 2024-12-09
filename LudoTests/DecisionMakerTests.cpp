#include "gtest/gtest.h"
#include "gameManagement/decisionMaker/DecisionMaker.h"

TEST(DecisionMakerTest, ConstructorTest) {
    DecisionMaker decisionMaker;

    ASSERT_EQ(decisionMaker.GetGreenCoordinates().size(), 57);
    ASSERT_EQ(decisionMaker.GetYellowCoordinates().size(), 57);
    ASSERT_EQ(decisionMaker.GetRedCoordinates().size(), 57);
    ASSERT_EQ(decisionMaker.GetBlueCoordinates().size(), 57);
}





TEST(DecisionMakerTest, FindPawnTest) {
    DecisionMaker decisionMaker;

    Player player1(PlayerColor::Green);
    Player player2(PlayerColor::Red);

 
    Pawn pawn11({ 6, 1 }, PlayerColor::Green, { 6, 1 });
    Pawn pawn12({ 2, 8 }, PlayerColor::Green, { 2, 8 });

    
    Pawn pawn21({ 13, 6 }, PlayerColor::Red, { 13, 6 });
    Pawn pawn22({ 8, 13 }, PlayerColor::Red, { 8, 13 });

    player1.SetPawns({ &pawn11, &pawn12 });
    player2.SetPawns({ &pawn21, &pawn22 });

    std::vector<Player*> players = { &player1, &player2 };

    std::pair<int, int> result = decisionMaker.FindPawn(6, 1, players);
    ASSERT_EQ(result.first, 0);
    ASSERT_EQ(result.second, 0); 

    result = decisionMaker.FindPawn(2, 8, players);
    ASSERT_EQ(result.first, 0);
    ASSERT_EQ(result.second, 1);

    result = decisionMaker.FindPawn(13, 6, players);
    ASSERT_EQ(result.first, 1);
    ASSERT_EQ(result.second, 0);

    result = decisionMaker.FindPawn(8, 13, players);
    ASSERT_EQ(result.first, 1);
    ASSERT_EQ(result.second, 1);

    // Test not finding a pawn
    result = decisionMaker.FindPawn(0, 0, players);
    ASSERT_EQ(result.first, -1);
    ASSERT_EQ(result.second, -1);
}
TEST(DecisionMakerTest, LeaveBase) {
    DecisionMaker decisionMaker;

    auto greenCoordinates = decisionMaker.GetGreenCoordinates();

 
    Pawn pawn(greenCoordinates.begin(), PlayerColor::Green, { 14, 8 }, { 14, 8 });
    pawn.SetIsBased(true); 


    Player player(PlayerColor::Green);
    player.SetPawns({ &pawn });
    std::vector<Player*> players = { &player };


    decisionMaker.LeaveBase(&pawn, players);

    ASSERT_FALSE(pawn.IsBased()); 
    ASSERT_EQ(pawn.GetPawnCoordinates(), greenCoordinates.begin()->second); 
}

TEST(DecisionMakerTest, GetGreenCoordinates) 
{
    DecisionMaker decisionMaker;


    std::map<int, std::pair<int, int>> expectedGreenCoordinates = {
    {0, {6, 1}}, {1, {6, 2}}, {2, {6, 3}}, {3, {6, 4}}, {4, {6, 5}},
    {5, {5, 6}}, {6, {4, 6}}, {7, {3, 6}}, {8, {2, 6}}, {9, {1, 6}},
    {10, {0, 6}}, {11, {0, 7}}, {12, {0, 8}}, {13, {1, 8}}, {14, {2, 8}},
    {15, {3, 8}}, {16, {4, 8}}, {17, {5, 8}}, {18, {6, 9}}, {19, {6, 10}},
    {20, {6, 11}}, {21, {6, 12}}, {22, {6, 13}}, {23, {6, 14}}, {24, {7, 14}},
    {25, {8, 14}}, {26, {8, 13}}, {27, {8, 12}}, {28, {8, 11}}, {29, {8, 10}},
    {30, {8, 9}}, {31, {9, 8}}, {32, {10, 8}}, {33, {11, 8}}, {34, {12, 8}},
    {35, {13, 8}}, {36, {14, 8}}, {37, {14, 7}}, {38, {14, 6}}, {39, {13, 6}},
    {40, {12, 6}}, {41, {11, 6}}, {42, {10, 6}}, {43, {9, 6}}, {44, {8, 5}},
    {45, {8, 4}}, {46, {8, 3}}, {47, {8, 2}}, {48, {8, 1}}, {49, {8, 0}},
    {50, {7, 0}}, {51, {7, 1}}, {52, {7, 2}}, {53, {7, 3}}, {54, {7, 4}},
    {55, {7, 5}}, {56, {7, 6}}
    };


    std::map<int, std::pair<int, int>> actualGreenCoordinates = decisionMaker.GetGreenCoordinates();
    ASSERT_EQ(actualGreenCoordinates, expectedGreenCoordinates);
}


TEST(DecisionMakerTest, GetYellowCoordinates) {
    DecisionMaker decisionMaker;

   
    std::map<int, std::pair<int, int>> expectedYellowCoordinates = {
    {0, {1, 8}}, {1, {2, 8}}, {2, {3, 8}}, {3, {4, 8}}, {4, {5, 8}},
    {5, {6, 9}}, {6, {6, 10}}, {7, {6, 11}}, {8, {6, 12}}, {9, {6, 13}},
    {10, {6, 14}}, {11, {7, 14}}, {12, {8, 14}}, {13, {8, 13}}, {14, {8, 12}},
    {15, {8, 11}}, {16, {8, 10}}, {17, {8, 9}}, {18, {9, 8}}, {19, {10, 8}},
    {20, {11, 8}}, {21, {12, 8}}, {22, {13, 8}}, {23, {14, 8}}, {24, {14, 7}},
    {25, {14, 6}}, {26, {13, 6}}, {27, {12, 6}}, {28, {11, 6}}, {29, {10, 6}},
    {30, {9, 6}}, {31, {8, 5}}, {32, {8, 4}}, {33, {8, 3}}, {34, {8, 2}},
    {35, {8, 1}}, {36, {8, 0}}, {37, {7, 0}}, {38, {6, 0}}, {39, {6, 1}},
    {40, {6, 2}}, {41, {6, 3}}, {42, {6, 4}}, {43, {6, 5}}, {44, {5, 6}},
    {45, {4, 6}}, {46, {3, 6}}, {47, {2, 6}}, {48, {1, 6}}, {49, {0, 6}},
    {50, {0, 7}}, {51, {1, 7}}, {52, {2, 7}}, {53, {3, 7}}, {54, {4, 7}},
    {55, {5, 7}}, {56, {6, 7}}
    };


    std::map<int, std::pair<int, int>> actualYellowCoordinates = decisionMaker.GetYellowCoordinates();
    ASSERT_EQ(actualYellowCoordinates, expectedYellowCoordinates);
}

TEST(DecisionMakerTest, GetRedCoordinates) {

    DecisionMaker decisionMaker;

    std::map<int, std::pair<int, int>> expectedRedCoordinates = {
     {0, {13, 6}}, {1, {12, 6}}, {2, {11, 6}}, {3, {10, 6}}, {4, {9, 6}},
    {5, {8, 5}}, {6, {8, 4}}, {7, {8, 3}}, {8, {8, 2}}, {9, {8, 1}}, {10, {8, 0}},
    {11, {7, 0}}, {12, {6, 0}}, {13, {6, 1}}, {14, {6, 2}}, {15, {6, 3}},
    {16, {6, 4}}, {17, {6, 5}}, {18, {5, 6}}, {19, {4, 6}}, {20, {3, 6}},
    {21, {2, 6}}, {22, {1, 6}}, {23, {0, 6}},
    {24, {0, 7}}, {25, {0, 8}}, {26, {1, 8}}, {27, {2, 8}}, {28, {3, 8}},
    {29, {4, 8}}, {30, {5, 8}}, {31, {6, 9}}, {32, {6, 10}}, {33, {6, 11}},
    {34, {6, 12}}, {35, {6, 13}}, {36, {6, 14}}, {37, {7, 14}}, {38, {8, 14}},
    {39, {8, 13}}, {40, {8, 12}}, {41, {8, 11}}, {42, {8, 10}}, {43, {8, 9}},
    {44, {9, 8}}, {45, {10, 8}}, {46, {11, 8}}, {47, {12, 8}}, {48, {13, 8}},
    {49, {14, 8}}, {50, {14, 7}}, {51, {13, 7}}, {52, {12, 7}}, {53, {11, 7}},
    {54, {10, 7}}, {55, {9, 7}},{56, {8, 7}}
       
    };


    std::map<int, std::pair<int, int>> actualRedCoordinates = decisionMaker.GetRedCoordinates();
    ASSERT_EQ(actualRedCoordinates, expectedRedCoordinates);
}
TEST(DecisionMakerTest, GetBlueCoordinates) {
    DecisionMaker decisionMaker;

 
    std::map<int, std::pair<int, int>> expectedBlueCoordinates = {
        {0, {8, 13}}, {1, {8, 12}}, {2, {8, 11}}, {3, {8, 10}}, {4, {8, 9}},
        {5, {9, 8}}, {6, {10, 8}}, {7, {11, 8}}, {8, {12, 8}}, {9, {13, 8}},
        {10, {14, 8}}, {11, {14, 7}}, {12, {14, 6}}, {13, {13, 6}}, {14, {12, 6}},
        {15, {11, 6}}, {16, {10, 6}}, {17, {9, 6}}, {18, {8, 5}}, {19, {8, 4}},
        {20, {8, 3}}, {21, {8, 2}}, {22, {8, 1}}, {23, {8, 0}}, {24, {7, 0}},
        {25, {6, 0}}, {26, {6, 1}}, {27, {6, 2}}, {28, {6, 3}}, {29, {6, 4}},
        {30, {6, 5}}, {31, {5, 6}}, {32, {4, 6}}, {33, {3, 6}}, {34, {2, 6}},
        {35, {1, 6}}, {36, {0, 6}}, {37, {0, 7}}, {38, {0, 8}}, {39, {1, 8}},
        {40, {2, 8}}, {41, {3, 8}}, {42, {4, 8}}, {43, {5, 8}}, {44, {6, 9}},
        {45, {6, 10}}, {46, {6, 11}}, {47, {6, 12}}, {48, {6, 13}}, {49, {6, 14}},
        {50, {7, 14}}, {51, {7, 13}}, {52, {7, 12}}, {53, {7, 11}}, {54, {7, 10}},
        {55, {7, 9}}, {56, {7, 8}}
    };


    std::map<int, std::pair<int, int>> actualBlueCoordinates = decisionMaker.GetBlueCoordinates();
    ASSERT_EQ(actualBlueCoordinates, expectedBlueCoordinates);
}






