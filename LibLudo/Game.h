#pragma once
#include<vector>
#include"Player.h"
#include"Dice.h"
#include"IObserver.h"
#include "DecisionMaker.h"
#include "Observable.h"

class Game :  public Observable
{
private:
    DecisionMaker decisionMaker;
    Dice m_dice;
    Player* m_currentPlayer;
    std::vector<Player*> m_players;

public:
	Game();
	~Game();
    void VerifyCurrentPlayerWinner();
    void InitializePlayers();
    void Move(int row, int column, int dice);
    void SetCurrentPlayer(int index);
    Player* GetCurrentPlayer();
    uint16_t RollDice();
    std::vector<Player*> GetPlayers() const;

};

