#include <gtest/gtest.h>
#include "model/dice/Dice.h"

TEST(DiceTests, RollReturnsValidRange) {
    Dice dice;

    for (int i = 0; i < 100; ++i) { 
        uint16_t result = dice.roll();
        EXPECT_GE(result, 1);  
        EXPECT_LE(result, 6); 
    }
}
