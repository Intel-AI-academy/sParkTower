#ifndef MAINUI_H
#define MAINUI_H

#include <QWidget>
#include <QStackedWidget>

#include "usermodeui.h"
#include "managermodeui.h"
#include "managerpasswordui.h"
#include "registerdialog.h"
#include "paymentui.h"
#include "socketclient.h"
#include "infodatabase.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainUI; }
QT_END_NAMESPACE

class MainUI : public QWidget
{
    Q_OBJECT

public:
    MainUI(QWidget *parent = nullptr);
    ~MainUI();

private:
    Ui::MainUI *ui;
    UserModeUI *p_usermode;
    ManagerModeUI *p_managermode;
    ManagerPasswordUI *p_managerpasswordui;
    RegisterDialog *p_registerdialog;
    PaymentUI *p_paymentui;
    SocketClient *p_SocketClient;
    InfoDatabase *p_infodatabase;

    bool bCheck = true;

signals:
    void connected(bool=false);

private slots:
    void move_user_view();
    void move_back();
    void move_payment_view();
    void move_manager_view();
    void show_manager_pw_view();
    void show_register_dialog_view();
    void connectToServerSlot(bool);

    void send_in_time(QString);

};
#endif // MAINUI_H
