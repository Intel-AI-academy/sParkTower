#include "infodatabase.h"

InfoDatabase::InfoDatabase(QWidget *parent) :
    QWidget (parent)
{
    qsqldatabase = QSqlDatabase::addDatabase("QSQLITE");
    qsqldatabase.setDatabaseName("parkingdata.db");

    if(qsqldatabase.open())
        qDebug() << "success DB connection\n";
    else
        qDebug() << "fail DB creation\n";

    QString str_query = "CREATE TABLE parking_log_tb ("
            "car_slot_num VARCHAR(10),"
            "car_num VARCHAR(10),"
            "phone_num VARCHAR(10),"
            "input_time VARCHAR(10),"
            "output_time VARCHAR(10),"
            "charge_check VARCHAR(10))";
    QSqlQuery sql_query;
    if(!sql_query.exec(str_query))
        ;//qDebug() << "error" << sql_query.lastError().text();
    else
        qDebug() << "create table \n";
}

void InfoDatabase::recv_data(QString recv_data){
    QStringList qlist = recv_data.split('@');
    QString car_slot_num = qlist[0];
    QString car_num = qlist[1];
    QString phone_num = qlist[2];
    QString input_time = qlist[3];
    QString output_time = qlist[4];
    QString charge_check = qlist[5];
    QString str_query = "INSERT INTO parking_log_tb(car_slot_num,car_num,phone_num,input_time,output_time,charge_check) values('" + car_slot_num + "', '" + car_num + "', '" + phone_num + "', '" + input_time + "', '" + output_time + "', '" + charge_check + "')";

    QSqlQuery sql_query;
    if(!sql_query.exec(str_query))
    {
        ;
    }
    else
    {
        qDebug() << "insert query ok";
    }
}

void InfoDatabase::send_data()
{/*
    QString recv_data = "";
    QString str_query = "select * from parking_log_tb where charge_check == 'x'";
    QSqlQuery sql_query;
    if(!sql_query.exec(str_query))
        ;
    else
    {
        while (sql_query.next())
        {
            recv_data = sql_query.value("car_slot_num").toString();
            recv_data += '@';
            recv_data += sql_query.value("car_num").toString();
            recv_data += '@';
            recv_data += sql_query.value("phone_num").toString();
            recv_data += '@';
            recv_data += sql_query.value("input_time").toString();
            recv_data += '@';
            recv_data += sql_query.value("output_time").toString();
            recv_data += '@';
            recv_data += sql_query.value("charge_check").toString();
        }
    }*/
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
