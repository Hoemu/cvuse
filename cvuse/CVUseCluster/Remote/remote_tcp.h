#ifndef REMOTE_TCP_H
#define REMOTE_TCP_H

#include <QQueue>
#include <QTcpServer>
#include <QTcpSocket>
#include <QThread>

class RemoteTCP : public QObject
{
    Q_OBJECT
public:
    RemoteTCP();
    ~RemoteTCP();

    void sendData();

    bool linkTCP();

signals:
    void receiverData(QByteArray data);

    void signalTCPError(QString);

private slots:
    void sendMessage();
    void newConnect();
    void readMessage();
    void TCPError(QAbstractSocket::SocketError);

private:
    QTcpServer *tcp;

    QTcpSocket *tcpSocket;

    QString message;

    // 用来存放数据的大小信息
    quint16 blockSize;

    bool isLinkTCP;

    QQueue<QString> msgStack;
};

#endif // REMOTE_TCP_H
