#include "remote_tcp.h"

RemoteTCP::RemoteTCP()
{
    tcp = new QTcpSocket;
}

RemoteTCP::~RemoteTCP()
{
    delete tcp;
}
