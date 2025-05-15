#include "udp_server.h"

UDPServer::UDPServer(QObject *parent) : QObject(parent)
{
    udp = new QUdpSocket(this);
    isUse = false;
}

void UDPServer::send(const QString &msg)
{
    QByteArray sendData = msg.toLatin1();
    udp->writeDatagram(sendData.data(), sendData.size(), QHostAddress::Broadcast, port);
}

void UDPServer::setPort(const quint64 &port)
{
    qDebug() << "bind server port:" << port;
    this->port = port;
}

void UDPServer::setUDPProtocol(const QAbstractSocket::BindFlag &protocol)
{
    qDebug() << "bind server port:" << port;
    this->protocol = protocol;
    udp->bind(port, protocol);
    isUse = true;
    connect(udp, &QUdpSocket::readyRead, this, &UDPServer::processPendingDatagram);
}

void UDPServer::disUDPProtocol()
{
    if (isUse == false)
    {
        return;
    }
    isUse = false;
    disconnect(udp, &QUdpSocket::readyRead, this, &UDPServer::processPendingDatagram);
}

void UDPServer::processPendingDatagram()
{
    while (udp->hasPendingDatagrams())
    {
        QByteArray datagram;
        // 让datagram的大小为等待处理的数据报的大小，这样才能接收到完整的数据
        datagram.resize(udp->pendingDatagramSize());

        // 接收数据报，将其存放到datagram中
        udp->readDatagram(datagram.data(), datagram.size());
        emit receiverData(datagram);
        qDebug() << "accpet msg:" << QString(datagram);
    }
}
