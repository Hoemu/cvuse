#include "other_page.h"
#include "ui_other_page.h"

OtherPage::OtherPage(QWidget *parent) : QWidget(parent), ui(new Ui::OtherPage)
{
    udp = new UDPServer(this);
    udp->setPort(7777);

    connect(udp, &UDPServer::receiverData, this, &OtherPage::readData);

    ui->setupUi(this);
    group.addButton(ui->btn_test1);
    group.addButton(ui->btn_test2);

    groupUdpServer.addButton(ui->checkBox_Yes);
    groupUdpServer.addButton(ui->checkBox_No);
}

OtherPage::~OtherPage()
{
    delete ui;
}

void OtherPage::on_btn_udp_test_send_clicked()
{
    QString data = ui->lineEdit_UDP_SEND->text();
    udp->send(data.toLatin1());
}

void OtherPage::on_checkBox_Yes_clicked()
{
    udp->disUDPProtocol();
}

void OtherPage::on_checkBox_No_clicked()
{
    udp->setUDPProtocol(QUdpSocket::ShareAddress);
}

void OtherPage::readData(QByteArray data)
{
    ui->editeEara->appendPlainText(QString(data));
}
