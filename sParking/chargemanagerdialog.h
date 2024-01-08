#ifndef CHARGEMANAGERDIALOG_H
#define CHARGEMANAGERDIALOG_H

#include <QWidget>

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
    void close_dialog();
};

#endif // CHARGEMANAGERDIALOG_H
