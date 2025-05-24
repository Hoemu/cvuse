#ifndef REMOTE_TCP_H
#define REMOTE_TCP_H

#include <QTcpSocket>

class RemoteTCP
{
public:
    RemoteTCP();
    ~RemoteTCP();

    void sendData();

signals:
    void receiverData(QByteArray data);

private:
    QTcpSocket *tcp;
};

#endif // REMOTE_TCP_H
