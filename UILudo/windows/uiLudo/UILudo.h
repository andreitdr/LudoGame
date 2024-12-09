#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_UILudo.h"
#include <vector>

class UILudo : public QMainWindow
{
    Q_OBJECT

public:
    UILudo(QWidget *parent = nullptr);
    ~UILudo();
    void InitializeBoard();

private slots:

private:

    Ui::UILudoClass ui;
};
