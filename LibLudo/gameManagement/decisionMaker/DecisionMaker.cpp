#include "DecisionMaker.h"
DecisionMaker::DecisionMaker()
{
    m_greenCoordinates = {
   {0, {6, 1}}, {1, {6, 2}}, {2, {6, 3}}, {3, {6, 4}}, {4, {6, 5}},
   {5, {5, 6}}, {6, {4, 6}}, {7, {3, 6}}, {8, {2, 6}}, {9, {1, 6}},
   {10, {0, 6}}, {11, {0, 7}}, {12, {0, 8}}, {13, {1, 8}}, {14, {2, 8}},
   {15, {3, 8}}, {16, {4, 8}}, {17, {5, 8}}, {18, {6, 9}}, {19, {6, 10}},
   {20, {6, 11}}, {21, {6, 12}}, {22, {6, 13}}, {23, {6, 14}}, {24, {7, 14}},
   {25, {8, 14}}, {26, {8, 13}}, {27, {8, 12}}, {28, {8, 11}}, {29, {8, 10}},
   {30, {8, 9}}, {31, {9, 8}}, {32, {10, 8}}, {33, {11, 8}}, {34, {12, 8}},
   {35, {13, 8}}, {36, {14, 8}}, {37, {14, 7}}, {38, {14, 6}}, {39, {13, 6}},
   {40, {12, 6}}, {41, {11, 6}}, {42, {10, 6}}, {43, {9, 6}}, {44, {8, 5}},
   {45, {8, 4}}, {46, {8, 3}}, {47, {8, 2}}, {48, {8, 1}}, {49, {8, 0}},
   {50, {7, 0}}, {51, {7, 1}}, {52, {7, 2}}, {53, {7, 3}}, {54, {7, 4}},
   {55, {7, 5}}, {56, {7, 6}}
    };
    m_yellowCoordinates = {
    {0, {1, 8}}, {1, {2, 8}}, {2, {3, 8}}, {3, {4, 8}}, {4, {5, 8}},
    {5, {6, 9}}, {6, {6, 10}}, {7, {6, 11}}, {8, {6, 12}}, {9, {6, 13}},
    {10, {6, 14}}, {11, {7, 14}}, {12, {8, 14}}, {13, {8, 13}}, {14, {8, 12}},
    {15, {8, 11}}, {16, {8, 10}}, {17, {8, 9}}, {18, {9, 8}}, {19, {10, 8}},
    {20, {11, 8}}, {21, {12, 8}}, {22, {13, 8}}, {23, {14, 8}}, {24, {14, 7}},
    {25, {14, 6}}, {26, {13, 6}}, {27, {12, 6}}, {28, {11, 6}}, {29, {10, 6}},
    {30, {9, 6}}, {31, {8, 5}}, {32, {8, 4}}, {33, {8, 3}}, {34, {8, 2}},
    {35, {8, 1}}, {36, {8, 0}}, {37, {7, 0}}, {38, {6, 0}}, {39, {6, 1}},
    {40, {6, 2}}, {41, {6, 3}}, {42, {6, 4}}, {43, {6, 5}}, {44, {5, 6}},
    {45, {4, 6}}, {46, {3, 6}}, {47, {2, 6}}, {48, {1, 6}}, {49, {0, 6}},
    {50, {0, 7}}, {51, {1, 7}}, {52, {2, 7}}, {53, {3, 7}}, {54, {4, 7}},
    {55, {5, 7}}, {56, {6, 7}}
    };
    m_redCoordinates = { {0, {13, 6}}, {1, {12, 6}}, {2, {11, 6}}, {3, {10, 6}}, {4, {9, 6}},
    {5, {8, 5}}, {6, {8, 4}}, {7, {8, 3}}, {8, {8, 2}}, {9, {8, 1}}, {10, {8, 0}},
    {11, {7, 0}}, {12, {6, 0}}, {13, {6, 1}}, {14, {6, 2}}, {15, {6, 3}},
    {16, {6, 4}}, {17, {6, 5}}, {18, {5, 6}}, {19, {4, 6}}, {20, {3, 6}},
    {21, {2, 6}}, {22, {1, 6}}, {23, {0, 6}},
    {24, {0, 7}}, {25, {0, 8}}, {26, {1, 8}}, {27, {2, 8}}, {28, {3, 8}},
    {29, {4, 8}}, {30, {5, 8}}, {31, {6, 9}}, {32, {6, 10}}, {33, {6, 11}},
    {34, {6, 12}}, {35, {6, 13}}, {36, {6, 14}}, {37, {7, 14}}, {38, {8, 14}},
    {39, {8, 13}}, {40, {8, 12}}, {41, {8, 11}}, {42, {8, 10}}, {43, {8, 9}},
    {44, {9, 8}}, {45, {10, 8}}, {46, {11, 8}}, {47, {12, 8}}, {48, {13, 8}},
    {49, {14, 8}}, {50, {14, 7}}, {51, {13, 7}}, {52, {12, 7}}, {53, {11, 7}},
    {54, {10, 7}}, {55, {9, 7}},{56, {8, 7}}
    };
    m_blueCoordinates = {
    {0, {8, 13}}, {1, {8, 12}}, {2, {8, 11}}, {3, {8, 10}}, {4, {8, 9}},
    {5, {9, 8}}, {6, {10, 8}}, {7, {11, 8}}, {8, {12, 8}}, {9, {13, 8}},
    {10, {14, 8}}, {11, {14, 7}}, {12, {14, 6}}, {13, {13, 6}}, {14, {12, 6}},
    {15, {11, 6}}, {16, {10, 6}}, {17, {9, 6}}, {18, {8, 5}}, {19, {8, 4}},
    {20, {8,3}}, {21, {8, 2}}, {22, {8, 1}}, {23, {8, 0}}, {24, {7, 0}},
    {25, {6, 0}}, {26, {6, 1}}, {27, {6, 2}}, {28, {6, 3}}, {29, {6, 4}},
    {30, {6, 5}}, {31, {5, 6}}, {32, {4, 6}}, {33, {3, 6}}, {34, {2, 6}},
    {35, {1, 6}}, {36, {0, 6}}, {37, {0, 7}}, {38, {0, 8}}, {39, {1, 8}},
    {40, {2, 8}}, {41, {3, 8}}, {42, {4, 8}}, {43, {5, 8}}, {44, {6, 9}},
    {45, {6,10}}, {46, {6, 11}}, {47, {6, 12}}, {48, {6, 13}}, {49, {6, 14}},
    {50, {7, 14}}, {51, {7, 13}}, {52, {7, 12}}, {53, {7, 11}}, {54, {7, 10}},
    {55, {7, 9}}, {56, {7, 8}}
    };

}

std::pair<int, int> DecisionMaker::FindPawn(int row, int column, std::vector<Player*> players)
{
    for (size_t playerIndex = 0; playerIndex < players.size(); ++playerIndex)
    {
        const std::vector<Pawn*> pawns = players[playerIndex]->GetPawns();

        for (size_t pawnIndex = 0; pawnIndex < pawns.size(); ++pawnIndex)
        {
            if (pawns[pawnIndex]->GetPawnCoordinates().first == row &&
                pawns[pawnIndex]->GetPawnCoordinates().second == column)
            {
                return { static_cast<int>(playerIndex), static_cast<int>(pawnIndex) };
            }
        }
    }
    return { -1, -1 };
}

void DecisionMaker::Move(std::pair<int, int> coordinates, int dice, std::vector<Player*> players)
{
    auto pawns = players[coordinates.first]->GetPawns();

    if (pawns[coordinates.second]->GetPawnCoordinates() == pawns[coordinates.second]->GetInitialPosition())
    {
        if (dice == 6)
            LeaveBase(pawns[coordinates.second],players);
    }
    else
    {
        MoveAction(pawns[coordinates.second], dice, players);
    }
}

void DecisionMaker::MoveAction(Pawn* pawn, int dice, std::vector<Player*> players)
{
    if (pawn->GetPawnIterator()->first + dice <= 56)
    {
        std::advance(pawn->GetPawnIterator(), dice);
        pawn->SetPawnCoordinates(pawn->GetPawnIterator()->second);
        
        MultipleCapture(pawn, players);
    }
}

void DecisionMaker::LeaveBase(Pawn* pawn, std::vector<Player*> players)
{
    switch (pawn->GetPawnColor())
    {
    case PlayerColor::Green:
        pawn->SetPawnIterator(m_greenCoordinates.begin());
        pawn->SetPawnCoordinates(m_greenCoordinates.begin()->second);
        pawn->SetIsBased(false);
        break;
    case PlayerColor::Yellow:
        pawn->SetPawnIterator(m_yellowCoordinates.begin());
        pawn->SetPawnCoordinates(m_yellowCoordinates.begin()->second);
        pawn->SetIsBased(false);
        break;
    case PlayerColor::Red:
        pawn->SetPawnIterator(m_redCoordinates.begin());
        pawn->SetPawnCoordinates(m_redCoordinates.begin()->second);
        pawn->SetIsBased(false);
        break;
    case PlayerColor::Blue:
        pawn->SetPawnIterator(m_blueCoordinates.begin());
        pawn->SetPawnCoordinates(m_blueCoordinates.begin()->second);
        pawn->SetIsBased(false);
        break;
    }
    MultipleCapture(pawn, players);
}

void DecisionMaker::Capture(Pawn* pawn, std::vector<Player*> players)
{
    for (Player* player : players)
    {
        for (Pawn* otherPawn : player->GetPawns())
        {
            if (otherPawn->IsBased() == false && pawn->IsBased() == false)
            {
                if (otherPawn->GetInitialPosition() != pawn->GetInitialPosition() && otherPawn->GetPawnCoordinates() == pawn->GetPawnCoordinates() && otherPawn->GetPawnColor() != pawn->GetPawnColor())
                {
                    otherPawn->SetPawnCoordinates(otherPawn->GetInitialPosition());
                    otherPawn->SetIsBased(true);
                    break;
                }
            }
        }
    }
}

void DecisionMaker::MultipleCapture(Pawn* pawn, std::vector<Player*> players)
{
    int nrOfCapures = NrOfPawnsAt(pawn, players) - 1;
    while (nrOfCapures != 0)
    {
        Capture(pawn, players);
        nrOfCapures--;
    }
}

int DecisionMaker::NrOfPawnsAt(Pawn* pawn, std::vector<Player*> players)
{
    int nrOfPawns = 0;
    for (Player* player : players)
    {
        for (Pawn* otherPawn : player->GetPawns())
        {
            if (pawn->GetPawnCoordinates() == otherPawn->GetPawnCoordinates())
                nrOfPawns++;
        }
    }

    return nrOfPawns;
}

std::map<int, std::pair<int, int>> DecisionMaker::GetGreenCoordinates() const
{
    return this->m_greenCoordinates;
}

std::map<int, std::pair<int, int>> DecisionMaker::GetYellowCoordinates() const
{
    return this->m_yellowCoordinates;
}

std::map<int, std::pair<int, int>> DecisionMaker::GetRedCoordinates() const
{
    return this->m_redCoordinates;
}

std::map<int, std::pair<int, int>> DecisionMaker::GetBlueCoordinates() const
{
    return this->m_blueCoordinates;
}
