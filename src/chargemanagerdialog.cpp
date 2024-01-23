#include "chargemanagerdialog.h"
#include "ui_chargemanagerdialog.h"

ChargeManagerDialog::ChargeManagerDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChargeManagerDialog)
{
    ui->setupUi(this);
    connect(ui->back_button, SIGNAL(clicked()), this, SLOT(close_dialog()));
    connect(ui->change_charging_fee_button, SIGNAL(clicked()), this, SLOT(send_data_fee_slot()));
    connect(ui->change_charging_fee_button_2, SIGNAL(clicked()), this, SLOT(send_data_fee_slot()));

    QString initial_charging = "1000";
    QString initial_parking = "1000";
    ui->charging_fee_status_text->setText(initial_charging);
    ui->charging_fee_status_text_2->setText(initial_parking);

}

void ChargeManagerDialog::close_dialog()
{
    close();
}

void ChargeManagerDialog::send_data_fee_slot()
{

    QString parking_fee = ui->change_charging_fee_text->text();
    QString charging_fee = ui->change_charging_fee_text_2->text();

    emit send_fee(parking_fee, charging_fee);

    if(parking_fee != "")
        ui->charging_fee_status_text->setText(parking_fee);

    if(charging_fee != "")
        ui->charging_fee_status_text_2->setText(charging_fee);

    ui->change_charging_fee_text->clear();
    ui->change_charging_fee_text_2->clear();
}

ChargeManagerDialog::~ChargeManagerDialog()
{
    delete ui;
}
