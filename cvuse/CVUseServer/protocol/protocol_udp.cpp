#include "protocol_udp.h"

ProtocolUDP::ProtocolUDP()
{
#ifdef _WIN32
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);
#endif
}

void ProtocolUDP::server()
{
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    sockaddr_in addr { AF_INET, htons(8080), INADDR_ANY };
    bind(sock, (sockaddr *)&addr, sizeof(addr));

    char buf[1024];
    sockaddr_in client_addr;
    int len = sizeof(client_addr);
    while (true)
    {
        int recv_len = recvfrom(sock, buf, sizeof(buf), 0, (sockaddr *)&client_addr, &len);
        if (recv_len > 0)
        {
            sendto(sock, buf, recv_len, 0, (sockaddr *)&client_addr, len);
        }
    }
}
void ProtocolUDP::send_with_retry(int sock, const char *data, int len, sockaddr_in *server_addr)
{
    char ack_buf[1024];
    struct sockaddr_in from_addr;
    int from_len = sizeof(from_addr);

    for (int i = 0; i < 3; ++i)
    {
        // 发送数据到 server_addr
        sendto(sock, data, len, 0, (sockaddr *)server_addr, sizeof(*server_addr));

        // 设置超时等待 ACK
        fd_set read_set;
        FD_ZERO(&read_set);
        FD_SET(sock, &read_set);
        timeval timeout { 1, 0 }; // 1秒超时

        if (select(sock + 1, &read_set, NULL, NULL, &timeout) > 0)
        {
            // 接收 ACK
            int recv_len = recvfrom(sock, ack_buf, sizeof(ack_buf), 0, (struct sockaddr *)&from_addr, &from_len);

            // 验证 ACK 来源及内容
            if (recv_len > 0)
            {
                // 检查是否为预期服务器（可选）
                if (from_addr.sin_addr.s_addr == server_addr->sin_addr.s_addr && from_addr.sin_port == server_addr->sin_port)
                {
                    // 处理有效 ACK（如校验数据）
                    std::cout << "ACK received: " << ack_buf << std::endl;
                    return;
                }
            }
            else
            {
                // 处理接收错误
                std::cerr << "recvfrom error" << std::endl;
            }
        }
        std::cout << "Retry " << i + 1 << std::endl;
    }
    std::cerr << "Max retries exceeded" << std::endl;
}
