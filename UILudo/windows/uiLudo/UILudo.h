#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_UILudo.h"
#include <vector>

/**
 * @class UILudo
 * @brief Represents the main window for the Ludo game UI.
 */
class UILudo : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a new UILudo object.
     * @param parent The parent widget.
     */
    UILudo(QWidget *parent = nullptr);

    /**
     * @brief Destroys the UILudo object.
     */
    ~UILudo();

    /**
     * @brief Initializes the game board.
     */
    void InitializeBoard();

    private slots:

    private:
    Ui::UILudoClass ui; ///< The UI components for the main window.
};