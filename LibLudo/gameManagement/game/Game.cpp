#include "Game.h"

Game & Game::getInstance() {
    static Game instance;
    return instance;
}

void Game::resetGame() {
    for (const auto player : getInstance().m_players) {
        delete player;
    }

    getInstance().m_players.clear();
}

Game::~Game()
{

    for (auto player : m_players) {
        delete player;
    }
    m_players.clear();
}

void Game::VerifyCurrentPlayerWinner()
{
    int nrOfWinPawns = 0;
    for (auto pawn : m_currentPlayer->GetPawns())
    {
        if (pawn->GetPawnCoordinates() == pawn->GetWinPosition())
            nrOfWinPawns++;
    }
    if (nrOfWinPawns == 4)
        m_currentPlayer->SetIsWinner();
}

void Game::InitializePlayers()
{
    std::vector<PlayerColor> colors = { PlayerColor::Green, PlayerColor::Yellow, PlayerColor::Red, PlayerColor::Blue };
    std::vector<std::pair<int, int>> pairs = {
        {2, 2}, {2, 3}, {3, 2}, {3, 3},
        {2, 11}, {2, 12}, {3, 11}, {3, 12},
        {11, 2}, {11, 3}, {12, 2}, {12, 3},
        {11, 11}, {11, 12}, {12, 11}, {12, 12}
    };
    std::vector<std::pair<int, int>>winpair={
        decisionMaker.GetGreenCoordinates().rbegin()->second,
        decisionMaker.GetYellowCoordinates().rbegin()->second,
        decisionMaker.GetRedCoordinates().rbegin()->second,
        decisionMaker.GetBlueCoordinates().rbegin()->second
    };
    for (int i = 0; i < 4; ++i) {
        Player* player = new Player(colors[i]);

        std::vector<Pawn*> pawns;
        for (int j = 0; j < 4; ++j) {
            auto initialPosition = pairs[i * 4 + j];
            auto winPosition = winpair[i];
            Pawn* pawn = new Pawn(
                decisionMaker.GetGreenCoordinates().end(),
                colors[i],
                initialPosition,
                winPosition

            );
            pawn->SetInitialPosition(initialPosition);
            pawn->SetPawnCoordinates( initialPosition);
            pawns.push_back(pawn);
        }

        player->SetPawns(pawns);

        m_players.push_back(player);
    }
}
void Game::Move(int row, int column, int dice)
{
	std::pair<int, int> coordinates = decisionMaker.FindPawn(row, column, m_players);

	if (coordinates.first != -1 && coordinates.second != -1)
	{
        decisionMaker.Move(coordinates, dice, m_players);
	}
    NotifyOnMoveAction();
}

void Game::SetCurrentPlayer(int index)
{
    m_currentPlayer = m_players[index];
}

Player* Game::GetCurrentPlayer()
{
    return m_currentPlayer;
}

uint16_t Game::RollDice()
{
    NotifyOnRollAction();
    return m_dice.roll();
}


std::vector<Player*> Game::GetPlayers() const
{
    return m_players;
}
