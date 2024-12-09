#pragma once
#include<vector>
#include"../../model/player/Player.h"
#include"../../model/dice/Dice.h"
#include"../../observer/IObserver.h"
#include "../decisionMaker/DecisionMaker.h"
#include "../../observer/Observable.h"

class Game :  public Observable
{
private:
    DecisionMaker decisionMaker;
    Dice m_dice;
    Player* m_currentPlayer;
    std::vector<Player*> m_players;
	Game() = default;

public:
    static Game& getInstance();
    static void resetGame();
	~Game();
    void VerifyCurrentPlayerWinner();
    void InitializePlayers();
    void Move(int row, int column, int dice);
    void SetCurrentPlayer(int index);
    Player* GetCurrentPlayer();
    uint16_t RollDice();
    std::vector<Player*> GetPlayers() const;

};

