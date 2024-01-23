#include "socketclient.h"
#define Kor(str)  QString::fromLocal8Bit(str)

SocketClient::SocketClient(QWidget *parent, Qt::WindowFlags flags)
	: QWidget(parent, flags)
{
//    bool ok;
    p_qtcp_socket = new QTcpSocket();

    connect(p_qtcp_socket, SIGNAL(connected()), this, SLOT(slotConnectServer()));
    connect(p_qtcp_socket, SIGNAL(disconnected()), this, SLOT(slotClosedByServer()));
    connect(p_qtcp_socket, SIGNAL(readyRead()), this, SLOT(slotSocketReadData()));
    connect(p_qtcp_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slotSocketError()));
//    slotConnectToServer(ok);
}


void SocketClient::slotConnectToServer(bool& ok){
    //서버 연결 요청
    QString strHostIp;
//	tcpSocket.connectToHost(QHostAddress::LocalHost, 5000);
    strHostIp = SERVERIP, ok = true;
    if(ok)
    {
        if(strHostIp.isEmpty())
            p_qtcp_socket->connectToHost(SERVERIP, SERVERPOT);
        else
            p_qtcp_socket->connectToHost(strHostIp, SERVERPOT);
    }
}
void SocketClient::slotConnectServer()
{
    QString Str = "["+LOGID+":"+LOGPW+"]";
    QByteArray byteStr = Str.toLocal8Bit();
    p_qtcp_socket->write(byteStr);
}

void SocketClient::slotClosedByServer()
{
    p_qtcp_socket->close();
}

void SocketClient::slotSocketReadData(){
    QString strRecvData;
    QByteArray qByteArray;

    if (p_qtcp_socket->bytesAvailable() > BLOCK_SIZE)
		return;
    qByteArray = p_qtcp_socket->read(BLOCK_SIZE);
    strRecvData = QString::fromUtf8(qByteArray);
    emit sigSocketRecv(strRecvData);
}

void SocketClient::slotSocketError()
{
    QString Str = p_qtcp_socket->errorString();
}


void SocketClient::slotSocketSendData(QString strSendData)
{	
    if(p_qtcp_socket->isWritable())
    {
        if(!strSendData.isEmpty()) {
            strSendData = strSendData+"\n";
            QByteArray bCmd = strSendData.toLocal8Bit();
            p_qtcp_socket->write(bCmd);
        }
    }
    else
    {
       ;
    }
}

QTcpSocket * SocketClient::get_pqtcp_socket()
{
    return p_qtcp_socket;
}

SocketClient::~SocketClient()
{
    p_qtcp_socket->close();
}
