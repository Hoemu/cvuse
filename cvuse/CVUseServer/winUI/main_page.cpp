#include "main_page.h"
#include "ui_main_page.h"

MainPage::MainPage(QWidget *parent) : QWidget(parent), ui(new Ui::MainPage)
{
    ui->setupUi(this);

    group.addButton(ui->btn_fileServer);
    group.addButton(ui->btn_playServer);
}

MainPage::~MainPage()
{
    delete ui;
}

void MainPage::on_btn_playServer_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_play);
}

void MainPage::on_btn_fileServer_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_file);
}
