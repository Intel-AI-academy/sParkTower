#ifndef PAYMENTDIALOG_H
#define PAYMENTDIALOG_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class PaymentDialog;
}

class PaymentDialog : public QWidget
{
    Q_OBJECT

public:
    explicit PaymentDialog(QWidget *parent = nullptr);
    ~PaymentDialog();

private:
    Ui::PaymentDialog *ui;
    QMessageBox payment_msg;
private slots:
    void close_dialog();
    void show_payment_msg();
};

#endif // CHECKPAYMENT_H
