#include "LudoGrid.h"
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include "model/dice/Dice.h"
#include "QTimer"

LudoGrid::LudoGrid(QWidget* parent)
    : QWidget(parent) {
    InitializeBoard(); 
    m_lastPosition = { -1,-1 };
    InitializeObserver();
    Game::getInstance().InitializePlayers();
    auto players = Game::getInstance().GetPlayers();

    TransformToButtonPositions(players);
    m_gridLayout = new QGridLayout();
    m_gridLayout->setSpacing(1);

    for (int row = 0; row < 15; ++row) {
        for (int col = 0; col < 15; ++col) {
            QLabel* label = new QLabel(this);
            label->setFixedSize(40, 40);
            label->setStyleSheet("background-color: " + m_board[row][col] + "; border: 0.5px solid black; border-radius: 5px;");
            m_gridLayout->addWidget(label, row, col);

            if (buttonPositions.contains(std::pair<int, int>(row, col))) {
                QWidget* buttonWidget = new QWidget(this);
                QVBoxLayout* layout = new QVBoxLayout(buttonWidget);
                layout->setAlignment(Qt::AlignCenter);
                QPushButton* button = new QPushButton(this);
                button->setFixedSize(20, 20);
                QString pawnColor = "lightgreen";
                button->setStyleSheet("background-color: " + pawnColor + "; border: 0.5px solid black;");

                layout->addWidget(button);
                m_gridLayout->addWidget(buttonWidget, row, col);

                connect(button, &QPushButton::clicked, this, [this, row, col]() {
                    OnCellClicked(row, col);
                    });

                m_pawns.push_back(button);
            }
        }
    }

    InitializePawnsColors();

    m_diceButton = new QPushButton("Zar", this);
    m_diceButton->setFixedSize(60, 40);
    {
        m_diceButton->setStyleSheet(
            "QPushButton {"
            "    background-color: #77dd77;"
            "    color: white;"
            "    font-size: 14px;"
            "    border-radius: 10px;"
            "    border: 2px solid #379634;"
            "}"
            "QPushButton:hover {"
            "    background-color: #56c456;"
            "    border-color: #2e8133;"
            "}"
            "QPushButton:pressed {"
            "    background-color: #3da03d;"
            "}"
        );
    }

    connect(m_diceButton, &QPushButton::clicked, this, &LudoGrid::DiceRoll);

    m_diceLabel = new QLabel(" ", this); 
    m_diceLabel->setAlignment(Qt::AlignCenter);
    m_diceLabel->setStyleSheet("font-size: 20px; font-weight: bold;");
    m_playerLabel = new QLabel(" ", this);
    m_playerLabel->setAlignment(Qt::AlignCenter);
    m_playerLabel->setStyleSheet("");


    QVBoxLayout* diceLayout = new QVBoxLayout();
    diceLayout->addWidget(m_diceButton);
    diceLayout->addWidget(m_diceLabel);
    diceLayout->addWidget(m_playerLabel);
    diceLayout->setAlignment(Qt::AlignCenter); 


    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->addLayout(m_gridLayout);  
    mainLayout->addLayout(diceLayout);  

    setLayout(mainLayout);
}
void LudoGrid::InitializeBoard()
{
    QString tempBoard[15][15] = {
    {"green","green","green","green","green","green","white","white","white","yellow","yellow","yellow","yellow","yellow","yellow"},
    {"green","white","white","white","white","green","white","yellow","yellow","yellow","white","white","white","white","yellow"},
    {"green","white","green","green","white","green","white","yellow","white","yellow","white","yellow","yellow","white","yellow" },
    {"green","white","green","green","white","green","white","yellow","white","yellow","white","yellow","yellow","white","yellow" },
    {"green","white","white","white","white","green","white","yellow","white","yellow","white","white","white","white","yellow" },
    {"green","green","green","green","green","green","white","yellow","white","yellow","yellow","yellow","yellow","yellow","yellow" },
    {"white","green","white","white","white","white","pink","yellow","pink","white","white","white","white","white","white"},
    {"white","green","green","green","green","green","green","pink","blue","blue","blue","blue","blue","blue","white"},
    {"white","white","white","white","white","white","pink","red","pink","white","white","white","white","blue","white"},
    {"red","red","red","red","red","red","white","red","white","blue","blue","blue","blue","blue","blue"},
    {"red","white","white","white","white","red","white","red","white","blue","white","white","white","white","blue"},
    {"red","white","red","red","white","red","white","red","white","blue","white","blue","blue","white","blue"},
    {"red","white","red","red","white","red","white","red","white","blue","white","blue","blue","white","blue"},
    {"red","white","white","white","white","red","red","red","white","blue","white","white","white","white","blue"},
    {"red","red","red","red","red","red","white","white","white","blue","blue","blue","blue","blue","blue"},
    };

    for (int row = 0; row < 15; ++row) {
        for (int col = 0; col < 15; ++col) {
            m_board[row][col] = tempBoard[row][col];
        }
    }
}

void LudoGrid::InitializeObserver()
{
    IObserver* dice = new Dice();
    Game::getInstance().AddObserver(dice);
}

void LudoGrid::InitializePawnsColors()
{

    QStringList pawnColors = {
        "lightgreen", "lightgreen", "lightgreen", "lightgreen",
        "lightyellow", "lightyellow", "lightyellow", "lightyellow",
        "coral", "coral", "coral", "coral", 
        "lightblue", "lightblue", "lightblue", "lightblue"
    };

    for (int i = 0; i < m_pawns.size(); ++i) {
        QString style = QString("background-color: %1; border: 0.5px solid black; border-radius: 10px;").arg(pawnColors[i]);
        m_pawns[i]->setStyleSheet(style);
    }
}

void LudoGrid::OnCellClicked(int row, int col) {
    if (!m_waitingForMove) return; 

    m_lastPosition = std::make_pair(row, col);

    Game::getInstance().Move(m_lastPosition.first, m_lastPosition.second, m_lastDiceRoll);
    Game::getInstance().VerifyCurrentPlayerWinner();
    UpdateButtonPositions();
    FinalMessage();
    m_waitingForMove = false;
    ChangePlayer();
}
void LudoGrid::DiceRoll() {
    if (!m_waitingForDice) return;

    m_lastDiceRoll = Game::getInstance().RollDice();
    m_diceLabel->setText(QString("%1").arg(m_lastDiceRoll));

    UpdatePawnButtonStates();

    m_diceLabel->setStyleSheet("font-weight: bold; font-size: 20px; color: white;");
    auto currentPlayer = Game::getInstance().GetCurrentPlayer();
    if ((currentPlayer->HasAllPawnsInBase() && m_lastDiceRoll != 6 )||(currentPlayer->HasAllPawnsInactive()&& m_lastDiceRoll != 6)) {
        QTimer::singleShot(1000, this, &LudoGrid::ChangePlayer);
        return;
    }
    m_waitingForDice = false;
    m_waitingForMove = true;
}

void LudoGrid::TransformToButtonPositions(const std::vector<Player*>& players)
{
    buttonPositions.clear();

    for (const auto& player : players) 
    {
        const auto& pawns = player->GetPawns(); 
        for (const auto& pawn : pawns) 
        {
            auto coordinates = pawn->GetPawnCoordinates();
            buttonPositions.append(std::pair<int, int>(coordinates.first, coordinates.second));
        }
    }
}


void LudoGrid::UpdateButtonPositions() {

    for (auto button : m_pawns) {
        delete button->parentWidget();
    }
    m_pawns.clear();
    auto players = Game::getInstance().GetPlayers();
    TransformToButtonPositions(players);
    for (const auto& position : buttonPositions) {
        int row = position.first;
        int col = position.second;

        QWidget* buttonWidget = new QWidget(this);
        QVBoxLayout* layout = new QVBoxLayout(buttonWidget);
        layout->setAlignment(Qt::AlignCenter);
        QPushButton* button = new QPushButton(this);
        button->setFixedSize(20, 20);

        layout->addWidget(button);
        m_gridLayout->addWidget(buttonWidget, row, col);


        connect(button, &QPushButton::clicked, this, [this, row, col]() {
            OnCellClicked(row, col);
            });


        m_pawns.push_back(button);
    }

    InitializePawnsColors();

    this->update();
}

void LudoGrid::UpdatePawnButtonStates()
{
    m_playerLabel->setStyleSheet("");
    for (auto* button : m_pawns) {
        button->setEnabled(false);
    }
    auto currentPlayer = Game::getInstance().GetPlayers()[m_currentPlayerIndex];
    PlayerColor currentColor = currentPlayer->GetColor();
    QString style;
    for (int i = 0; i < m_pawns.size(); ++i) 
    {
        QPushButton* button = m_pawns[i];
        for (const auto& pawn : currentPlayer->GetPawns()) 
        {
            if (buttonPositions[i] == std::pair<int, int>(pawn->GetPawnCoordinates().first, pawn->GetPawnCoordinates().second)) 
            {
                if (pawn->GetPawnCoordinates() == pawn->GetWinPosition())
                {
                    style = button->styleSheet();
                    button->setEnabled(false);
                    break;
                }
                else if (pawn->IsBased() && m_lastDiceRoll != 6) 
                {

                    style = button->styleSheet(); 
                    button->setEnabled(false);
                    break;
                }
                else {

                    button->setEnabled(true);
                    style = button->styleSheet();
                    break;
                }

            }
        }
    }

    if (!style.isEmpty()) {
        m_playerLabel->setStyleSheet(style);
    }
}

void LudoGrid::ChangePlayer() 
{
        if (m_lastDiceRoll == 6)
        {
            m_nrOfsSx++;
            if (m_nrOfsSx == 2)
            {
                m_currentPlayerIndex++;
                m_nrOfsSx = 0;
            }
        }
        else
        {
            m_currentPlayerIndex++;
            m_nrOfsSx = 0;
        }

        m_currentPlayerIndex = m_currentPlayerIndex % Game::getInstance().GetPlayers().size();
        Game::getInstance().SetCurrentPlayer(m_currentPlayerIndex);
        m_waitingForDice = true;
        m_waitingForMove = false;
        m_diceLabel->setText("");
        UpdatePawnButtonStates();
}

void LudoGrid::ResetGame()
{

    m_currentPlayerIndex = 0;
    m_lastPosition = { -1, -1 };
    m_nrOfsSx = 0;
    m_waitingForDice = true;
    m_waitingForMove = false;

    Game::resetGame();
    Game::getInstance().InitializePlayers();
    UpdateButtonPositions(); 
    InitializePawnsColors(); 
    m_diceLabel->setText(" ");
    m_playerLabel->setText(" ");

    StartGame();
}

void LudoGrid::FinalMessage()
{
    int nrOfWinners = 0;

    for (const auto& player : Game::getInstance().GetPlayers())
    {
        if (player->IsWinner())
        {
            QMessageBox::information(this, "Winner", "Jocul s-a terminat!");

            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(
                this,
                "Joc nou",
                "Doriti sa începeti un joc nou?",
                QMessageBox::Yes | QMessageBox::No
            );

            if (reply == QMessageBox::Yes) {
                ResetGame(); 
            }
            else {
                close(); 
            }

            return;
        }
    }
}

void LudoGrid::StartGame() 
{
    m_currentPlayerIndex = 0;
    Game::getInstance().SetCurrentPlayer(m_currentPlayerIndex);
    m_waitingForDice = true;
    m_waitingForMove = false;
    UpdatePawnButtonStates();
    UpdateButtonPositions();
    InitializePawnsColors();
}