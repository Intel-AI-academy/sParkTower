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
#include <QDateTime>
#include <QTimer>
#include <QMessageBox>

class InfoDatabase : public QWidget
{
    Q_OBJECT

public:
    explicit InfoDatabase(QWidget *parent = nullptr);

    ~InfoDatabase();

    void soket_data(QString);

    void update_database();

    void recv_data(QString);

    QString send_numbers(QString, QString);

private:
    QSqlDatabase qsqldatabase;
    QMessageBox update_fail_msg;
    int i;
    int parking_slot[];
    void move_to_parking_slot(QString, QString);
    void out_parkinig(QString);

private slots:
    void update_for_pay(QString);

signals:
    void send_data_from_db(QString);
    void save_db(QString);
    void socket_send_data(QString);
    void check_charging_slot(int);


};

#endif // INFODATABASE_H
