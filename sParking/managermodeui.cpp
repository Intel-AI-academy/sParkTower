#include "managermodeui.h"
#include "ui_managermodeui.h"

ManagerModeUI::ManagerModeUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManagerModeUI)
{
    ui->setupUi(this);
    p_chargemanagerdialog = new ChargeManagerDialog;
    p_garagemanagerdialog = new GarageManagerDialog;

    connect(ui->back_button, SIGNAL(clicked()), this, SLOT(push_back_button()));

    connect(ui->charge_manager_button, SIGNAL(clicked()), this, SLOT(show_payment_manager_view()));
    connect(ui->garage_manager_button, SIGNAL(clicked()), this, SLOT(show_garage_view()));
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

ManagerModeUI::~ManagerModeUI()
{
    delete ui;
}
