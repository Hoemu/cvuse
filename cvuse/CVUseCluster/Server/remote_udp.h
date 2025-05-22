#ifndef REMOTE_UDP_H
#define REMOTE_UDP_H

#include <QObject>
#include <QUdpSocket>

typedef const unsigned int muint;

class RemoteUDP : public QObject
{
    Q_OBJECT
    using const_protocol = const QHostAddress::SpecialAddress;
    using const_bindFlag = const QUdpSocket::BindFlag;

public:
    RemoteUDP(QObject *parent = nullptr);
    ~RemoteUDP();

    void send(const QString &msg);

    void setPort(const quint64 &port);

    void setIPAddr(const QString &ipV4);

    /** 设置 UDP 协议 */
    void setUDPProtocol(const_bindFlag &protocol, const_protocol &protocolAddr = QHostAddress::Null);

    /** 设置为组播模式 */
    void setMulticastGroup();

    /** 设置为广播模式 */
    void setBroadcast();

    /** 设置为单播模式 */
    void setUnicast();

    /** 设置为任播模式 */
    void setAnycast();

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
