#include "protocol_udp.h"

ProtocolUDP::ProtocolUDP(QObject *parent) : QObject(parent)
{
    udpServer = new QUdpSocket(this);

    if (!udpServer->bind(QHostAddress::AnyIPv4, 12345))
    { // 绑定本地 IPv4 地址和端口
        qDebug() << "绑定失败：" << udpServer->errorString();
    }

    connect(udpServer, &QUdpSocket::readyRead, this, &ProtocolUDP::processPendingDatagrams);
}

void ProtocolUDP::setIP(const QString &ip)
{
    addr.setAddress(ip);
}

void ProtocolUDP::setPort(const quint16 &port)
{
    this->port = port;
}

void ProtocolUDP::processPendingDatagrams()
{
    while (udpServer->hasPendingDatagrams())
    {
        QByteArray datagram;
        QHostAddress sender;
        quint16 senderPort;
        datagram.resize(udpServer->pendingDatagramSize());
        // 读取数据报和来源信息
        udpServer->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
        qDebug() << "来自" << sender << ":" << senderPort << "的数据：" << datagram;
    }
}

void ProtocolUDP::send(const QByteArray &data)
{
    QHostAddress targetAddr(ip);
    quint16 targetPort = port;
    qint64 bytesSent = udpServer->writeDatagram(data, targetAddr, targetPort);
    if (bytesSent == -1)
    {
        qDebug() << "发送失败：" << udpServer->errorString();
    }
    else
    {
        qDebug() << "发送成功：" << data.toStdString();
    }
}
