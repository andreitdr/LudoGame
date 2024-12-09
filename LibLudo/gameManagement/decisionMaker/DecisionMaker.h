#pragma once

#include <iostream>
#include <map>
#include <vector>

#include "../../model/pawn/Pawn.h"
#include "../../model/player/Player.h"

/**
 * @class DecisionMaker
 * @brief Manages the decision-making process for the game.
 */
class DecisionMaker
{
public:
    /**
     * @brief Constructs a new DecisionMaker object.
     */
    DecisionMaker();

    /**
     * @brief Finds a pawn at the specified row and column.
     * @param row The row to search.
     * @param column The column to search.
     * @param players The list of players.
     * @return A pair of integers representing the position of the pawn.
     */
    std::pair<int, int> FindPawn(int row, int column, std::vector<Player*> players);

    /**
     * @brief Moves a pawn based on the given coordinates and dice roll.
     * @param coordinates The coordinates of the pawn.
     * @param dice The dice roll value.
     * @param players The list of players.
     */
    void Move(std::pair<int, int> coordinates, int dice, std::vector<Player*> players);

    /**
     * @brief Executes the move action for a pawn.
     * @param pawn The pawn to move.
     * @param dice The dice roll value.
     * @param players The list of players.
     */
    void MoveAction(Pawn* pawn, int dice, std::vector<Player*> players);

    /**
     * @brief Moves a pawn out of the base.
     * @param pawn The pawn to move.
     * @param players The list of players.
     */
    void LeaveBase(Pawn* pawn, std::vector<Player*> players);

    /**
     * @brief Captures a pawn.
     * @param pawn The pawn to capture.
     * @param players The list of players.
     */
    void Capture(Pawn* pawn, std::vector<Player*> players);

    /**
     * @brief Captures multiple pawns.
     * @param pawn The pawn to capture.
     * @param players The list of players.
     */
    void MultipleCapture(Pawn* pawn, std::vector<Player*> players);

    /**
     * @brief Gets the number of pawns at the specified position.
     * @param pawn The pawn to check.
     * @param players The list of players.
     * @return The number of pawns at the specified position.
     */
    int NrOfPawnsAt(Pawn* pawn, std::vector<Player*> players);

    /**
     * @brief Gets the coordinates for the green player.
     * @return A map of coordinates for the green player.
     */
    std::map<int, std::pair<int, int>> GetGreenCoordinates() const;

    /**
     * @brief Gets the coordinates for the yellow player.
     * @return A map of coordinates for the yellow player.
     */
    std::map<int, std::pair<int, int>> GetYellowCoordinates() const;

    /**
     * @brief Gets the coordinates for the red player.
     * @return A map of coordinates for the red player.
     */
    std::map<int, std::pair<int, int>> GetRedCoordinates() const;

    /**
     * @brief Gets the coordinates for the blue player.
     * @return A map of coordinates for the blue player.
     */
    std::map<int, std::pair<int, int>> GetBlueCoordinates() const;

private:
    std::map<int, std::pair<int, int>> m_greenCoordinates; ///< Coordinates for the green player.
    std::map<int, std::pair<int, int>> m_yellowCoordinates; ///< Coordinates for the yellow player.
    std::map<int, std::pair<int, int>> m_redCoordinates; ///< Coordinates for the red player.
    std::map<int, std::pair<int, int>> m_blueCoordinates; ///< Coordinates for the blue player.
};