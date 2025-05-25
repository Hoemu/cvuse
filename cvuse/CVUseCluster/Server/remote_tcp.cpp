#include "remote_tcp.h"

RemoteTCP::RemoteTCP()
{
    tcp = new QTcpServer;
}

RemoteTCP::~RemoteTCP()
{
    delete tcp;
}

bool RemoteTCP::linkTCP()
{
    connect(tcp, &QTcpServer::newConnection, this, &RemoteTCP::sendMessage);
    isLinkTCP = true;
}

void RemoteTCP::sendMessage()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);

    // 设置数据流的版本，客户端和服务器端使用的版本要相同
    out.setVersion(QDataStream::Qt_6_8);
    out << (quint16)0;
    out << QString("hello TCP!!!");
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));

    // 获取已经建立的连接的套接字
    tcpSocket = tcp->nextPendingConnection();
    connect(tcpSocket, &QTcpSocket::disconnected, tcpSocket, &QTcpSocket::deleteLater);
    tcpSocket->write(block);
    tcpSocket->disconnectFromHost();

    // 发送数据成功后，显示提示
    // ui->label->setText(tr("发送数据成功!!!"));
}

void RemoteTCP::newConnect()
{
    blockSize = 0;

    // 取消已有的连接
    tcpSocket->abort();
    isLinkTCP = false;
    // tcpSocket->connectToHost(ui->hostLineEdit->text(), ui->portLineEdit->text().toInt());
}

void RemoteTCP::readMessage()
{
    qDebug() << "readMessage:";
    QDataStream in(tcpSocket);

    // 设置数据流版本，这里要和服务器端相同
    in.setVersion(QDataStream::Qt_6_8);

    // 如果是刚开始接收数据
    if (blockSize == 0)
    {
        // 判断接收的数据是否大于两字节，也就是文件的大小信息所占的空间
        // 如果是则保存到blockSize变量中，否则直接返回，继续接收数据
        if (tcpSocket->bytesAvailable() < (int)sizeof(quint16))
            return;
        in >> blockSize;
        qDebug() << "blockSize: " << blockSize;
    }
    // 如果没有得到全部的数据，则返回，继续接收数据
    if (tcpSocket->bytesAvailable() < blockSize)
        return;
    // 将接收到的数据存放到变量中
    in >> message;
    // 显示接收到的数据
    qDebug() << "message: " << message;
    // ui->messageLabel->setText(message);
    msgStack.push_back(message);

    // emit receiverData(in.device());
}

void RemoteTCP::TCPError(QAbstractSocket::SocketError)
{
    emit signalTCPError(tcpSocket->errorString());
}
