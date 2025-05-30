#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Cluster"); // 集群

    conf = new ConfigSetting;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete conf;
}

void MainWindow::on_btn_UDP_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_udp);
}

void MainWindow::on_btn_TCP_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_tcp);
}
