#ifndef PAYMENTUI_H
#define PAYMENTUI_H

#include <QWidget>
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
signals:
    void push_back();
private:
    Ui::PaymentUI *ui;
    PaymentDialog *p_paymentdialog;
private slots:
    void push_back_button();
    void show_pay_dialog_view();
};

#endif // PAYMENT_H
