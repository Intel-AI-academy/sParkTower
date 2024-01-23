#ifndef USERMODEUI_H
#define USERMODEUI_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>
#include <QDateTime>
#include <QMessageBox>
#include "infodatabase.h"

namespace Ui {
class UserModeUI;
}

class UserModeUI : public QWidget
{
    Q_OBJECT

public:
    explicit UserModeUI(QWidget *parent = nullptr);
    ~UserModeUI();
    QString recv_data;

    QPushButton* get_main_ui_button();

signals:
    void push_back();
    void move_to_payment(QString, QString);
    void move_to_registrationcar();
    void send_data_to_db(QString);
    void compare_with_db();
    void socket_send_data(QString);

private:
    Ui::UserModeUI *ui;
    QString output_text;
    QLineEdit *carnum_text;
    QLineEdit *phonenum_text;
    QPushButton *button;
    int check_num;
    QDateTime temp_time;
    int charging_slot[2];
    int parking_slot[2];
    QString send_data;
    QMessageBox cannot_parking_msg;
    int i;

private slots:
    void push_back_button();
    void input_key();
    void update_charging_slot(int);


public slots:
    void register_car();
    void compare();
    void send_data_slot(QString);
};

#endif // USERMODEUI_H
