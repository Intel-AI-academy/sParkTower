#include "managermodeui.h"
#include "ui_managermodeui.h"

ManagerModeUI::ManagerModeUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManagerModeUI)
{
    ui->setupUi(this);

    p_chargemanagerdialog = new ChargeManagerDialog;
    p_garagemanagerdialog = new GarageManagerDialog;
    p_infodatabase = new InfoDatabase;

    connect(ui->back_button, SIGNAL(clicked()), this, SLOT(push_back_button()));
    connect(ui->charge_manager_button, SIGNAL(clicked()), this, SLOT(show_payment_manager_view()));
    connect(ui->garage_manager_button, SIGNAL(clicked()), this, SLOT(show_garage_view()));

    connect(p_infodatabase, SIGNAL(RecvDataSig_garage()), this, SLOT(soket_data));
    connect(p_infodatabase, SIGNAL(RecvDataSig_pay()), this, SLOT(soket_data));

}

void ManagerModeUI::push_back_button()
{
    emit push_back();
}

void ManagerModeUI::show_payment_manager_view()
{
    p_chargemanagerdialog->show();
}

void ManagerModeUI::show_garage_view()
{
    p_garagemanagerdialog->show();
}


void ManagerModeUI::soket_data(QString recvData)
{
    QStringList qlist = recvData.split("@");
    QString in_tiem = qlist[2];
    QString out_time = qlist[3];
    QString grage_num = qlist[4];

    QString strQuery = "insert into sParking_tb(in_tiem, out_time, grage_num) values('" + in_tiem + "' , '" + out_time + "' , '" + grage_num + "')";
    QSqlQuery sqlQuery;
    if(!sqlQuery.exec(strQuery))
    {
        ;
    }
    else
    {
        qDebug()<<"insert query ok";
    }
}


ManagerModeUI::~ManagerModeUI()
{
    delete ui;
}
