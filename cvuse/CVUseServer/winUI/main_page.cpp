#include "main_page.h"
#include "ui_main_page.h"

MainPage::MainPage(QWidget *parent) : QWidget(parent), ui(new Ui::MainPage)
{
    ui->setupUi(this);
}

MainPage::~MainPage()
{
    delete ui;
}
