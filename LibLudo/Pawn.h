#pragma once

#include <iostream>
#include <map>

#include "PlayerColor.h"

class Pawn
{
public:

	Pawn();
	Pawn(std::map<int, std::pair<int, int>>::iterator pawnIterator, PlayerColor color, std::pair<int, int> initialPosition, std::pair<int, int>winPosition);
	Pawn(std::pair<int, int> pawnCoordinates, PlayerColor color, std::pair<int, int> initialPosition);
	~Pawn();
	void SetPawnIterator(const std::map<int, std::pair<int, int>>::iterator& iterator);
	void SetPawnCoordinates(const std::pair<int, int>& pawnCoordinates);
	void SetIsBased(const bool isBased);
	void SetInitialPosition(const std::pair<int, int>& pawnCoordinates);
	void SetFinalPosition(const std::pair<int, int>& pawnCoordinates);


	std::map<int, std::pair<int, int>>::iterator& GetPawnIterator();
	std::pair<int, int> GetInitialPosition()const;
	std::pair<int, int> GetWinPosition()const;
	std::pair<int, int>GetPawnCoordinates()const;
	PlayerColor GetPawnColor() const;
	bool IsBased() const;


private:
	bool m_isBased;

	std::map<int, std::pair<int, int>>::iterator m_pawnIterator;
	std::pair<int, int> m_pawnCoordinates;
	std::pair<int, int> m_initialPosition;
	std::pair<int, int> m_winPosition;
	PlayerColor m_color;


};