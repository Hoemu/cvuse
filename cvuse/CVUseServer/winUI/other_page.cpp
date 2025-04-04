#include "other_page.h"
#include "ui_other_page.h"

OtherPage::OtherPage(QWidget *parent) : QWidget(parent), ui(new Ui::OtherPage)
{
    ui->setupUi(this);
    group.addButton(ui->btn_test1);
    group.addButton(ui->btn_test2);
}

OtherPage::~OtherPage()
{
    delete ui;
}
