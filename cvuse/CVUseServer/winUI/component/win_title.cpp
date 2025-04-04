#include "win_title.h"
#include "ui_win_title.h"

WinTitle::WinTitle(QWidget *parent) : QWidget(parent), ui(new Ui::WinTitle)
{
    ui->setupUi(this);
}

WinTitle::~WinTitle()
{
    delete ui;
}
