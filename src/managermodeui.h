#ifndef MANAGERMODEUI_H
#define MANAGERMODEUI_H

#include <QWidget>
#include <QDebug>
#include <QPixmap>
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
    void send_fee_text(QString, QString);

private:
    Ui::ManagerModeUI *ui;
    ChargeManagerDialog *p_chargemanagerdialog;
    GarageManagerDialog *p_garagemanagerdialog;
    InfoDatabase *p_infodatabase;
    QPixmap yellow, blue;

public slots:
    void search_slot();

private slots:
    void push_back_button();
    void show_payment_manager_view();
    void show_garage_view();
    void show_signal(QString, QString);



};

#endif // MANAGERMODEUI_H
