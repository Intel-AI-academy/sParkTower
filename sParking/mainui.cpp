#include "mainui.h"
#include "ui_mainui.h"

MainUI::MainUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainUI)
{
    ui->setupUi(this);
    p_usermode = new UserModeUI;
    p_managermode = new ManagerModeUI;
    p_managerpasswordui = new ManagerPasswordUI;
    p_registerdialog = new RegisterDialog;
    p_paymentui = new PaymentUI;
    p_SocketClient = new SocketClient;
    p_infodatabase = new InfoDatabase;

    ui->stackedWidget->insertWidget(1, p_usermode);
    ui->stackedWidget->insertWidget(2, p_managermode);
    ui->stackedWidget->insertWidget(3, p_paymentui);


    connect(ui->manager_mode, SIGNAL(clicked()), this, SLOT(show_manager_pw_view()));
    connect(p_usermode, SIGNAL(move_to_registrationcar()), this, SLOT(show_register_dialog_view()));

    connect(ui->user_mode, SIGNAL(clicked()), this, SLOT(move_user_view()));
    connect(p_usermode, SIGNAL(push_back()), this, SLOT(move_back()));
    connect(p_managermode, SIGNAL(push_back()), this, SLOT(move_back()));
    connect(p_managerpasswordui, SIGNAL(manager_view()), this, SLOT(move_manager_view()));
    connect(p_usermode, SIGNAL(move_to_payment()), this, SLOT(move_payment_view()));
    connect(p_paymentui, SIGNAL(push_back()), this, SLOT(move_user_view()));

    connect(p_usermode, SIGNAL(send_data_to_db(QString)), this, SLOT(recv_data_from_usermode(QString)));

    connect(p_registerdialog, SIGNAL(register_car()), p_usermode, SLOT(register_car()));

    connectToServerSlot(bCheck);
}

void MainUI::connectToServerSlot(bool bCheck)
{
    p_SocketClient->slotConnectToServer(bCheck);
    if(!bCheck)
    {
        qDebug() << "no connect";
    }
    else
    {
        qDebug() << "server connect";
    }

}

void MainUI::move_user_view(){
    ui->stackedWidget->setCurrentIndex(1);
}
void MainUI::move_back(){
    ui->stackedWidget->setCurrentIndex(0);
}
void MainUI::move_payment_view(){
    ui->stackedWidget->setCurrentIndex(3);
}
void MainUI::move_manager_view(){
    ui->stackedWidget->setCurrentIndex(2);
}
void MainUI::show_manager_pw_view(){
    p_managerpasswordui->show();
}
void MainUI::show_register_dialog_view(){
    p_registerdialog->show();
}

void MainUI::recv_data_from_usermode(QString recv_data)
{
    p_infodatabase->recv_data(recv_data);
}




MainUI::~MainUI()
{
    delete ui;
}

