#ifndef USERMODEUI_H
#define USERMODEUI_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>
#include <QDateTime>
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

signals:
    void push_back();
    void move_to_payment();
    void move_to_registrationcar();
    void send_data_to_db(QString);
    void compare_with_db();

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
    int i;
    QString send_data;
private slots:
    void push_back_button();

    void input_key();

public slots:
    void register_car();
    void compare();
};

#endif // USERMODEUI_H
