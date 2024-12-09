#include "Pawn.h"

Pawn::Pawn()
{
	m_isBased = true;
}

Pawn::Pawn(std::map<int, std::pair<int, int>>::iterator pawnIterator, PlayerColor color, std::pair<int, int> initialPosition, std::pair<int,int> winPosition)
{
	this->m_pawnIterator = pawnIterator;
	this->m_color = color;
	this->m_initialPosition = initialPosition;
	this->m_winPosition = winPosition;
	m_isBased = true;
}

Pawn::Pawn(std::pair<int, int> pawnCoordinates, PlayerColor color, std::pair<int, int> initialPosition)
{
	this->m_pawnCoordinates = pawnCoordinates;
	this->m_color = color;
	this->m_initialPosition = initialPosition;
	m_isBased = true;
}

Pawn::~Pawn()
{

}

void Pawn::SetPawnIterator(const std::map<int, std::pair<int, int>>::iterator& iterator)
{
	this->m_pawnIterator = iterator;
}

void Pawn::SetPawnCoordinates(const std::pair<int, int>& pawnCoordinates)
{
	this->m_pawnCoordinates = pawnCoordinates;
}



void Pawn::SetIsBased(const bool isBased)
{
	this->m_isBased = isBased;
}

void Pawn::SetInitialPosition(const std::pair<int, int>& pawnCoordinates)
{
	m_initialPosition = pawnCoordinates;
}

void Pawn::SetFinalPosition(const std::pair<int, int>& pawnCoordinates)
{
	this->m_initialPosition = pawnCoordinates;
}

std::map<int, std::pair<int, int>>::iterator& Pawn::GetPawnIterator()
{
	return this->m_pawnIterator;
}

std::pair<int, int> Pawn::GetInitialPosition() const
{
	return this->m_initialPosition;
}

std::pair<int, int> Pawn::GetWinPosition() const
{
	return this->m_winPosition;
}

std::pair<int, int> Pawn::GetPawnCoordinates() const
{
	return this->m_pawnCoordinates;
}

PlayerColor Pawn::GetPawnColor() const
{
	return this->m_color;
}

bool Pawn::IsBased() const
{
	return this->m_isBased;
}
