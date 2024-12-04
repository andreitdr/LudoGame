#pragma once

#include <iostream>

#include <map> 
#include <vector>

#include"Dice.h"
#include "Pawn.h"
#include "Player.h"

class DecisionMaker
{
public:
    DecisionMaker();

    std::pair<int, int> FindPawn(int row, int column, std::vector<Player*> players);
    void Move(std::pair<int, int> coordinates, int dice, std::vector<Player*> players);
    void MoveAction(Pawn* pawn, int dice, std::vector<Player*> players);
    void LeaveBase(Pawn* pawn, std::vector<Player*> players);
    void Capture(Pawn* pawn, std::vector<Player*> players);
    void MultipleCapture(Pawn* pawn, std::vector<Player*> players);
    int NrOfPawnsAt(Pawn* pawn, std::vector<Player*> players);
    std::map<int, std::pair<int, int>> GetGreenCoordinates()const;
    std::map<int, std::pair<int, int>> GetYellowCoordinates()const;
    std::map<int, std::pair<int, int>> GetRedCoordinates() const;
    std::map<int, std::pair<int, int>> GetBlueCoordinates() const;

private:
    std::map<int, std::pair<int, int>> m_greenCoordinates;
    std::map<int, std::pair<int, int>> m_yellowCoordinates;
    std::map<int, std::pair<int, int>> m_redCoordinates;
    std::map<int, std::pair<int, int>> m_blueCoordinates;
};