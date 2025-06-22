#include "remote_tcp.h"

RemoteTCP::RemoteTCP()
{
    tcp = new QTcpServer;
}

RemoteTCP::~RemoteTCP()
{
    delete tcp;
}
