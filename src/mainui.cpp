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
    p_socketclient = new SocketClient;
    p_infodatabase = new InfoDatabase;

    one_minute = new QTimer();

    ui->stackedWidget->insertWidget(1, p_usermode);
    ui->stackedWidget->insertWidget(2, p_managermode);
    ui->stackedWidget->insertWidget(3, p_paymentui);

    connect(ui->manager_mode, SIGNAL(clicked()), this, SLOT(show_manager_pw_view()));
    connect(p_usermode, SIGNAL(move_to_registrationcar()), this, SLOT(show_register_dialog_view()));
    connect(ui->user_mode, SIGNAL(clicked()), this, SLOT(move_user_view()));
    connect(p_usermode, SIGNAL(push_back()), this, SLOT(move_back()));
    connect(p_managermode, SIGNAL(push_back()), this, SLOT(move_back()));
    connect(p_managerpasswordui, SIGNAL(manager_view()), this, SLOT(move_manager_view()));
    connect(p_usermode, SIGNAL(move_to_payment(QString, QString)), this, SLOT(move_payment_view(QString, QString)));
    connect(p_paymentui, SIGNAL(push_back()), p_usermode, SLOT(push_back_button()));

    connect(p_registerdialog, SIGNAL(register_car()), p_usermode, SLOT(register_car()));

    connect(p_usermode, SIGNAL(send_data_to_db(QString)), this, SLOT(recv_data_from_usermode(QString)));

    connect(p_usermode, SIGNAL(socket_send_data(QString)), p_socketclient, SLOT(slotSocketSendData(QString)));
    connect(p_infodatabase, SIGNAL(socket_send_data(QString)), p_socketclient, SLOT(slotSocketSendData(QString)));

    connect_to_server_slot(b_check);

    connect(p_infodatabase, SIGNAL(check_charging_slot(int)), p_usermode, SLOT(update_charging_slot(int)));
    connect(p_paymentui, SIGNAL(update_payment(QString)), p_infodatabase, SLOT(update_for_pay(QString)));

    connect(p_managermode, SIGNAL(send_fee_text(QString, QString)), p_paymentui, SLOT(set_fee(QString, QString)));
    //wait
    connect(one_minute, &QTimer::timeout, p_infodatabase, &InfoDatabase::update_database);
    one_minute->start(60000);
}

void MainUI::connect_to_server_slot(bool b_check){
    p_socketclient->slotConnectToServer(b_check);
}
void MainUI::move_user_view(){
    ui->stackedWidget->setCurrentIndex(1);
}
void MainUI::move_back(){
    ui->stackedWidget->setCurrentIndex(0);
}
void MainUI::move_payment_view(QString car_num, QString phone_num){
    ui->stackedWidget->setCurrentIndex(3);
    QString temp;
    temp = p_infodatabase->send_numbers(car_num, phone_num);
    QStringList qlist = temp.split("@");
    p_paymentui->car_num = qlist[0];
    p_paymentui->phone_num = qlist[1];
    p_paymentui->input_time = qlist[2];
    p_paymentui->show_time_text();
}
void MainUI::move_manager_view(){
    ui->stackedWidget->setCurrentIndex(2);
    p_managermode->search_slot();
}
void MainUI::show_manager_pw_view(){
    p_managerpasswordui->show();
}
void MainUI::show_register_dialog_view(){
    p_registerdialog->show();
}
void MainUI::recv_data_from_usermode(QString recv_data){
    p_infodatabase->recv_data(recv_data);
}


MainUI::~MainUI()
{
    delete ui;
}

