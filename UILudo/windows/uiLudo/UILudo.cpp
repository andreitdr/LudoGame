#include "UILudo.h"
#include <QPushButton>

UILudo::UILudo(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

     this->setStyleSheet("background-image: url(images/background4.jpg);"
        "background-repeat: no-repeat;"
        "background-position: center;");


    
}

UILudo::~UILudo()
{
}


