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
