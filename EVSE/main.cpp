#include "ChargingportDetector.h"
#include "ClientSocket.h"
#include <iostream>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cout << "Usage: iot_client <IP> <port> <name>\n" << std::endl;
        return -1;
    }

    const char* server_ip = argv[1];
    const int server_port = atoi(argv[2]);
    std::string id = argv[3];

    // ClientSocket 객체 생성
    ClientSocket client(server_ip, server_port, id);

    // ChargingportDetector 객체 생성
    ChargingportDetector detector;

    // 각 객체를 별도의 스레드로 실행
    pthread_t sndThread, rcvThread, detThread;
    pthread_create(&sndThread, nullptr, &ClientSocket::SendMsgThread, &client);
    pthread_create(&rcvThread, nullptr, &ClientSocket::RecvMsgThread, &client);
    pthread_create(&detThread, nullptr, &ChargingportDetector::DetectPortThread, &detector);

    // 각 객체의 스레드가 종료될 때까지 기다림
    pthread_join(sndThread, nullptr);
    pthread_join(rcvThread, nullptr);
    pthread_join(detThread, nullptr);

    return 0;
}
