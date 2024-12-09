#pragma once
#include <iostream>
#include "../../observer/IObserver.h"

/**
 * @class Dice
 * @brief Represents a dice used in the game.
 */
class Dice : public IObserver
{
public:
    /**
     * @brief Constructs a new Dice object.
     */
    Dice();

    /**
     * @brief Rolls the dice and returns the result.
     * @return The value of the dice roll.
     */
    uint16_t roll();

    /**
     * @brief Called when the dice is rolled.
     */
    void OnRoll() override;

    /**
     * @brief Called when a move is made.
     */
    void OnMove() override;

private:
    uint16_t m_diceNumber; ///< The current value of the dice.
};