﻿#include "UILudo.h"
#include <QtWidgets/QApplication>
#include "LudoGrid.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    //UILudo uiludo;
    //uiludo.show();

    LudoGrid grid;
    grid.setFixedSize(620, 620);
    grid.show();
    grid.UpdateButtonPositions();
    grid.StartGame();
    return app.exec();
}