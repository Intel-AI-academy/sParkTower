#include "db.h"

DB::DB(QObject *parent) : QObject(parent)
{
    p_SocketClient = new SocketClient;
    //p_ManagerModeUI = new ManagerModeUI;


    connect(p_SocketClient, SIGNAL(sigSocketRecv(QString)), this, SLOT(RecvUpdateSlot(QString)));
}

void DB::user_data(QString user_data)
{

    QString data;

    data = user_data;

    qDebug() <<"recv data : " << data;

    if(data !=-1){
        //emit time_sig(user_data);
    }

}




void DB::RecvUpdateSlot(QString strRecvData) //show, sig
{
    QTime time = QTime::currentTime();
    QString strTime = time.toString();

    strRecvData.chop(1);

    strTime = strTime  + " " + strRecvData;
    //ui->pTERecvData->append(strTime);
    //ui->pTERecvData->moveCursor(QTextCursor::End);
    strRecvData.replace("[","@");
    strRecvData.replace("]","@");
    QStringList qList = strRecvData.split("@");

    if(qList[2].indexOf("X")!=-1)
    {
        emit x_sig(strRecvData);
    }
    else if(qList[2].indexOf("Y")!=-1)
    {
        emit y_sig(strRecvData);
    }
}
