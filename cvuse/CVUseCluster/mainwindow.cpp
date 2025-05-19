#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Cluster"); // 集群

    isConnect = false;
    conf = new ConfigSetting;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete conf;
}

void MainWindow::on_btn_send_clicked()
{
    if (isConnect == false)
    {
        return;
    }
    clinet->send(ui->textEdit_eara->text());
}

void MainWindow::readData(QByteArray data)
{
    ui->text_accept->append(data);
}

void MainWindow::on_btn_clear_clicked()
{
    ui->text_accept->clear();
}

void MainWindow::on_btn_connect_clicked()
{
    init();
}

void MainWindow::init()
{
    server = new RemoteUDP(this);
    server->setPort(ui->acceptPort->text().toUInt());
    server->setUDPProtocol(QUdpSocket::ShareAddress);
    connect(server, &RemoteUDP::receiverData, this, &MainWindow::MainWindow::readData);

    clinet = new RemoteUDP(this);
    clinet->setPort(ui->Sendport->text().toUInt());
    clinet->setIPAddr(ui->ip->text());

    isConnect = true;
    ui->label_status->setText("已连接");
}

void MainWindow::on_btn_disconnect_clicked()
{
    if (isConnect == true)
    {
        delete server;
        delete clinet;
        ui->label_status->setText("断开连接");
    }
}
