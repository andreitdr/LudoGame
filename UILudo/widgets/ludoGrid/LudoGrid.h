#pragma once

#include <QWidget>
#include <QPushButton>
#include <vector>
#include <utility>
#include <QLabel>
#include <QGridLayout>
#include "gameManagement/game/Game.h"

/**
 * @class LudoGrid
 * @brief Represents the Ludo game grid in the UI.
 */
class LudoGrid : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a new LudoGrid object.
     * @param parent The parent widget.
     */
    explicit LudoGrid(QWidget* parent = nullptr);

    /**
     * @brief Initializes the game board.
     */
    void InitializeBoard();

    /**
     * @brief Initializes the colors of the pawns.
     */
    void InitializePawnsColors();

    /**
     * @brief Initializes the observer for the game.
     */
    void InitializeObserver();

    /**
     * @brief Handles the event when a cell is clicked.
     * @param row The row of the clicked cell.
     * @param col The column of the clicked cell.
     */
    void OnCellClicked(int row, int col);

    /**
     * @brief Rolls the dice.
     */
    void DiceRoll();

    /**
     * @brief Transforms player positions to button positions.
     * @param players The players in the game.
     */
    void TransformToButtonPositions(const std::vector<Player*>& players);

    /**
     * @brief Updates the positions of the buttons.
     */
    void UpdateButtonPositions();

    /**
     * @brief Updates the states of the pawn buttons.
     */
    void UpdatePawnButtonStates();

    /**
     * @brief Starts the game.
     */
    void StartGame();

    /**
     * @brief Changes the current player.
     */
    void ChangePlayer();

    /**
     * @brief Resets the game.
     */
    void ResetGame();

    /**
     * @brief Displays the final message.
     */
    void FinalMessage();

private:
    std::pair<int, int> m_lastPosition; ///< The last position of a pawn.
    QList<std::pair<int, int>> buttonPositions; ///< The positions of the buttons.
    QPushButton* m_diceButton; ///< The button for rolling the dice.
    QLabel* m_diceLabel; ///< The label for displaying the dice roll.
    QLabel* m_playerLabel; ///< The label for displaying the current player.
    std::vector<QPushButton*> m_pawns; ///< The buttons representing the pawns.
    QString m_board[15][15]; ///< The game board.
    QGridLayout* m_gridLayout; ///< The layout for the grid.
    int m_currentPlayerIndex; ///< The index of the current player.
    int m_lastDiceRoll; ///< The last dice roll.
    bool m_waitingForDice; ///< Indicates if waiting for a dice roll.
    bool m_waitingForMove; ///< Indicates if waiting for a move.
    int m_nrOfsSx; ///< Number of sixes rolled.
};