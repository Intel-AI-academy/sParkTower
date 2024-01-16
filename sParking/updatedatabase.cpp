#include "updatedatabase.h"

UpdateDatabase::UpdateDatabase()
{

}
void UpdateDatabase::user_data(QString user_data)
{

    QString data;

    data = user_data;

    qDebug() << data;
}

void UpdateDatabase::soket_data(QString recvData)
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
