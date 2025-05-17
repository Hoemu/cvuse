#ifndef REMOTE_UDP_H
#define REMOTE_UDP_H

#include <QObject>
#include <QUdpSocket>

class RemoteUDP : public QObject
{
    Q_OBJECT
public:
    RemoteUDP(QObject *parent = nullptr);

    void send(const QString &msg, QHostAddress *host = nullptr);

    void setPort(const quint64 &port);

    void setIPAddr(const QString &ipV4);

    void setUDPProtocol(const QUdpSocket::BindFlag &protocol, QHostAddress *host = nullptr);

signals:
    void receiverData(QByteArray data);

protected slots:
    void processPendingDatagram();

    void UDPError(QAbstractSocket::SocketError error);

private:
    QUdpSocket *udp;

    quint16 port;

    QHostAddress addr;

    QString ipV4;

    QUdpSocket::BindFlag protocol;
};

#endif // REMOTE_UDP_H
