#ifndef PROTOCOL_UDP_H
#define PROTOCOL_UDP_H

#include <chrono>
#include <cstring>
#include <iostream>
#include <thread>
#ifdef _WIN32
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <arpa/inet.h>
#include <unistd.h>
#endif

class ProtocolUDP
{
public:
    ProtocolUDP();

    void server();

    void clint();

    void send_with_retry(int sock, const char* data, int len, sockaddr_in* addr);
};

#endif // PROTOCOL_UDP_H
