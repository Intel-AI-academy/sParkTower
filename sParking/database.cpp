#include "database.h"

DataBase::DataBase()
{
    qSqlDatabase = QSqlDatabase::addDatabase("QSQLITE");
    qSqlDatabase.setDatabaseName("sParking.db");

    if(qSqlDatabase.open())
        qDebug() << "success DB connection\n";
    else
        qDebug() << "fail DB connection\n";

    QString strQuery = "CREATE TABLE sParking_tb ("
            "car_num VARCHAR(10),"
            "phone_num VARCHAR(10),"
            "in_tiem VARCHAR(10),"
            "out_time VARCHAR(10),"
            "grage_num VARCHAR(10))";

    QSqlQuery sqlQuery;
    if(!sqlQuery.exec(strQuery))
        ;
    else
        qDebug() << "create table\n";

}

void DataBase::user_data(QString user_data){

    QString data;

    data = user_data;

    qDebug() << data;
}

void DataBase::soket_data(QString recvData)
{
    QStringList qlist = recvData.split("@");
    QString in_tiem = qlist[2];
    QString out_time = qlist[3];
    QString grage_num = qlist[4];

    QString strQuery = "insert into sParking_tb(in_tiem, out_time, grage_num) values('" + in_tiem + "' , '" + out_time + "' , '" + grage_num + "')";
    QSqlQuery sqlQuery;
    if(!sqlQuery.exec(strQuery))
    {
        ;
    }
    else
    {
        qDebug()<<"insert query ok";
    }
}
