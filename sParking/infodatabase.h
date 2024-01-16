#ifndef INFODATABASE_H
#define INFODATABASE_H

#include <QWidget>
#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QDate>
#include <QTime>
#include <QDebug>

class InfoDatabase : public QWidget
{
    Q_OBJECT

public:
    explicit InfoDatabase(QWidget *parent = nullptr);

    ~InfoDatabase();

    void user_data(QString);

    void soket_data(QString);

    void RecvUpdateSlot(QString);

    void in_out_time(QString);

private:
    //UserModeUI *p_usermode;

signals:
    void RecvDataSig_garage(QString);
    void RecvDataSig_pay(QString);

    //void x_sig(QString);
    //void y_sig(QString);

};

#endif // INFODATABASE_H
