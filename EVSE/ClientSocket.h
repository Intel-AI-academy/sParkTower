// ClientSocket.h
#ifndef CLIENT_SOCKET_H
#define CLIENT_SOCKET_H

#include <string>
#include "GlobalVariables.h"

#define BUF_SIZE 100
#define NAME_SIZE 20
#define ARR_CNT 5

class ClientSocket {
public:
    ClientSocket(const char* server_ip, int server_port, const std::string& id);
    ~ClientSocket();

    void SendMsg();
    void RecvMsg();
    static void* SendMsgThread(void* arg);
    static void* RecvMsgThread(void* arg);
    //void run();

    int client_socket;

private:
    std::string id;
};

#endif // CLIENT_SOCKET_H

