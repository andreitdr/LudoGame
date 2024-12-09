#pragma once
#include <vector>
#include "../../model/player/Player.h"
#include "../../model/dice/Dice.h"
#include "../../observer/IObserver.h"
#include "../decisionMaker/DecisionMaker.h"
#include "../../observer/Observable.h"

/**
 * @class Game
 * @brief Manages the overall game logic and state.
 */
class Game : public Observable
{
private:
    DecisionMaker decisionMaker; ///< Manages decision-making for the game.
    Dice m_dice; ///< Dice used in the game.
    Player* m_currentPlayer; ///< Pointer to the current player.
    std::vector<Player*> m_players; ///< List of players in the game.

    /**
     * @brief Constructs a new Game object.
     */
    Game() = default;

public:
    /**
     * @brief Gets the singleton instance of the Game.
     * @return Reference to the singleton Game instance.
     */
    static Game& getInstance();

    /**
     * @brief Resets the game to its initial state.
     */
    static void resetGame();

    /**
     * @brief Destroys the Game object.
     */
    ~Game();

    /**
     * @brief Verifies if the current player is the winner.
     */
    void VerifyCurrentPlayerWinner();

    /**
     * @brief Initializes the players for the game.
     */
    void InitializePlayers();

    /**
     * @brief Moves a pawn based on the given row, column, and dice roll.
     * @param row The row of the pawn.
     * @param column The column of the pawn.
     * @param dice The dice roll value.
     */
    void Move(int row, int column, int dice);

    /**
     * @brief Sets the current player by index.
     * @param index The index of the player to set as current.
     */
    void SetCurrentPlayer(int index);

    /**
     * @brief Gets the current player.
     * @return Pointer to the current player.
     */
    Player* GetCurrentPlayer();

    /**
     * @brief Rolls the dice.
     * @return The value of the dice roll.
     */
    uint16_t RollDice();

    /**
     * @brief Gets the list of players.
     * @return A vector of pointers to the players.
     */
    std::vector<Player*> GetPlayers() const;
};