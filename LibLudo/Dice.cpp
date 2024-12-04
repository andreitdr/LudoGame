#include "Dice.h"
#include <random>

Dice::Dice()
{
	m_diceNumber = 0;
}

uint16_t Dice::roll()
{

	static std::random_device rd;  
	static std::mt19937 gen(rd());
	static std::uniform_int_distribution<> dis(1,6);
	
	m_diceNumber = dis(gen);
	
	return m_diceNumber;
}

void Dice::OnRoll()
{
	return;
}

void Dice::OnMove()
{
	return;
}
