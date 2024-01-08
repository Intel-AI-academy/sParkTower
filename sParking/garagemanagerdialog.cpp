#include "garagemanagerdialog.h"
#include "ui_garagemanagerdialog.h"

GarageManagerDialog::GarageManagerDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GarageManagerDialog)
{
    ui->setupUi(this);
}

GarageManagerDialog::~GarageManagerDialog()
{
    delete ui;
}
