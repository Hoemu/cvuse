#include "udp_page.h"
#include "ui_udp_page.h"

UDPPage::UDPPage(QWidget *parent) : QWidget(parent), ui(new Ui::UDPPage)
{
    ui->setupUi(this);
    isConnect = false;
    server = nullptr;
    clinet = nullptr;
}

UDPPage::~UDPPage()
{
    delete ui;
}

void UDPPage::on_btn_connect_clicked()
{
    quint64 currentSendPort = ui->doubleSpinBox_SendPort->value();
    quint64 currentAcceptPort = ui->doubleSpinBox_AcceptPort->value();
    QString currentIP = ui->ip->text();

    if (isConnect == true && (server->getIPAddr() == currentIP || server->getPort() == currentAcceptPort || clinet->getPort() == currentSendPort))
    {
        return;
    }
    cancelConnect();
    init();
    isConnect = true;
    clinet->sendData(ui->textEdit_eara->text());
}

void UDPPage::on_btn_disconnect_clicked()
{
    if (isConnect == true)
    {
        cancelConnect();
    }
    isConnect = false;
}

void UDPPage::readData(QByteArray data)
{
    ui->text_accept->append(data);
}

void UDPPage::init()
{
    server = new RemoteUDP(this);
    server->setPort(ui->doubleSpinBox_AcceptPort->value());
    server->setUDPProtocol(QUdpSocket::ShareAddress);
    connect(server, &RemoteUDP::receiverData, this, &UDPPage::readData);

    clinet = new RemoteUDP(this);
    clinet->setPort(ui->doubleSpinBox_SendPort->value());
    clinet->setIPAddr(ui->ip->text());

    ui->label_status->setText("已连接");
}

void UDPPage::cancelConnect()
{
    if (server == nullptr || clinet == nullptr)
    {
        return;
    }
    delete server;
    server = nullptr;
    delete clinet;
    clinet = nullptr;
    ui->label_status->setText("断开连接");
}

void UDPPage::on_btn_clear_clicked()
{
    ui->text_accept->clear();
}

void UDPPage::on_btn_send_clicked()
{
    if (clinet != nullptr)
    {
        clinet->sendData(ui->textEdit_eara->text());
    }
}
