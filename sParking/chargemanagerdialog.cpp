#include "chargemanagerdialog.h"
#include "ui_chargemanagerdialog.h"

ChargeManagerDialog::ChargeManagerDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChargeManagerDialog)
{
    ui->setupUi(this);

}

ChargeManagerDialog::~ChargeManagerDialog()
{
    delete ui;
}
