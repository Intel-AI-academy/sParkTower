#ifndef USERMODEUI_H
#define USERMODEUI_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
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

signals:
    void push_back();
    void move_to_payment();
    void move_to_registrationcar();
    void in_time(QString);

private:
    Ui::UserModeUI *ui;
    QString output_text;
    QLineEdit *carnum_text;
    QLineEdit *phonenum_text;
    QPushButton *button;
    int check_num;
    QDateTime input_time;

private slots:
    void push_back_button();

    void input_key();
};

#endif // USERMODEUI_H
