#include "other_page.h"
#include "ui_other_page.h"

OtherPage::OtherPage(QWidget *parent) : QWidget(parent), ui(new Ui::OtherPage)
{
    ui->setupUi(this);
}

OtherPage::~OtherPage()
{
    delete ui;
}
