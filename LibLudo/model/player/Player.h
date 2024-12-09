#pragma once

#include <iostream>
#include <vector>
#include "../pawn/Pawn.h"
#include "../playerColor/PlayerColor.h"

/**
 * @class Player
 * @brief Represents a player in the game.
 */
class Player
{
public:
    /**
     * @brief Constructs a new Player object with a specified color.
     * @param playerColor The color of the player.
     */
    Player(PlayerColor playerColor);

    /**
     * @brief Constructs a new Player object.
     */
    Player();

    /**
     * @brief Destroys the Player object.
     */
    ~Player();

    /**
     * @brief Sets the color of the player.
     * @param playerColor The color to set.
     */
    void SetColor(PlayerColor playerColor);

    /**
     * @brief Gets the color of the player.
     * @return The color of the player.
     */
    PlayerColor GetColor() const;

    /**
     * @brief Sets the pawns of the player.
     * @param pawns The pawns to set.
     */
    void SetPawns(std::vector<Pawn*> pawns);

    /**
     * @brief Gets the pawns of the player.
     * @return A vector of pointers to the pawns.
     */
    std::vector<Pawn*> GetPawns() const;

    /**
     * @brief Checks if all pawns are in the base.
     * @return True if all pawns are in the base, false otherwise.
     */
    bool HasAllPawnsInBase();

    /**
     * @brief Checks if all pawns are inactive.
     * @return True if all pawns are inactive, false otherwise.
     */
    bool HasAllPawnsInactive();

    /**
     * @brief Sets the player as the winner.
     */
    void SetIsWinner();

    /**
     * @brief Checks if the player is the winner.
     * @return True if the player is the winner, false otherwise.
     */
    bool IsWinner();

private:
    PlayerColor m_color; ///< The color of the player.
    std::vector<Pawn*> m_pawns; ///< The pawns of the player.
    bool m_winner; ///< Indicates if the player is the winner.
};