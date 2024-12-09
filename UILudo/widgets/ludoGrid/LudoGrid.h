#ifndef LUDOGRID_H
#define LUDOGRID_H

#include <QWidget>
#include <QPushButton>
#include <vector>
#include <utility>
#include "gameManagement/game/Game.h"
#include <QLabel>
#include <qgridlayout.h>

class LudoGrid : public QWidget
{
    Q_OBJECT

public:
    explicit LudoGrid(QWidget* parent = nullptr);

public:
    void InitializeBoard();
    void InitializePawnsColors();
    void InitializeObserver();
    void OnCellClicked(int row, int col);
    void DiceRoll();
    void TransformToButtonPositions(const std::vector<Player*>& players);
    void UpdateButtonPositions();
    void UpdatePawnButtonStates();
    void StartGame();
    void ChangePlayer();
    void ResetGame();
    void FinalMessage();

private:
    std::pair<int, int>m_lastPosition;
    QList<std::pair<int, int>> buttonPositions;
    QPushButton* m_diceButton;
    QLabel* m_diceLabel;  
    QLabel* m_playerLabel;  
    std::vector<QPushButton*> m_pawns;
    QString m_board[15][15];
    QGridLayout* m_gridLayout;
    int m_currentPlayerIndex; 
    int m_lastDiceRoll;    
    bool m_waitingForDice;    
    bool m_waitingForMove;
    int m_nrOfsSx;
};

#endif 
