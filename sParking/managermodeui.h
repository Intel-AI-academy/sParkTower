#ifndef MANAGERMODEUI_H
#define MANAGERMODEUI_H

#include <QWidget>
#include "chargemanagerdialog.h"
#include "garagemanagerdialog.h"
#include "infodatabase.h"

namespace Ui {
class ManagerModeUI;
}

class ManagerModeUI : public QWidget
{
    Q_OBJECT

public:
    explicit ManagerModeUI(QWidget *parent = nullptr);
    ~ManagerModeUI();

signals:
    void push_back();

private:
    Ui::ManagerModeUI *ui;
    ChargeManagerDialog *p_chargemanagerdialog;
    GarageManagerDialog *p_garagemanagerdialog;
    InfoDatabase *p_infodatabase;



private slots:
    void push_back_button();
    void show_payment_manager_view();
    void show_garage_view();
    void soket_data(QString);

};

#endif // MANAGERMODEUI_H
