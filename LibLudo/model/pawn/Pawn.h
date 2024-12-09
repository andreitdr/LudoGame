#pragma once

#include <iostream>
#include <map>

#include "../playerColor/PlayerColor.h"

/**
 * @class Pawn
 * @brief Represents a pawn in the game.
 */
class Pawn
{
public:
    /**
     * @brief Constructs a new Pawn object.
     */
    Pawn();

    /**
     * @brief Constructs a new Pawn object with specified parameters.
     * @param pawnIterator Iterator to the pawn's position in a map.
     * @param color The color of the pawn.
     * @param initialPosition The initial position of the pawn.
     * @param winPosition The winning position of the pawn.
     */
    Pawn(std::map<int, std::pair<int, int>>::iterator pawnIterator, PlayerColor color, std::pair<int, int> initialPosition, std::pair<int, int> winPosition);

    /**
     * @brief Constructs a new Pawn object with specified coordinates.
     * @param pawnCoordinates The coordinates of the pawn.
     * @param color The color of the pawn.
     * @param initialPosition The initial position of the pawn.
     */
    Pawn(std::pair<int, int> pawnCoordinates, PlayerColor color, std::pair<int, int> initialPosition);

    /**
     * @brief Destroys the Pawn object.
     */
    ~Pawn();

    /**
     * @brief Sets the iterator for the pawn.
     * @param iterator The iterator to set.
     */
    void SetPawnIterator(const std::map<int, std::pair<int, int>>::iterator& iterator);

    /**
     * @brief Sets the coordinates of the pawn.
     * @param pawnCoordinates The coordinates to set.
     */
    void SetPawnCoordinates(const std::pair<int, int>& pawnCoordinates);

    /**
     * @brief Sets whether the pawn is based.
     * @param isBased The based status to set.
     */
    void SetIsBased(const bool isBased);

    /**
     * @brief Sets the initial position of the pawn.
     * @param pawnCoordinates The initial position to set.
     */
    void SetInitialPosition(const std::pair<int, int>& pawnCoordinates);

    /**
     * @brief Sets the final position of the pawn.
     * @param pawnCoordinates The final position to set.
     */
    void SetFinalPosition(const std::pair<int, int>& pawnCoordinates);

    /**
     * @brief Gets the iterator for the pawn.
     * @return Reference to the iterator.
     */
    std::map<int, std::pair<int, int>>::iterator& GetPawnIterator();

    /**
     * @brief Gets the initial position of the pawn.
     * @return The initial position of the pawn.
     */
    std::pair<int, int> GetInitialPosition() const;

    /**
     * @brief Gets the winning position of the pawn.
     * @return The winning position of the pawn.
     */
    std::pair<int, int> GetWinPosition() const;

    /**
     * @brief Gets the coordinates of the pawn.
     * @return The coordinates of the pawn.
     */
    std::pair<int, int> GetPawnCoordinates() const;

    /**
     * @brief Gets the color of the pawn.
     * @return The color of the pawn.
     */
    PlayerColor GetPawnColor() const;

    /**
     * @brief Checks if the pawn is based.
     * @return True if the pawn is based, false otherwise.
     */
    bool IsBased() const;

private:
    bool m_isBased; ///< Indicates if the pawn is based.
    std::map<int, std::pair<int, int>>::iterator m_pawnIterator; ///< Iterator to the pawn's position in a map.
    std::pair<int, int> m_pawnCoordinates; ///< Coordinates of the pawn.
    std::pair<int, int> m_initialPosition; ///< Initial position of the pawn.
    std::pair<int, int> m_winPosition; ///< Winning position of the pawn.
    PlayerColor m_color; ///< Color of the pawn.
};