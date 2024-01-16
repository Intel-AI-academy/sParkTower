#ifndef INFODATABASE_H
#define INFODATABASE_H

#include <QWidget>
#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSql>
#include <QDebug>
#include <QDate>
#include <QTime>

class InfoDatabase : public QWidget
{
    Q_OBJECT

public:
    explicit InfoDatabase(QWidget *parent = nullptr);

    ~InfoDatabase();

    void send_data();

    void soket_data(QString);

    void RecvUpdateSlot(QString);

    void recv_data(QString);

private:
    //UserModeUI *p_usermode;
    QSqlDatabase qsqldatabase;

signals:
    void RecvDataSig_garage(QString);
    void RecvDataSig_pay(QString);
    void send_data_from_db(QString);

    //void x_sig(QString);
    //void y_sig(QString);

};

#endif // INFODATABASE_H
