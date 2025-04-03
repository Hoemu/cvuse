#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QOpenGLFunctions"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("WinServer");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_main_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_main);
}

void MainWindow::on_btn_setting_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_setting);
}

void MainWindow::on_btn_other_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_other);
}
