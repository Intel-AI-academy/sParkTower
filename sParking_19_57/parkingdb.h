#ifndef PARKINGDB_H
#define PARKINGDB_H

#include <QObject>
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QDate>
#include <QTime>
#include "socketclient.h"
#include "managermodeui.h"

class ParkingDB
{
    Q_OBJECT

public:
    explicit ParkingDB(QWidget *parent = nullptr);

    ~ParkingDB();

    void user_data(QString);

    void soket_data(QString);

    void RecvUpdateSlot(QString);

private:
    SocketClient *p_SocketClient;
    ManagerModeUI *p_ManagerModeUI;

signals:
    //void RecvDataSig_garage(QString);
    //void RecvDataSig_pay(QString);

    void x_sig(QString);
    void y_sig(QString);
    void time_sig(QString);
};

#endif // PARKINGDB_H
