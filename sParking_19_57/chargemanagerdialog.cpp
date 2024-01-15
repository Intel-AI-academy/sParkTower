#include "chargemanagerdialog.h"
#include "ui_chargemanagerdialog.h"

ChargeManagerDialog::ChargeManagerDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChargeManagerDialog)
{
    ui->setupUi(this);
    connect(ui->back_button, SIGNAL(clicked()), this, SLOT(close_dialog()));

}

void ChargeManagerDialog::close_dialog()
{
    close();
}

ChargeManagerDialog::~ChargeManagerDialog()
{
    delete ui;
}
