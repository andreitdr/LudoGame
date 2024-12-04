#pragma once

#include <iostream>
#include <vector>
#include "Pawn.h"
#include "PlayerColor.h"

class Player
{

public:
	Player(PlayerColor playerColor);
	Player();
	~Player();
	void SetColor(PlayerColor playerColor);
	PlayerColor GetColor() const;
	void SetPawns(std::vector<Pawn*> pawns);
	std::vector<Pawn*> GetPawns() const;
	bool HasAllPawnsInBase();
	bool HasAllPawnsInactive();
	void SetIsWinner();
	bool IsWinner();
private:
	PlayerColor m_color;
	std::vector<Pawn*> m_pawns;
	bool m_winner;
};

