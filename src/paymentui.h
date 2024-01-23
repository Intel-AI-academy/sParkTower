#ifndef PAYMENTUI_H
#define PAYMENTUI_H

#include <QWidget>
#include <QDateTime>
#include <QString>
#include <QDebug>
#include <iostream>

#include "paymentdialog.h"

namespace Ui {
class PaymentUI;
}

class PaymentUI : public QWidget
{
    Q_OBJECT

public:
    explicit PaymentUI(QWidget *parent = nullptr);
    ~PaymentUI();
    void show_time_text();
    QString car_num;
    QString phone_num;
    QString input_time;
    QString parking_fee_data;
    QString charging_fee_data;

signals:
    void push_back();
    void update_payment(QString);
    void parking_charging(QString);
private:
    Ui::PaymentUI *ui;
    PaymentDialog *p_paymentdialog;


private slots:
    void push_back_button();
    void show_pay_dialog_view();
    void send_payment_data();
    void set_fee(QString, QString);
};

#endif // PAYMENT_H
