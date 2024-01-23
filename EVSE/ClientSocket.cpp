// ClientSocket.cpp
#include "ClientSocket.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

char name[NAME_SIZE]="[Default]";
char msg[BUF_SIZE];

ClientSocket::ClientSocket(const char* server_ip, int server_port, const std::string& id) {
    // 소켓 생성
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    this->client_socket = client_socket;
    if (client_socket == -1) {
        std::cerr << "Error: 소켓 생성 실패" << std::endl;
        exit(EXIT_FAILURE);
    }

    // 서버에 연결
    sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(server_port);
    if (inet_pton(AF_INET, server_ip, &server_address.sin_addr) <= 0) {
        std::cerr << "Error: 주소 변환 실패" << std::endl;
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    if (connect(client_socket, reinterpret_cast<sockaddr*>(&server_address), sizeof(server_address)) == -1) {
        std::cerr << "Error: 서버에 연결 실패" << std::endl;
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    this->id = id;

    // 클라이언트 접속
    std::string msg = "[" + id + ":PASSWD]";

    // 서버로 접속
    if (send(client_socket, msg.c_str(), msg.size(), 0) == -1) {
        std::cerr << "Error: 서버 접속 실패" << std::endl;
    }
}

ClientSocket::~ClientSocket() {
    // 소켓 닫기
    close(client_socket);
}

void ClientSocket::SendMsg() {
    // 전달된 인자로부터 소켓 디스크립터를 가져옴
    char name_msg[NAME_SIZE + BUF_SIZE + 2];  // 메시지와 ID를 저장할 배열

    // 사용자에게 메시지 입력 안내 출력
    fputs("Input a message! [ID]msg (Default ID:ALLMSG)\n",stdout);

    while(1) {
	// Lock the mutex before accessing the shared data
        std::unique_lock<std::mutex> lock(mtx);

        // Wait for a message to be available or for the producer to finish
        conv.wait(lock, []{ return !messageQueue.empty(); });

        // Check if the producer has finished and the queue is empty
        if (messageQueue.empty()) {
            break;
        }

        // 배열 초기화
        memset(msg, 0, sizeof(msg));
        name_msg[0] = '\0';

	// Consume the message
	std::string message = messageQueue.front();
	messageQueue.pop();

	// 영상으로부터 메시지를 입력받음
	strncpy(msg, message.c_str(), sizeof(message) - 1);
	msg[sizeof(message) - 1] = '\0';  // 문자열의 끝을 나타내는 null 문자 추가
	// 입력된 메시지가 "quit"인 경우, 소켓을 닫고 함수 종료
	if(!strncmp(msg, "quit\n", 5)) {
	    client_socket = -1;
            return;
	}
	// 입력된 메시지가 "["로 시작하지 않는 경우, 기본 ID인 "[ALLMSG]"를 추가
        else if(msg[0] != '[')
        {
            strcat(name_msg, "[ALLMSG]");
            strcat(name_msg, msg);
        }
        // 입력된 메시지가 "["로 시작하는 경우, 그대로 사용
        else
	    strcpy(name_msg, msg);

        // 소켓을 통해 메시지를 서버에 전송
        if(write(client_socket, name_msg, strlen(name_msg)) <= 0)
        {
            client_socket = -1;
            return;
        }

        // Unlock the mutex before processing the message
        lock.unlock();

    }
}

void ClientSocket::RecvMsg() {
    //int i;
    //char *pToken;
    //char *pArray[ARR_CNT] = {0};

    char name_msg[NAME_SIZE + BUF_SIZE + 1];
    int str_len;
    while(1) {
        memset(name_msg, 0x0, sizeof(name_msg));
        str_len = read(client_socket, name_msg, NAME_SIZE + BUF_SIZE);
        if(str_len <= 0)
        {
            client_socket = -1;
            return;
        }
        name_msg[str_len] = 0;
        fputs(name_msg, stdout);
    }
}

/*
void ClientSocket::run() {
    pthread_t snd_thread, rcv_thread;
    void * thread_return;

    pthread_create(&rcv_thread, NULL, RecvMsgThread, (void *)&client_socket);
    pthread_create(&snd_thread, NULL, SendMsgThread, (void *)&client_socket);

    pthread_join(snd_thread, &thread_return);
    pthread_join(rcv_thread, &thread_return);
}
*/

void* ClientSocket::SendMsgThread(void* arg) {
    ClientSocket* clientSocket = reinterpret_cast<ClientSocket*>(arg);
    clientSocket->SendMsg();
    return nullptr;
}

void* ClientSocket::RecvMsgThread(void* arg) {
    ClientSocket* clientSocket = reinterpret_cast<ClientSocket*>(arg);
    clientSocket->RecvMsg();
    return nullptr;
}
