#ifndef DB_H
#define DB_H

#include <QObject>
#include <QWidget>
#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QDate>
#include <QTime>
#include "socketclient.h"
#include "managermodeui.h"

class DB : public QObject
{
    Q_OBJECT
public:
    explicit DB(QObject *parent = nullptr);

    void user_data(QString);

    void soket_data(QString);

    void RecvUpdateSlot(QString);

private:
    SocketClient *p_SocketClient;
    //ManagerModeUI *p_ManagerModeUI;

signals:
    //void RecvDataSig_garage(QString);
    //void RecvDataSig_pay(QString);

    void x_sig(QString);
    void y_sig(QString);
    void time_sig(QString);

};

#endif // DB_H
