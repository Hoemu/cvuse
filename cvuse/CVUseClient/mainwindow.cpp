#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QOpenGLFunctions"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("WinClient");
}

MainWindow::~MainWindow()
{
    delete ui;
}
