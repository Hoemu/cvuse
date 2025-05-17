#ifndef REMOTE_UDP_H
#define REMOTE_UDP_H

#include <QObject>
#include <QUdpSocket>

class RemoteUDP : public QObject
{
    Q_OBJECT
public:
    RemoteUDP(QObject *parent = nullptr);
    ~RemoteUDP();

    void send(const QString &msg);

    void setPort(const quint64 &port);

    void setIPAddr(const QString &ipV4);

    void setUDPProtocol(const QUdpSocket::BindFlag &protocol);

signals:
    void receiverData(QByteArray data);

protected slots:
    void processPendingDatagram();

    void UDPError(QAbstractSocket::SocketError error);

private:
    QUdpSocket *udp;

    quint16 port;

    QString ipV4;

    QHostAddress *addr;

    QUdpSocket::BindFlag protocol;
};

#endif // REMOTE_UDP_H
