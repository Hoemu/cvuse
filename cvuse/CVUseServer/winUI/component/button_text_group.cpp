#include "button_text_group.h"
#include "ui_button_text_group.h"

ButtonTextGroup::ButtonTextGroup(QWidget *parent) : QWidget(parent), ui(new Ui::ButtonTextGroup)
{
    ui->setupUi(this);
}

ButtonTextGroup::~ButtonTextGroup()
{
    delete ui;
}

void ButtonTextGroup::setStyleSheet(const QString &styleSheet)
{
    qDebug() << styleSheet;
    // qssTool.switchTo("background-color:;", ui->picture); // 在把当前
    ui->picture->setStyleSheet(styleSheet);
}
