#include "remote_udp.h"

RemoteUDP::RemoteUDP(QObject *parent) : QObject(parent)
{
    udp = new QUdpSocket(this);

    connect(udp, &QUdpSocket::errorOccurred, this, &RemoteUDP::UDPError);
}

void RemoteUDP::send(const QString &msg, QHostAddress *host)
{
    if (host == nullptr)
    {
        *host = QHostAddress::Broadcast;
    }
    QByteArray sendData = msg.toLatin1();
    udp->writeDatagram(sendData.data(), sendData.size(), *host, port);
}

void RemoteUDP::setPort(const quint64 &port)
{
    qDebug() << "bind server port:" << port;
    this->port = port;
}

void RemoteUDP::setIPAddr(const QString &ipV4)
{
    addr.setAddress(ipV4);
}

void RemoteUDP::setUDPProtocol(const QAbstractSocket::BindFlag &protocol, QHostAddress *host)
{
    QHostAddress add = *host;
    if (host != nullptr)
    {
        addr = add;
    }
    qDebug() << "bind server port:" << port;
    this->protocol = protocol;
    udp->bind(port, protocol);

    connect(udp, &QUdpSocket::readyRead, this, &RemoteUDP::processPendingDatagram);
}

void RemoteUDP::processPendingDatagram()
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

void RemoteUDP::UDPError(QAbstractSocket::SocketError error)
{
    qDebug() << error;
}
