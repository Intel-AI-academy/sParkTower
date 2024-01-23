#ifndef CHARGEMANAGERDIALOG_H
#define CHARGEMANAGERDIALOG_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class ChargeManagerDialog;
}

class ChargeManagerDialog : public QWidget
{
    Q_OBJECT

public:
    explicit ChargeManagerDialog(QWidget *parent = nullptr);
    ~ChargeManagerDialog();

private:
    Ui::ChargeManagerDialog *ui;

private slots:
    void send_data_fee_slot();
    void close_dialog();

signals:
    void send_fee(QString, QString);
};

#endif // CHARGEMANAGERDIALOG_H
