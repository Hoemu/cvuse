#ifndef PROTOCOL_UDP_H
#define PROTOCOL_UDP_H

#include <QUdpSocket>

class ProtocolUDP : public QObject
{
public:
    ProtocolUDP(QObject *parent = nullptr);

    void setIP(const QString &ip);

    void setPort(const quint16 &port);

    /** 接收数据 */
    void processPendingDatagrams();

    /** 发送数据 */
    void send(const QByteArray &data);

private:
    QUdpSocket *udpServer;

    QString ip;

    quint16 port;

    QHostAddress addr;
};

#endif // PROTOCOL_UDP_H
