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
        ;
    else
        qDebug() << "create table \n";

    for(i=0;i<2;i++)
        parking_slot[i]=0;
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
        emit save_db(car_slot_num);
    }
}

void InfoDatabase::update_database()
{
    QDateTime time = QDateTime::currentDateTime();
    QString time_format = "HH:mm:ss";
    QString str_time = time.toString(time_format);

    int intime = 0;
    int outtime = 0;
    int count = 0;
    QString slot = "";

    QString temp;
    QStringList qlist;
    QStringList minute;
    QStringList current_time_temp;
    QString str_query = "SELECT * FROM parking_log_tb WHERE charge_check = 'x' AND output_time = 'null'";
    QSqlQuery sql_query;
    if(!sql_query.exec(str_query))
        ;
    else
    {
        while (sql_query.next())
        {
            //update code
            temp = sql_query.value("input_time").toString();
            qlist = temp.split(":");
            //minute = qlist[1].split(":");

            current_time_temp = str_time.split(":");

            intime = current_time_temp[0].toUInt() * 3600 + current_time_temp[1].toUInt() * 60 + current_time_temp[2].toUInt();
            outtime = qlist[0].toUInt() * 3600 + qlist[1].toUInt() * 60 + qlist[2].toUInt();
            if((intime - outtime) >= 10 && sql_query.value("car_slot_num").toInt() > 0 && sql_query.value("car_slot_num").toInt() <= 2)
            {
                for(i=0;i<2;i++)
                {
                    if(parking_slot[i]==1)
                    {
                        count++;
                    }
                }
                if(count < 2)
                {
                    for(i=0;i<2;i++)
                    {
                        if(parking_slot[i]==0)
                        {
                            qDebug() << "update";
                            QString update_query = QString("UPDATE parking_log_tb SET output_time = '%1' WHERE output_time = 'null' AND car_slot_num = '1' OR car_slot_num = '2'")
                                                           .arg(str_time);
                            QSqlQuery update_sql_query;
                            update_sql_query.exec(update_query);

                            parking_slot[i]=1;
                            slot = QString::number(i+3);
                            temp = QString::number(i+3);
                            temp += "@";
                            temp += sql_query.value("car_num").toString();
                            temp += "@";
                            temp += sql_query.value("phone_num").toString();
                            temp += "@";
                            temp += str_time;
                            temp += "@";
                            temp += "null";
                            temp += "@";
                            temp += sql_query.value("charge_check").toString();
                            recv_data(temp);
                            // add signal for send msg to stm
                            move_to_parking_slot(sql_query.value("car_slot_num").toString(), slot);
                            emit check_charging_slot(slot.toInt() - 3);
                            break;
                        }
                    }
                }
                else
                {
                    update_fail_msg.setText("Not enough parking slot!!");
                    update_fail_msg.exec();
                }
            }
        }
    }

}

void InfoDatabase::move_to_parking_slot(QString from, QString to)
{
    QString str_recv_id = "tower";
    QString str_send_data = from + "@" + to;

    //qDebug()<<"send_data_slot : "<<str_send_data;
    if(!str_send_data.isEmpty())
    {
        str_send_data = "["+str_recv_id+"]" + "Park@on@" + str_send_data;
    }
    emit socket_send_data(str_send_data);
}

void InfoDatabase::update_for_pay(QString num_time)
{
    QStringList qlist = num_time.split("@");
    QString str_query = QString("SELECT * FROM parking_log_tb");
    QSqlQuery sql_query;
    if(!sql_query.exec(str_query))
        ;
    else
    {
        while (sql_query.next())
        {
            if(sql_query.value("car_num").toString() == qlist[0] && sql_query.value("phone_num").toString() == qlist[1])
            {
                if(sql_query.value("output_time").toString() == "null")
                {
                    QString update_query = QString("UPDATE parking_log_tb SET output_time = '%1' WHERE car_num = '%2' AND phone_num = '%3'")
                                                   .arg(qlist[2])
                                                   .arg(qlist[0])
                                                   .arg(qlist[1]);
                    QSqlQuery update_sql_query;
                    update_sql_query.exec(update_query);

                    if(sql_query.value("car_slot_num").toInt() > 2)
                        parking_slot[sql_query.value("car_slot_num").toInt() - 3] = 0;
                    out_parkinig(sql_query.value("car_slot_num").toString());

                }

                QString update_query1 = QString("UPDATE parking_log_tb SET charge_check = 'o' WHERE car_num = '%1' AND phone_num = '%2'")
                        .arg(qlist[0])
                        .arg(qlist[1]);
                QSqlQuery update_sql_query1;
                update_sql_query1.exec(update_query1);
            }
        }
    }
}

void InfoDatabase::out_parkinig(QString parking_slot)
{
    QString str_recv_id = "tower";
    QString str_send_data = "out@" + parking_slot;

    qDebug()<<"send_data_slot : "<<str_send_data;
    if(!str_send_data.isEmpty())
    {
        str_send_data = "["+str_recv_id+"]" + "Park@" + str_send_data;
    }
    emit socket_send_data(str_send_data);
}

QString InfoDatabase::send_numbers(QString car_num, QString phone_num)
{
    QString numbers;
    QString str_query = QString("SELECT * FROM parking_log_tb");
    QSqlQuery sql_query;
    if(!sql_query.exec(str_query))
        ;
    else
    {
        while (sql_query.next())
        {
            if(sql_query.value("car_num") == car_num && sql_query.value("phone_num") == phone_num)
            {
                numbers = sql_query.value("car_num").toString();
                numbers += "@";
                numbers += sql_query.value("phone_num").toString();
                numbers += "@";
                numbers += sql_query.value("input_time").toString();
            }
        }
    }
    return numbers;
}

InfoDatabase::~InfoDatabase()
{

}
