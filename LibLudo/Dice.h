#pragma once
#include <iostream>
#include "IObserver.h"

class Dice: public IObserver
{
public:
	Dice();
	uint16_t roll();
	void OnRoll() override;
	void OnMove() override;
private:
	uint16_t m_diceNumber;
};

