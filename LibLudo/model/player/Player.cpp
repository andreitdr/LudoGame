#include "Player.h"

Player::Player(PlayerColor playerColor)
{
	this->m_color = playerColor;
	this->m_pawns.resize(4);
	this->m_winner = false;
}

Player::Player()
{
	for (auto pawn : m_pawns) {
		delete pawn;
	}
	m_pawns.clear(); 
}

Player::~Player()
{
}

void Player::SetColor(PlayerColor playerColor)
{
	this->m_color = playerColor;
}

PlayerColor Player::GetColor() const
{
	return m_color;
}

void Player::SetPawns(std::vector<Pawn*> pawns)
{
	m_pawns = pawns;
}

std::vector<Pawn*> Player::GetPawns() const
{
	return m_pawns;
}

bool Player::HasAllPawnsInBase()
{
	int cnt=0;
	for (const auto& pawn : m_pawns)
	{
		if (pawn->GetPawnCoordinates() == pawn->GetInitialPosition())
			cnt++;
	}
	if (cnt == 4)
		return true;
	else
		return false;
}

bool Player::HasAllPawnsInactive()
{
	if (HasAllPawnsInBase() == true) return true;

	int inactivePawns = 0;
	for (const auto& pawn : m_pawns)
	{
		if (pawn->GetPawnCoordinates() == pawn->GetInitialPosition() || pawn->GetPawnCoordinates() == pawn->GetWinPosition())
			inactivePawns++;
	}

	if (inactivePawns == 4)
		return true;
	else
		return false;
}

void Player::SetIsWinner()
{
	m_winner = true;
}

bool Player::IsWinner()
{
	return m_winner;
}
