#ifndef UDP_SERVER_H
#define UDP_SERVER_H

#include <QObject>
#include <QUdpSocket>

class UDPServer : public QObject
{
    Q_OBJECT
public:
    UDPServer(QObject *parent);

    void send(const QString &msg);

    void setPort(const quint64 &port);

    void setUDPProtocol(const QUdpSocket::BindFlag &protocol);

    void disUDPProtocol();

signals:
    void receiverData(QByteArray data);

protected slots:
    void processPendingDatagram();

private:
    QUdpSocket *udp;

    quint64 port;

    QUdpSocket::BindFlag protocol;

    bool isUse;
};

#endif // UDP_SERVER_H
