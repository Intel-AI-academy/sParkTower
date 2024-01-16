#ifndef DATABASE_H
#define DATABASE_H


#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDateTime>
#include <QDebug>
#include "usermodeui.h"
class DataBase
{
public:
    DataBase();

    ~DataBase();

    void soket_data(QString);
    void user_data(QString);

private:
    QSqlDatabase qSqlDatabase;
    UserModeUI *p_UserModeUI;

};

#endif // DATABASE_H
