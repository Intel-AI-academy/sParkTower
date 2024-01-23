#ifndef UPDATEDATABASE_H
#define UPDATEDATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDateTime>
#include <QDebug>
#include "usermodeui.h"

class UpdateDatabase
{
public:
    UpdateDatabase();

    ~UpdateDatabase();

    void user_data(QString);

    void soket_data(QString);

private:

};



#endif // UPDATEDATABASE_H
