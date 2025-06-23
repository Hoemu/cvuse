#include "remote_tcp.h"

RemoteTCP::RemoteTCP()
{
    tcp = new QTcpServer;
}

RemoteTCP::~RemoteTCP()
{
    delete tcp;
}

void RemoteTCP::sendMessage() {}

void RemoteTCP::newConnect() {}

void RemoteTCP::readMessage() {}

void RemoteTCP::TCPError(QAbstractSocket::SocketError) {}
