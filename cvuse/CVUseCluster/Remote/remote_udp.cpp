#include "remote_udp.h"

RemoteUDP::RemoteUDP(QObject *parent) : QObject(parent)
{
    udp = new QUdpSocket(this);
    addr = new QHostAddress;
    addr->setAddress(QHostAddress::Broadcast);

    connect(udp, &QUdpSocket::errorOccurred, this, &RemoteUDP::UDPError);
}

RemoteUDP::~RemoteUDP()
{
    udp->abort();
    udp->close();

    delete addr;
}

void RemoteUDP::sendData(const QString &msg)
{
    QByteArray sendData = msg.toLatin1();
    quint16 res = udp->writeDatagram(sendData.data(), sendData.size(), *addr, port);
}

void RemoteUDP::setPort(const quint64 &port)
{
    qDebug() << "bind server port:" << port;
    this->port = port;
}

void RemoteUDP::setIPAddr(const QString &ipV4)
{
    addr->setAddress(ipV4);
}

void RemoteUDP::setUDPProtocol(const_bindFlag &protocol, const_protocol &protocolAddr)
{
    this->protocol = protocol;

    if (protocolAddr != QHostAddress::Null)
    {
        addr->setAddress(protocolAddr);
        udp->bind(protocolAddr, 8080, protocol);
        qDebug() << "protocol address is null.";
    }
    else
    {
        udp->bind(port, protocol);
    }
    qDebug() << "bind server protocol:" << port;

    connect(udp, &QUdpSocket::readyRead, this, &RemoteUDP::processPendingDatagram);
}

void RemoteUDP::setMulticastGroup() {}

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
