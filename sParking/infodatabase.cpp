#include "infodatabase.h"

InfoDatabase::InfoDatabase(QWidget *parent) :
    QWidget (parent)
{

    //p_usermodeui = new UserModeUI;
    //p_usermode = new UserModeUI;


//    connect(p_SocketClient, SIGNAL(sigSocketRecv(QString)), this, SLOT(RecvUpdateSlot(QString)));
    //connect(this, SIGNAL(x_sig(QString)), p_ManagerModeUI, SLOT(soket_data(QString)));
    //connect(this, SIGNAL(time_sig(QString)), this, SLOT(RecvUpdateSlot(QString)));
    //connect(p_usermode, SIGNAL(in_time(QString)), this, SLOT(in_out_time(QString)));
}

void InfoDatabase::in_out_time(QString recv_time){
    qDebug() << recv_time;
}

void InfoDatabase::user_data(QString user_data)
{

    QString data;

    data = user_data;

    qDebug() <<"recv data : " << data;

    if(data !=-1){
        //emit time_sig(user_data);
    }

}

void InfoDatabase::RecvUpdateSlot(QString strRecvData) //show, sig
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
        emit RecvDataSig_garage(strRecvData);
    }
    else if(qList[2].indexOf("Y")!=-1)
    {
        emit RecvDataSig_pay(strRecvData);
    }
}

InfoDatabase::~InfoDatabase()
{

}
